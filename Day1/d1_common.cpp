#include <d1_common.h>

int solve(int (*get_calibration_value)(const std::string&))
{
    std::string input_line;
    int sum = 0;
    while(std::getline(std::cin, input_line))
    {
        sum += get_calibration_value(input_line);
    }
    return sum;
}

bool is_digit(const char& c)
{
    return '0' <= c && c <= '9';
}
