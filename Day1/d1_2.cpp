#include <d1_common.h>

bool is_substr_at(const std::string& bigs, const std::string& smols, int i)
{
    // returns: does bigs contain smols at position i?
    int pos = 0;
    while(i < bigs.size() && pos < smols.size() && bigs[i] == smols[pos])
    {
        ++i;
        ++pos;
    }
    return pos == smols.size();
}

int get_calibration_value_2(const std::string& line)
{
    const std::string numbers[10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    int first = -1;
    int last = -1;
    for(int i=0; i < line.size(); ++i)
    {
        char c = line[i];
        if(is_digit(c))
        {
            if(first == -1)
            {
                first = c - '0';
            }
            last = c - '0';
        }
        else
        {
            for(int j = 0; j < 10; ++j)
            {
                const std::string& num_str = numbers[j];
                if(is_substr_at(line, num_str, i))
                {
                    if(first == -1)
                    {
                        first = j;
                    }
                    last = j;
                    break;
                }
            }
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
    std::cout << solve(get_calibration_value_2) << "\n";
    return 0;
}
