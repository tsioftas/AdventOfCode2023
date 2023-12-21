#include <d4_common.h>

int main()
{
    int sum = 0;
    std::vector<Card> input = read_input();
    for(std::vector<Card>::iterator it = input.begin(); it != input.end(); ++it)
    {
        int w = it->how_many_winning();
        sum += w > 0 ? (1 << (w-1)) : 0;
    }
    std::cout << sum << "\n";
    return 0;
}