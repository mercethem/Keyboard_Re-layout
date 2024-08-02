#include <iostream>
#include <unordered_map>
#include "keyboard_lookup_table.h"
#include <iomanip>


//Key names array
const char* key_names[] = {
        "NUMBER_1",
        "NUMBER_2",
        "NUMBER_3",
        "NUMBER_4",
        "NUMBER_5",
        "NUMBER_6",
        "NUMBER_7",
        "NUMBER_8",
        "NUMBER_9",
        "NUMBER_0",

        "LETTER_Q",
        "LETTER_W",
        "LETTER_E",
        "LETTER_R",
        "LETTER_T",
        "LETTER_Y",
        "LETTER_U",
        "LETTER_I",
        "LETTER_O",
        "LETTER_P",
        "LETTER_A",
        "LETTER_S",
        "LETTER_D",
        "LETTER_F",
        "LETTER_G",
        "LETTER_H",
        "LETTER_J",
        "LETTER_K",
        "LETTER_L",
        "LETTER_Z",
        "LETTER_X",
        "LETTER_C",
        "LETTER_V",
        "LETTER_B",
        "LETTER_N",
        "LETTER_M",

        "F1",
        "F2",
        "F3",
        "F4",
        "F5",
        "F6",
        "F7",
        "F8",
        "F9",
        "F10",
        "F11",
        "F12",

        "NUMPAD_0",
        "NUMPAD_1",
        "NUMPAD_2",
        "NUMPAD_3",
        "NUMPAD_4",
        "NUMPAD_5",
        "NUMPAD_6",
        "NUMPAD_7",
        "NUMPAD_8",
        "NUMPAD_9",
        "NUMPAD_DECIMAL",
        "NUMPAD_DIVIDE",
        "NUMPAD_MULTIPLY",
        "NUMPAD_SUBTRACT",
        "NUMPAD_ADD",
        "NUMPAD_ENTER",

        "BACKSPACE",
        "TAB",
        "ENTER",
        "ESC",
        "SPACE",
        "CAPS_LOCK",
        "SHIFT_LEFT",
        "SHIFT_RIGHT",
        "CTRL_LEFT",
        "CTRL_RIGHT",
        "ALT_LEFT",
        "ALT_RIGHT",
        "DELETE",
        "HOME",
        "END",
        "PAGE_UP",
        "PAGE_DOWN",
        "UP_ARROW",
        "DOWN_ARROW",
        "LEFT_ARROW",
        "RIGHT_ARROW",

        "PRINT_SCREEN",
        "SCROLL_LOCK",
        "PAUSE",
        "INSERT",
        "APPLICATION",
        "NUM_LOCK"
};


