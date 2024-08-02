#ifndef KEYBOARD_RE_LAYOUT_H
#define KEYBOARD_RE_LAYOUT_H


#include <string>
#include <windows.h>
#include <cstdint>
#include <vector>


class KeyboardRelayout
{
public:
    KeyboardRelayout(const std::string &key_path, const std::string &value_name);

    std::vector<uint8_t> update_binary_data(uint8_t operator_first, uint8_t operator_second);

    bool set_registry_binary_value(HKEY h_key, const std::vector<uint8_t> &binary_data);

    bool delete_registry_value(HKEY h_key);

    HKEY create_or_open_registry_key();

    void close_registry_key(HKEY h_key);

private:
    std::string key_path;
    std::string value_name;
    const std::vector<uint8_t> binary_data;
    HKEY h_key{};
    uint8_t operator_first{};
    uint8_t operator_second{};
};


#endif // KEYBOARD_RE_LAYOUT_H
