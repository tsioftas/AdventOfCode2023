#include <d4_common.h>

Card::Card(std::string line)
{
    int colon = line.find_first_of(':');
    int bar = line.find_first_of('|');
    std::string winning_numbers_str = line.substr(colon+1, bar-colon-1);
    std::string check_numbers_str = line.substr(bar+1);
    std::istringstream line_stream(winning_numbers_str);
    int winning_number;
    while(line_stream >> winning_number)
    {
        d_winning_numbers[winning_number] = true;
    }
    line_stream = std::istringstream(check_numbers_str);
    int check_number;
    while(line_stream >> check_number)
    {
        d_numbers.push_back(check_number);
    }
}

int Card::how_many_winning()
{
    int cnt = 0;
    for(std::vector<int>::iterator it = d_numbers.begin(); it != d_numbers.end(); ++it)
    {
        cnt += d_winning_numbers[*it];
    }
    return cnt;
}

std::vector<Card> read_input()
{
    std::vector<Card> ret;
    std::string line;
    while(std::getline(std::cin, line))
    {
        ret.push_back(Card(line));
    }
    return ret;
}