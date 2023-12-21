#ifndef D4_COMMON
#define D4_COMMON

#include <sstream>
#include <unordered_map>
#include <vector>
#include <iostream>

class Card
{
public:
    Card(std::string line);
    int how_many_winning();
private:
    std::vector<int> d_numbers;
    std::unordered_map<int, bool> d_winning_numbers;
};

std::vector<Card> read_input();

#endif // D4_COMMON