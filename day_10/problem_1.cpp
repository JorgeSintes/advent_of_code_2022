#include<iostream>
#include<fstream>

int add_score(int register_no, int cycle_no) {
    switch(cycle_no) {
        case 20:
            return register_no*cycle_no;
        case 60:
            return register_no*cycle_no;
        case 100:
            return register_no*cycle_no;
        case 140:
            return register_no*cycle_no;
        case 180:
            return register_no*cycle_no;
        case 220:
            return register_no*cycle_no;
        default:
            return 0;
    }
}

int main()
{
    std::fstream file_input("input");
    std::string line;
    int cycle_no = 0;
    int register_no = 1;
    int line_number;
    int signal_strength = 0;

    while(std::getline(file_input, line)) {
        if (line == "noop") {
            cycle_no ++;
            signal_strength += add_score(register_no, cycle_no);
        }
        if (line.substr(0,4) == "addx") {
            line_number = std::stoi(line.substr(5, line.length()));
            cycle_no++;
            signal_strength += add_score(register_no, cycle_no);
            cycle_no++;
            signal_strength += add_score(register_no, cycle_no);
            register_no += line_number;
        }
    }

    std::cout << signal_strength << std::endl;
}