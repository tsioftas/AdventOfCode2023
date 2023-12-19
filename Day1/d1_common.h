#ifndef D1_COMMON
#define D1_COMMON

#include <iostream>

int solve(int (*get_calibration_value)(const std::string&));
bool is_digit(const char& c);

#endif
