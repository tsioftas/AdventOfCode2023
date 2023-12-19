#ifndef D2_COMMON
#define D2_COMMON

#include <vector>
#include <iostream>

class Game
{
    public:
        static Game parseLine(const std::string& input_line);
        struct round
        {
            public:
                int d_r, d_g, d_b;
                round(int r, int g, int b) :
                    d_r{r}, d_g{g}, d_b{b} {}
        };
        const std::vector<round>& rounds() const;
        const int id() const;
    private:
        Game(int id, const std::vector<round>& rounds);
        static std::vector<std::pair<int, char> >* parseInput(const std::string& line);

        int d_id;
        std::vector<round> d_rounds;
};

std::vector<std::string>* tokenize(const  std::string& s, const char& delimiter);

std::vector<Game> read_input();

#endif
