#include <fstream>
#include <iostream>
#include <map>

bool is_char_in_string(char c, std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Construct priority dictionary
    std::map<char, int> priority_dict;
    int score = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        priority_dict[c] = score;
        score++;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        priority_dict[c] = score;
        score++;
    }

    int sum_of_priorities = 0;

    std::string line;
    std::ifstream input_file("input");

    while(std::getline(input_file, line))
    {
        std::string ruckpack_1 = line.substr(0, line.length()/2);
        std::string ruckpack_2 = line.substr(line.length()/2, line.length()/2);
        for (int i = 0; i < line.length()/2; i++) // for each char in ruckpack 1
        {
            if (is_char_in_string(ruckpack_1[i], ruckpack_2))
            {
                std::cout << ruckpack_1 << ", letter " << ruckpack_1[i] << " is in " << ruckpack_2 << std::endl;
                std::cout << "Score is: " << priority_dict[ruckpack_1[i]] << std::endl;
                sum_of_priorities += priority_dict[ruckpack_1[i]];
                break;
            }

        }
    }
    std::cout << sum_of_priorities << std::endl;
}