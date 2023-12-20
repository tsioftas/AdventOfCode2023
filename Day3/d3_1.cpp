#include <d3_common.h>

int main()
{
    int sum = 0;
    Schematic* input = read_input();
    std::cout << input->M_size() << " " << input->N_size() << std::endl;
    for(int i=0; i < input->M_size(); ++i)
    {
        int linesum = 0;
        int num = 0;
        bool found_part_number = false;
        for(int j=0; j < input->N_size(); ++j)
        {
            if(input->is_number(i, j))
            {
                num *= 10;
                num += input->val(i, j);
                if(input->is_part_number(i, j))
                {
                    found_part_number = true;
                }
            }
            else
            {
                if(found_part_number)
                {
                    linesum += num;
                }
                found_part_number = false;
                num = 0;
            }
        }
        if(found_part_number)
        {
            linesum += num;
        }
        sum += linesum;
    }
    std::cout << sum << "\n";
    delete input;
}