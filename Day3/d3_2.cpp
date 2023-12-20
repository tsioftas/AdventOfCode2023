#include <d3_common.h>

#include <set>
#include <unordered_map>

class SchematicB : public Schematic
{
public:
    SchematicB(std::vector<std::string> sqr) : Schematic(sqr)
    {
        asterisks = new std::set<int>*[M];
        numids = new int*[M];
        int numid = 0;
        int num = 0;
        for(int i=0; i < M; ++i)
        {
            asterisks[i] = new std::set<int>[N];
            numids[i] = new int[N];

            for(int j=0; j < N; ++j)
            {
                if(!is_number(i, j))
                {
                    numids[i][j] = -1;
                    num = 0;
                }
                else
                {
                    if(is_valid_pos(i, j-1) && is_number(i, j-1))
                    {
                        numids[i][j] = numids[i][j-1];
                    }
                    else
                    {
                        numids[i][j] = numid++;
                    }
                    num = 10*num + val(i, j);
                    if(!is_valid_pos(i, j+1) || !is_number(i, j+1))
                    {
                        numid_to_val[numids[i][j]] = num;
                        num = 0;
                    }
                }
            }
        }
    }

    ~SchematicB()
    {
        for(int i=0; i < M; ++i)
        {
            delete[] asterisks[i];
            delete[] numids[i];
        }
        delete[] asterisks;
        delete[] numids;
    }

    bool is_part_number(int  i, int j)
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
        bool ret = false;
        for(int ii=0; ii < 8; ++ii)
        {
            int x = adjacents[ii].first;
            int y = adjacents[ii].second;
            if(is_valid_pos(x, y) && is_symbol(x, y))
            {
                if(_[x][y] == '*')
                {
                    asterisks[x][y].insert(numids[i][j]);
                }
                ret = true;
            }
        }
        return ret;
    }

    void debug()
    {
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                std::cout << numids[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::set<int>** asterisks;
    std::unordered_map<int, int> numid_to_val;
private:
    int** numids;
};

SchematicB* read_input_2()
{
    std::string line;
    std::vector<std::string> input;
    while(std::getline(std::cin, line))
    {
        input.push_back(line);
    }
    return new SchematicB(input);
}

int main()
{
    int sum = 0;
    SchematicB* input = read_input_2();
    for(int i=0; i < input->M_size(); ++i)
    {
        for(int j=0; j < input->N_size(); ++j)
        {
            input->is_part_number(i, j);
        }
    }

    for(int i=0; i < input->M_size(); ++i)
    {
        for(int j=0; j < input->N_size(); ++j)
        {
            if(input->asterisks[i][j].size() == 2)
            {
                int numidA = *(input->asterisks[i][j].begin());
                int numidB = *(std::next(input->asterisks[i][j].begin()));
                int numA = input->numid_to_val[numidA];
                int numB = input->numid_to_val[numidB];
                sum += numA * numB;
            }
        }
    }

    std::cout << sum << "\n";
    delete input;
}