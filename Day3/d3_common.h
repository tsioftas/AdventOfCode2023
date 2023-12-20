#ifndef D3_COMMON
#define D3_COMMON

#include <iostream>
#include <vector>

class Schematic
{
protected:
    int M, N;
    char** _;

    struct _hidden
    {
        char* line;
        _hidden(char* l) : line{l} {};
        char operator[](int j)
        {
            return line[j];
        }
    };

public:
    Schematic(const std::vector<std::string>& sqr);
    ~Schematic();

    bool is_part_number(int  i, int j);
    bool is_number(int i, int j);
    bool is_symbol(int i, int j);
    bool is_valid_pos(int i, int j);

    int M_size();
    int N_size();
    int val(int i, int j);

    _hidden operator[](int i)
    {
        return _hidden(_[i]);
    }
};

Schematic* read_input();

#endif // D3_COMMON