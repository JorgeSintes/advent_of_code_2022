#include <fstream>
#include <iostream>

int main()
{
    int calories{0}, total{0};
    int top1{0}, top2{0}, top3{0};
    std::ifstream input("input");
    std::string line;

    while(std::getline(input, line))
    {
        if (line.empty())
        {
            if (total > top1)
            {
                top3 = top2;
                top2 = top1;
                top1 = total;
            }
            else if (total > top2)
            {
                top3 = top2;
                top2 = total;
            }
            else if (total > top3)
            {
                top3 = total;
            }
            total = 0;
        }
        else
        {
            calories = std::stoi(line);
            total += calories;
        }
    }
    std::cout << top1 << ", " << top2 << ", " << top3 << std::endl;
    std::cout << "The total is: " << top1+top2+top3 << std::endl;
}