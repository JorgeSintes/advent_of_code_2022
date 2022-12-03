#include <fstream>
#include <iostream>

int main()
{
    int total_score{0};
    std::string line;
    std::ifstream input("input");

    int scores[3] = {1,2,3}; // Storing the scores depending on what you've played
    int idx, idx_modifier; // Storing the index of what the oponent plays and the offset depending if you won, lost or tied

    while(std::getline(input, line))
    {
        switch(line[2]) // Assign scores depending if you win or not.
        {
            case 'X': // Lost
                total_score += 0;
                idx_modifier = 2;
                break;
            case 'Y': // Tied
                total_score += 3;
                idx_modifier = 0;
                break;
            case 'Z': // Won
                total_score += 6;
                idx_modifier = 1;
                break;
        }
        switch(line[0])
        {
            case 'A':
                idx = 0;
                break;
            case 'B':
                idx = 1;
                break;
            case 'C':
                idx = 2;
                break;
        }
        total_score += scores[(idx + idx_modifier) % 3]; // Add the score depending on what the oponent played
    }

    std::cout << "Result: " << total_score << std::endl;
}