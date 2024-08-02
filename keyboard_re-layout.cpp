#include "keyboard_re-layout.h"
#include <iostream>


KeyboardRelayout::KeyboardRelayout(const std::string &key_path, const std::string &value_name)
        : key_path(key_path), value_name(value_name) {}

// Set the binary value
std::vector<uint8_t> KeyboardRelayout::update_binary_data(uint8_t operator_first, uint8_t operator_second)
{
    return {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x02, 0x00, 0x00, 0x00, operator_first, 0x00, operator_second, 0x00,
            0x02, 0x00, 0x00, 0x00, operator_second, 0x00, operator_first, 0x00,
            0x00, 0x00, 0x00, 0x00
    };
}


// Create a binary key or open that
HKEY KeyboardRelayout::create_or_open_registry_key()
{
    HKEY h_key;
    LONG result = RegCreateKeyEx(
            HKEY_LOCAL_MACHINE,
            key_path.c_str(),
            0,
            nullptr,
            REG_OPTION_NON_VOLATILE,
            KEY_WRITE,
            nullptr,
            &h_key,
            nullptr
    );

    if(result != ERROR_SUCCESS) {
        throw std::runtime_error("Failed to create or open registry key. Error code: " + std::to_string(result));
    }

    return h_key;
}


// Add a binary value in registry
bool KeyboardRelayout::set_registry_binary_value(HKEY h_key, const std::vector<uint8_t> &binary_data)
{
    DWORD dataSize = binary_data.size();
    LONG result = RegSetValueEx(
            h_key,
            value_name.c_str(),
            0,
            REG_BINARY,
            binary_data.data(),
            dataSize
    );

    if(result != ERROR_SUCCESS) {
        std::cerr << "Failed to set binary value. Error code: " << result << std::endl;
        return false;
    }

    std::cout << "Binary value successfully added." << std::endl;
    return true;
}


// Close the registry key
void KeyboardRelayout::close_registry_key(HKEY h_key)
{
    RegCloseKey(h_key);
}


// Delete the registry value
bool KeyboardRelayout::delete_registry_value(HKEY h_key)
{
    LONG result = RegDeleteValue(h_key, value_name.c_str());
    if(result != ERROR_SUCCESS) {
        std::cerr << "There is NOT EXIST a changed Keyboard Layout!" << std::endl;
        return false;
    }

    std::cout << "Registry value successfully DELETED." << std::endl;
    return true;
}