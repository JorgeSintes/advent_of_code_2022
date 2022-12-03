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
    std::string line_1;
    std::ifstream input_file("input");

    while(std::getline(input_file, line_1))
    {
        std::string line_2, line_3;
        std::getline(input_file, line_2);
        std::getline(input_file, line_3);

        for (int i = 0; i < line_1.length(); i++) // for each char in ruckpack 1
        {
            if (is_char_in_string(line_1[i], line_2) && is_char_in_string(line_1[i], line_3))
            {
                sum_of_priorities += priority_dict[line_1[i]];
                break;
            }
        }
    }
    std::cout << sum_of_priorities << std::endl;
}