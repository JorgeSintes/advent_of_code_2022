#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class CharStack
{
    private:
        char* bottom;
        char* level;
        int size;

    public:
        CharStack(int stack_size=16)
        {
            level = (char *) malloc(stack_size);
            bottom = level;
            size = stack_size;
        }

        void increase_size()
        {
            bottom = (char *) realloc(bottom, size*2);
            level = bottom + size;
            size = size*2;
        }
        
        void add(char character)
        {
            *level = character;
            level++;
            if (level == bottom + size) {
                increase_size();
            }
        }
        
        void add_from_string(std::string input_string)
        {
            for (int i=0; i < input_string.length(); i++)
            {
                add(input_string[i]);
            }
        }

        char peek()
        {
            if (level > bottom) {
                return *(level-1);
            }
            else {
                return '0';
            }
        }

        char pop()
        {
            if (level > bottom) {
                level--;
                return *(level);
            }
            else {
                return '0';
            }
        }

        std::string pop_several(int no_pops)
        {
            std::string result;
            for (int i=0; i<no_pops; i++){
                result = pop() + result;
            }
            return result;
        }

        int get_size()
        {
            return size;
        }
};

int main()
{
    // Define stacks
    CharStack stack_1(2);
    CharStack stack_2(2);
    CharStack stack_3(2);
    CharStack stack_4(2);
    CharStack stack_5(2);
    CharStack stack_6(2);
    CharStack stack_7(2);
    CharStack stack_8(2);
    CharStack stack_9(2);

    stack_1.add_from_string("BGSC");
    stack_2.add_from_string("TMWHJNVG");
    stack_3.add_from_string("MQS");
    stack_4.add_from_string("BSLTWNM");
    stack_5.add_from_string("JZFTVGWP");
    stack_6.add_from_string("CTBGQHS");
    stack_7.add_from_string("TJPBW");
    stack_8.add_from_string("GDCZFTQM");
    stack_9.add_from_string("NSHBPF");

    std::map<int, CharStack> stack_dict;
    stack_dict[1] = stack_1;
    stack_dict[2] = stack_2;
    stack_dict[3] = stack_3;
    stack_dict[4] = stack_4;
    stack_dict[5] = stack_5;
    stack_dict[6] = stack_6;
    stack_dict[7] = stack_7;
    stack_dict[8] = stack_8;
    stack_dict[9] = stack_9;

    std::string line;
    std::fstream input_file("input");

    while(std::getline(input_file, line))
    {
        // Parse line
        int end_of_number = line.find(' ', 5);
        int pop_number = std::stoi(line.substr(5, end_of_number-5));
        int next_number = line.find(' ', end_of_number+1) + 1;
        end_of_number = line.find(' ', next_number);
        int origin_stack = std::stoi(line.substr(next_number, end_of_number-next_number));
        next_number = line.find(' ', end_of_number+1) + 1;
        int destination_stack = std::stoi(line.substr(next_number, 8));

        // Perform operation
        stack_dict[destination_stack].add_from_string(stack_dict[origin_stack].pop_several(pop_number));
    }
    for (int i=1; i < 10; i++)
    {
        std::cout << stack_dict[i].peek() << "";
    }
    std::cout << std::endl;

}