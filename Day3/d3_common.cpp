#include <d3_common.h>

Schematic::Schematic(const std::vector<std::string>& sqr)
{
    M = sqr.size();
    N = sqr[0].size();
    _ = new char*[M];
    for(int i=0; i < M; ++i)
    {
        _[i] = new char[N];
        for(int j=0; j < N; ++j)
        {
            _[i][j] = sqr[i][j];
        }
    }
}

Schematic::~Schematic()
{
    for(int i=0; i < M; ++i)
    {
        delete _[i];
    }
    delete _;
}

Schematic* read_input()
{
    std::string line;
    std::vector<std::string> input;
    while(std::getline(std::cin, line))
    {
        input.push_back(line);
    }
    return new Schematic(input);
}

bool Schematic::is_part_number(int  i, int j)
{
    if(!is_number(i, j))
    {
        return false;
    }
    std::pair<int, int> adjacents[] = {
        std::make_pair(i-1, j-1),
        std::make_pair(i-1, j),
        std::make_pair(i-1, j+1),
        std::make_pair(i, j-1),
        std::make_pair(i, j+1),
        std::make_pair(i+1, j-1),
        std::make_pair(i+1, j),
        std::make_pair(i+1, j+1),
    };
    for(int i=0; i < 8; ++i)
    {
        int x = adjacents[i].first;
        int y = adjacents[i].second;
        if(is_valid_pos(x, y) && is_symbol(x, y))
        {
            return true;
        }
    }
    return false;
}

bool Schematic::is_number(int i, int j)
{
    return '0' <= _[i][j] && _[i][j] <= '9';
}

bool Schematic::is_symbol(int i, int j)
{
    return _[i][j] != '.' && !is_number(i, j);
}

bool Schematic::is_valid_pos(int i, int j)
{
    return 0 <= i && i < M && 0 <= j && j < N;
}

int Schematic::M_size()
{
    return M;
}

int Schematic::N_size()
{
    return N;
}

int Schematic::val(int i, int j)
{
    return _[i][j] - '0';
}