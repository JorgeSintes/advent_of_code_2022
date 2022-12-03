#include <fstream>
#include <iostream>

int main()
{
    int calories{0}, total{0}, max_total{0};
    std::string input_line;
    std::ifstream input {"input"};

    while (std::getline(input, input_line))
    {
        if (input_line.empty())
        {
            if (total > max_total)
            {
                max_total = total;
            }
            total = 0; 
        }
        else
        {
            calories = std::stoi(input_line);
            total += calories;
        }
    }

    std::cout << "The total is: " << max_total << std::endl;
    return 0;
}