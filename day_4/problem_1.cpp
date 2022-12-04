#include <fstream>
#include <iostream>

bool is_contained(std::string sequence, std::string outer_sequence)
{
    /* Returns true if sequence is contained on outer_sequence, false otherwise. */
    int sequence_l = std::stoi(sequence.substr(0, sequence.find('-')));
    int sequence_r = std::stoi(sequence.substr(sequence.find('-')+1, sequence.length()));
    int outer_sequence_l = std::stoi(outer_sequence.substr(0, outer_sequence.find('-')));
    int outer_sequence_r = std::stoi(outer_sequence.substr(outer_sequence.find('-')+1, outer_sequence.length()));
    if ((sequence_l >= outer_sequence_l) && (sequence_r <= outer_sequence_r)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int result = 0;
    std::string line;
    std::fstream input_file("input");

    while(std::getline(input_file, line))
    {
        // Separate the different sequences of assignments
        int comma_idx = line.find(',');
        std::string sequence_1 = line.substr(0, comma_idx);
        std::string sequence_2 = line.substr(comma_idx+1, line.length());
        if (is_contained(sequence_1, sequence_2) || is_contained(sequence_2, sequence_1)) {
            result++;
        }
    }

    std::cout << "The result is: " << result << std::endl;
}