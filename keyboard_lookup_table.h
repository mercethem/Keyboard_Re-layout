#ifndef KEYBOARD_RE_LAYOUT_KEYBOARD_LOOKUP_TABLE_H
#define KEYBOARD_RE_LAYOUT_KEYBOARD_LOOKUP_TABLE_H


#define     KEYBOARD_SUB_STR    "SYSTEM\\CurrentControlSet\\Control\\Keyboard Layout"
#define     REGISTER_NAME       "Scancode Map"


//Key names and hex codes
enum class KeyCodes
{
    // Number keys (top row)
    NUMBER_1 = 0x02,
    NUMBER_2 = 0x03,
    NUMBER_3 = 0x04,
    NUMBER_4 = 0x05,
    NUMBER_5 = 0x06,
    NUMBER_6 = 0x07,
    NUMBER_7 = 0x08,
    NUMBER_8 = 0x09,
    NUMBER_9 = 0x0A,
    NUMBER_0 = 0x0B,

    // Alphabet keys
    LETTER_Q = 0x10,
    LETTER_W = 0x11,
    LETTER_E = 0x12,
    LETTER_R = 0x13,
    LETTER_T = 0x14,
    LETTER_Y = 0x15,
    LETTER_U = 0x16,
    LETTER_I = 0x17,
    LETTER_O = 0x18,
    LETTER_P = 0x19,
    LETTER_A = 0x1E,
    LETTER_S = 0x1F,
    LETTER_D = 0x20,
    LETTER_F = 0x21,
    LETTER_G = 0x22,
    LETTER_H = 0x23,
    LETTER_J = 0x24,
    LETTER_K = 0x25,
    LETTER_L = 0x26,
    LETTER_Z = 0x2C,
    LETTER_X = 0x2D,
    LETTER_C = 0x2E,
    LETTER_V = 0x2F,
    LETTER_B = 0x30,
    LETTER_N = 0x31,
    LETTER_M = 0x32,

    // Function keys
    F1 = 0x3B,
    F2 = 0x3C,
    F3 = 0x3D,
    F4 = 0x3E,
    F5 = 0x3F,
    F6 = 0x40,
    F7 = 0x41,
    F8 = 0x42,
    F9 = 0x43,
    F10 = 0x44,
    F11 = 0x57,
    F12 = 0x58,

    // Numpad keys
    NUMPAD_0 = 0x52,
    NUMPAD_1 = 0x4F,
    NUMPAD_2 = 0x50,
    NUMPAD_3 = 0x51,
    NUMPAD_4 = 0x4B,
    NUMPAD_5 = 0x4C,
    NUMPAD_6 = 0x4D,
    NUMPAD_7 = 0x47,
    NUMPAD_8 = 0x48,
    NUMPAD_9 = 0x49,
    NUMPAD_DECIMAL = 0x53,
    NUMPAD_DIVIDE = 0x35,
    NUMPAD_MULTIPLY = 0x37,
    NUMPAD_SUBTRACT = 0x4A,
    NUMPAD_ADD = 0x4E,
    NUMPAD_ENTER = 0x1C,

    // Control and special keys
    BACKSPACE = 0x0E,
    TAB = 0x0F,
    ENTER = 0x1C,
    ESC = 0x01,
    SPACE = 0x39,
    CAPS_LOCK = 0x3A,
    SHIFT_LEFT = 0x2A,
    SHIFT_RIGHT = 0x36,
    CTRL_LEFT = 0x1D,
    CTRL_RIGHT = 0x1D,
    ALT_LEFT = 0x38,
    ALT_RIGHT = 0x38,
    DELETE_ = 0x53,
    HOME = 0x47,
    END = 0x4F,
    PAGE_UP = 0x49,
    PAGE_DOWN = 0x51,
    UP_ARROW = 0x48,
    DOWN_ARROW = 0x50,
    LEFT_ARROW = 0x4B,
    RIGHT_ARROW = 0x4D,

    // Other special keys
    PRINT_SCREEN = 0x37,
    SCROLL_LOCK = 0x46,
    PAUSE = 0x45,
    INSERT = 0x52,
    APPLICATION = 0x5D,
    NUM_LOCK = 0x45
};


KeyCodes get_key_code(const std::string &key_name);

int key_code_in_map(const std::string &str_code_name);

void print_keys();


#endif //KEYBOARD_RE_LAYOUT_KEYBOARD_LOOKUP_TABLE_H
