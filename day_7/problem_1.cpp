#include <fstream>
#include <iostream>
#include <vector>

static int total_value=0;

class NonBinTree{
    public:
    int value = 0;
    int valid_dirs = 0;
    std::string name;
    std::vector<NonBinTree*> child_nodes;
    NonBinTree* parent;

    NonBinTree(std::string given_name, NonBinTree* given_parent) {
        name = given_name;
        parent = given_parent;
    }

    NonBinTree* get_parent() {
        return parent;
    }

    void add_child_node(std::string node_name) {
        // NonBinTree new_node(node_name, this);
        NonBinTree* new_node = new NonBinTree(node_name, this);
        child_nodes.push_back(new_node);
    }

    NonBinTree* get_child(int index) {
        return child_nodes[index];
    }

    int get_value() {
        int node_value = value;
        for (int i = 0; i < child_nodes.size(); i++) {
            node_value += child_nodes[i]->get_value();
        }
        if (node_value <= 100000) {
            total_value += node_value;
        }
        return node_value;
    }
};

int main() {
    std::fstream input_file("input");
    std::string line;

    std::getline(input_file, line);
    NonBinTree root("parent", NULL);
    NonBinTree* node = &root;

    while(std::getline(input_file, line)) {
        if (line.substr(0,4) == "$ cd") {
            std::string change_dir = line.substr(5, line.length());
            if (change_dir == "..") {
                node = node->get_parent();
            }
            else {
                for (int i = 0; i < node->child_nodes.size(); i++) {
                    if (node->child_nodes[i]->name == change_dir) {
                        node = node->child_nodes[i];
                        break;
                    }
                }
            }
        }

        else if (line[0] != '$') {
            int separator = line.find(' ');
            std::string first_part = line.substr(0,separator);
            if (first_part == "dir") {
                std::string second_part = line.substr(separator+1,line.length());
                node->add_child_node(second_part);
            }
            else {
                node->value += std::stoi(first_part);
            }
        }
    }
    std::cout << "Total space used: " << root.get_value() << std::endl;
    std::cout << "Solution: " << total_value << std::endl;
}