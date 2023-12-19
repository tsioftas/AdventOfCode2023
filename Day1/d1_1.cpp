#include <d1_common.h>

int get_calibration_value_1(const std::string& line)
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
    std::cout << solve(get_calibration_value_1) << "\n";
    return 0;
}
