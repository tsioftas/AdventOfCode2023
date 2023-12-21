#include <d4_common.h>

int main()
{
    std::vector<Card> input = read_input();
    int N = input.size();
    int multiplier[N];
    for(int i=0; i < N; ++i)
    {
        multiplier[i] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i)
    {
        cnt += multiplier[i];
        int w = input[i].how_many_winning();
        for(int j = 1; j <= w; ++j)
        {
            multiplier[i+j] += multiplier[i];
        }
    }
    std::cout << cnt << "\n";
    return 0;
}