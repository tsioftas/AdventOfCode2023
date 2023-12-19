#include <iostream>

bool is_digit(const char& c)
{
    return '0' <= c && c <= '9';
}

int get_calibration_value(const std::string& line)
{
    int first = -1;
    int last = -1;
    for(auto c : line)
    {
        if(is_digit(c))
        {
            if(first == -1)
            {
                first = c - '0';
            }
            last = c - '0';
        }
    }
    if(first == -1)
    {
        return 0;
    }
    return 10*first + last;
}

int main()
{
    std::string input_line;
    int sum = 0;
    while(std::getline(std::cin, input_line))
    {
        sum += get_calibration_value(input_line);
    }
    std::cout << sum << "\n";
    return 0;
}
