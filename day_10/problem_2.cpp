#include<iostream>
#include<fstream>

std::string draw_pixel(int register_no, int cycle_no)
{
    std::string return_string = "";
    if ((cycle_no%40 >= register_no -1) && (cycle_no%40 <= register_no +1)) {
        return_string += '#';
    }
    else {
        return_string += '.';
    }
    switch(cycle_no) {
        case 40:
            return_string += '\n';
            break;
        case 80:
            return_string += '\n';
            break;
        case 120:
            return_string += '\n';
            break;
        case 160:
            return_string += '\n';
            break;
        case 200:
            return_string += '\n';
            break;
        case 240:
            return_string += '\n';
            break;
    }
    
    return return_string;
}

int main()
{
    std::fstream file_input("input");
    std::string line;

    int cycle_no = 0;
    int register_no = 2;
    int line_number;

    std::string image;

    while(std::getline(file_input, line)) {
        if (line == "noop") {
            cycle_no ++;
            image += draw_pixel(register_no, cycle_no);
        }
        if (line.substr(0,4) == "addx") {
            cycle_no++;
            image += draw_pixel(register_no, cycle_no);
            cycle_no++;
            image += draw_pixel(register_no, cycle_no);
            line_number = std::stoi(line.substr(5, line.length()));
            register_no += line_number;
        }
    }
    std::cout << image << std::endl;
}