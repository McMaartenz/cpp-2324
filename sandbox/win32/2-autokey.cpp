#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <vector>
#include <array>

template <typename T>
using vec = std::vector<T>;

struct key_stroke {
    INPUT down;
    INPUT up;
};

//! @param[in] key virtual-key code
//! @return INPUT structs
constexpr key_stroke generate_input(WORD key);

//! @param[in] key key
//! @return INPUT structs
vec<INPUT> generate_input_key(char key);

//! @param[in] key key
//! @return success
bool send_key(char key);

//! @param[in] keys keys
//! @return success
bool send_keys(std::string keys);

//! @param[in] inputs strokes
//! @param[in] input_size stroke count
bool send_strokes(LPINPUT inputs, UINT input_size);

int main(int argc, char** argv, char** envp) {
    bool ok = send_keys("Hello World");
    if (!ok) {
        std::cout << "Failed to send strokes\n";
    }
    
    return EXIT_SUCCESS;
}

bool send_key(char key) {
    vec<INPUT> inputs = generate_input_key(key);
    return send_strokes((LPINPUT)&inputs[0], inputs.size());
}

bool send_keys(std::string keys) {
    vec<INPUT> all_inputs{};
    for (char k : keys) {
        vec<INPUT> inputs = generate_input_key(k);
        all_inputs.insert(all_inputs.end(), inputs.begin(), inputs.end());
    }

    return send_strokes((LPINPUT)&all_inputs[0], all_inputs.size());
}

bool send_strokes(LPINPUT inputs, UINT input_size) {
    return input_size == SendInput(input_size, inputs, sizeof(INPUT));
}

constexpr key_stroke generate_input(WORD key) {
    key_stroke event {};

    event.down.type = INPUT_KEYBOARD;
    event.down.ki.wVk = key;

    event.up.type = INPUT_KEYBOARD;
    event.up.ki.wVk = key;
    event.up.ki.dwFlags = KEYEVENTF_KEYUP;
    
    return event;
}

vec<INPUT> generate_input_key(char key) {
    vec<INPUT> inputs(2);

    const bool is_upper = std::isupper(key);
    key = std::toupper(key);

    key_stroke key_evt = generate_input(key);
    key_stroke shift_evt = generate_input(VK_LSHIFT);
    
    if (is_upper) inputs.push_back(shift_evt.down);

    inputs.push_back(key_evt.down);
    inputs.push_back(key_evt.up);

    if (is_upper) inputs.push_back(shift_evt.up);

    return inputs;
}
