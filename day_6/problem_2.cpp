#include <fstream>
#include <iostream>

bool is_valid(std::string marker)
{
    for (int i = 0; i < marker.length()-1; i++) {
        for (int j = i+1; j < marker.length(); j++){
            if (marker[i] == marker[j]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::fstream input_file("input");
    std::string line;
    std::getline(input_file, line);
    std::string marker = line.substr(0,14);

    for (int i = 14; i < line.length(); i++) {
        if (is_valid(marker)) {
            std::cout << "Valid at character " << i << std::endl;
            break;
        }
        marker = marker.substr(1,13) + line[i];
    }
}