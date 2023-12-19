#include <d2_common.h>

bool possible(Game g, int max_r, int max_g, int max_b)
{
    bool poss = true;
    for(int i=0; poss && i < g.rounds().size(); ++i)
    {
        Game::round r = g.rounds()[i];
        poss &= r.d_b <= max_b && r.d_r <= max_r && r.d_g <= max_g;
    }
    return poss;
}

int main()
{
    std::vector<Game> games = read_input();
    int sum = 0;
    for(Game game : games)
    {
        if(possible(game, 12, 13, 14))
        {
            sum += game.id();
        }
    }
    std::cout << sum << "\n";
}