//key name and map
const std::unordered_map<std::string, KeyCodes> key_map = {
        {"NUMBER_1",        KeyCodes::NUMBER_1},
        {"NUMBER_2",        KeyCodes::NUMBER_2},
        {"NUMBER_3",        KeyCodes::NUMBER_3},
        {"NUMBER_4",        KeyCodes::NUMBER_4},
        {"NUMBER_5",        KeyCodes::NUMBER_5},
        {"NUMBER_6",        KeyCodes::NUMBER_6},
        {"NUMBER_7",        KeyCodes::NUMBER_7},
        {"NUMBER_8",        KeyCodes::NUMBER_8},
        {"NUMBER_9",        KeyCodes::NUMBER_9},
        {"NUMBER_0",        KeyCodes::NUMBER_0},

        {"LETTER_Q",        KeyCodes::LETTER_Q},
        {"LETTER_W",        KeyCodes::LETTER_W},
        {"LETTER_E",        KeyCodes::LETTER_E},
        {"LETTER_R",        KeyCodes::LETTER_R},
        {"LETTER_T",        KeyCodes::LETTER_T},
        {"LETTER_Y",        KeyCodes::LETTER_Y},
        {"LETTER_U",        KeyCodes::LETTER_U},
        {"LETTER_I",        KeyCodes::LETTER_I},
        {"LETTER_O",        KeyCodes::LETTER_O},
        {"LETTER_P",        KeyCodes::LETTER_P},
        {"LETTER_A",        KeyCodes::LETTER_A},
        {"LETTER_S",        KeyCodes::LETTER_S},
        {"LETTER_D",        KeyCodes::LETTER_D},
        {"LETTER_F",        KeyCodes::LETTER_F},
        {"LETTER_G",        KeyCodes::LETTER_G},
        {"LETTER_H",        KeyCodes::LETTER_H},
        {"LETTER_J",        KeyCodes::LETTER_J},
        {"LETTER_K",        KeyCodes::LETTER_K},
        {"LETTER_L",        KeyCodes::LETTER_L},
        {"LETTER_Z",        KeyCodes::LETTER_Z},
        {"LETTER_X",        KeyCodes::LETTER_X},
        {"LETTER_C",        KeyCodes::LETTER_C},
        {"LETTER_V",        KeyCodes::LETTER_V},
        {"LETTER_B",        KeyCodes::LETTER_B},
        {"LETTER_N",        KeyCodes::LETTER_N},
        {"LETTER_M",        KeyCodes::LETTER_M},

        {"F1",              KeyCodes::F1},
        {"F2",              KeyCodes::F2},
        {"F3",              KeyCodes::F3},
        {"F4",              KeyCodes::F4},
        {"F5",              KeyCodes::F5},
        {"F6",              KeyCodes::F6},
        {"F7",              KeyCodes::F7},
        {"F8",              KeyCodes::F8},
        {"F9",              KeyCodes::F9},
        {"F10",             KeyCodes::F10},
        {"F11",             KeyCodes::F11},
        {"F12",             KeyCodes::F12},

        {"NUMPAD_0",        KeyCodes::NUMPAD_0},
        {"NUMPAD_1",        KeyCodes::NUMPAD_1},
        {"NUMPAD_2",        KeyCodes::NUMPAD_2},
        {"NUMPAD_3",        KeyCodes::NUMPAD_3},
        {"NUMPAD_4",        KeyCodes::NUMPAD_4},
        {"NUMPAD_5",        KeyCodes::NUMPAD_5},
        {"NUMPAD_6",        KeyCodes::NUMPAD_6},
        {"NUMPAD_7",        KeyCodes::NUMPAD_7},
        {"NUMPAD_8",        KeyCodes::NUMPAD_8},
        {"NUMPAD_9",        KeyCodes::NUMPAD_9},
        {"NUMPAD_DECIMAL",  KeyCodes::NUMPAD_DECIMAL},
        {"NUMPAD_DIVIDE",   KeyCodes::NUMPAD_DIVIDE},
        {"NUMPAD_MULTIPLY", KeyCodes::NUMPAD_MULTIPLY},
        {"NUMPAD_SUBTRACT", KeyCodes::NUMPAD_SUBTRACT},
        {"NUMPAD_ADD",      KeyCodes::NUMPAD_ADD},
        {"NUMPAD_ENTER",    KeyCodes::NUMPAD_ENTER},

        {"BACKSPACE",       KeyCodes::BACKSPACE},
        {"TAB",             KeyCodes::TAB},
        {"ENTER",           KeyCodes::ENTER},
        {"ESC",             KeyCodes::ESC},
        {"SPACE",           KeyCodes::SPACE},
        {"CAPS_LOCK",       KeyCodes::CAPS_LOCK},
        {"SHIFT_LEFT",      KeyCodes::SHIFT_LEFT},
        {"SHIFT_RIGHT",     KeyCodes::SHIFT_RIGHT},
        {"CTRL_LEFT",       KeyCodes::CTRL_LEFT},
        {"CTRL_RIGHT",      KeyCodes::CTRL_RIGHT},
        {"ALT_LEFT",        KeyCodes::ALT_LEFT},
        {"ALT_RIGHT",       KeyCodes::ALT_RIGHT},
        {"DELETE_",         KeyCodes::DELETE_},
        {"HOME",            KeyCodes::HOME},
        {"END",             KeyCodes::END},
        {"PAGE_UP",         KeyCodes::PAGE_UP},
        {"PAGE_DOWN",       KeyCodes::PAGE_DOWN},
        {"UP_ARROW",        KeyCodes::UP_ARROW},
        {"DOWN_ARROW",      KeyCodes::DOWN_ARROW},
        {"LEFT_ARROW",      KeyCodes::LEFT_ARROW},
        {"RIGHT_ARROW",     KeyCodes::RIGHT_ARROW},

        {"PRINT_SCREEN",    KeyCodes::PRINT_SCREEN},
        {"SCROLL_LOCK",     KeyCodes::SCROLL_LOCK},
        {"PAUSE",           KeyCodes::PAUSE},
        {"INSERT",          KeyCodes::INSERT},
        {"APPLICATION",     KeyCodes::APPLICATION},
        {"NUM_LOCK",        KeyCodes::NUM_LOCK}
};


KeyCodes get_key_code(const std::string &key_name)
{
    auto it = key_map.find(key_name);
    if(it != key_map.end()) {
        return it->second;
    }
    throw std::invalid_argument("Invalid key name");
}


int key_code_in_map(const std::string &str_code_name)
{
    try {
        KeyCodes key_code = get_key_code(str_code_name);
        return static_cast<int>(key_code);
    }
    catch(const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1; //Error return value
    }
}


void print_keys()
{
    const int colWidth = 25; // Width of each column
    const int numCols = 4;   // Number of columns

    // Print the key names in three columns
    for(size_t i = 0; i < sizeof(key_names) / sizeof(key_names[0]); i += numCols) {
        for(int j = 0; j < numCols; ++j) {
            if(i + j < sizeof(key_names) / sizeof(key_names[0])) {
                std::cout << std::setw(colWidth) << key_names[i + j];
            }
        }
        std::cout << std::endl;
    }
}