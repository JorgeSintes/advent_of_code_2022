#include <fstream>
#include <iostream>

int main()
{
    int total_score{0};
    std::string line;
    std::ifstream input("input");

    while(std::getline(input, line))
    {
        switch(line[2]) // Assign scores depending on what you've played
        {
            case 'X':
                total_score += 1;
                break;
            case 'Y':
                total_score += 2;
                break;
            case 'Z':
                total_score += 3;
                break;
        }
        if ((line[0] == 'A' && line[2] == 'Y') || (line[0] == 'B' && line[2] == 'Z') || (line[0] == 'C' && line[2] == 'X'))
            total_score += 6;
        else if ((line[0] == 'A' && line[2] == 'X') || (line[0] == 'B' && line[2] == 'Y') || (line[0] == 'C' && line[2] == 'Z'))
            total_score += 3;
    }

    std::cout << "Result: " << total_score << std::endl;
}