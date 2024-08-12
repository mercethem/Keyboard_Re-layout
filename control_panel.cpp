#include <iostream>
#include <algorithm>
#include "keyboard_re-layout.h"
#include "keyboard_lookup_table.h"


void control_panel()
{
    const std::string key_path{KEYBOARD_SUB_STR};
    const std::string value_name{REGISTER_NAME};
    KeyboardRelayout keyboard_re_layout(key_path, value_name);

    while(true) {
        int choice;
        std::cout << "Choose an option:\n1. Create or Update Registry Key\n2. Delete Registry Value\n";
        std::cin >> choice;
        try {
            switch(choice) {
                case 1: {
                    print_keys();

                    std::cout << "Please choose one of them above and write below\n";

                    enter_first_key_again:
                    std::cout << "Choose your First Key Name:\n";
                    std::string first_key_name;
                    std::cin >> first_key_name;

                    //UPPERCASE
                    std::transform(first_key_name.begin(), first_key_name.end(), first_key_name.begin(),
                                   [](unsigned char c)
                                   {
                                       return std::toupper(c);
                                   });
                    //TRIM
                    first_key_name.erase(0, first_key_name.find_first_not_of(" \n\r\t"));
                    first_key_name.erase(first_key_name.find_last_not_of(" \n\r\t") + 1);

                    int key_1 = key_code_in_map(first_key_name);
                    if(key_1 != -1) { ; //NOTHING
                    }
                    else {
                        std::cout << "Please enter valid key!" << '\n';
                        goto enter_first_key_again;
                    }

                    const auto key_first = static_cast<uint8_t>(key_1);

                    enter_second_key_again:
                    std::cout << "Choose your Second Key Name:\n";
                    std::string second_key_name;
                    std::cin >> second_key_name;

                    //UPPERCASE
                    std::transform(second_key_name.begin(), second_key_name.end(), second_key_name.begin(),
                                   [](unsigned char c)
                                   {
                                       return std::toupper(c);
                                   });

                    //TRIM
                    second_key_name.erase(0, second_key_name.find_first_not_of(" \n\r\t"));
                    second_key_name.erase(second_key_name.find_last_not_of(" \n\r\t") + 1);

                    int key_2 = key_code_in_map(second_key_name);
                    if(key_2 != -1) { ; //NOTHING
                    }
                    else {
                        std::cout << "Please enter valid key!" << std::endl;
                        goto enter_second_key_again;
                    }

                    const auto key_second = static_cast<uint8_t>(key_2);

                    const uint8_t operand_first{static_cast<const uint8_t>(key_first)};
                    const uint8_t operand_second{static_cast<const uint8_t>(key_second)};

                    auto binary_data_vector = keyboard_re_layout.update_binary_data(operand_first, operand_second);
                    auto hKey = keyboard_re_layout.create_or_open_registry_key();

                    if(keyboard_re_layout.set_registry_binary_value(hKey, binary_data_vector)) {
                        keyboard_re_layout.close_registry_key(hKey);
                    }
                    else {
                        keyboard_re_layout.close_registry_key(hKey);
                    }
                    break;
                }
                case 2: {
                    auto hKey = keyboard_re_layout.create_or_open_registry_key();

                    if(keyboard_re_layout.delete_registry_value(hKey)) {
                        keyboard_re_layout.close_registry_key(hKey);
                    }
                    else {
                        keyboard_re_layout.close_registry_key(hKey);
                    }
                    break;
                }
                default:
                    std::cerr << "Invalid choice." << '\n';
                    break;
            }
        }
        catch(const std::runtime_error &ex) {
            std::cerr << "Exception occurred: " << ex.what() << '\n';
        }

        std::cout << "Press Enter to continue or Ctrl+C to exit..." << '\n';
        std::cin.ignore(); // Clear the newline character from the buffer
        std::cin.get(); // Wait for Enter key
    }
}



