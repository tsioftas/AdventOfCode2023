#include <d2_common.h>

int power(Game g)
{
    int min_r = 0;
    int min_g = 0;
    int min_b = 0;
    for(int i = 0; i < g.rounds().size(); ++i)
    {
        min_r = std::max(min_r, g.rounds()[i].d_r);
        min_g = std::max(min_g, g.rounds()[i].d_g);
        min_b = std::max(min_b, g.rounds()[i].d_b);
    }
    return min_r * min_g * min_b;
}

int main()
{
    std::vector<Game> games = read_input();
    int sum = 0;
    for(Game game : games)
    {
        sum += power(game);
    }
    std::cout << sum << "\n";
}
