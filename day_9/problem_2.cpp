#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class Knot {
    public:
        int x = 0;
        int y = 0;
        std::vector<std::vector<int>> visited_places;

        void left() {x --;}
        void right() {x ++;}
        void down() {y --;}
        void up() {y ++;}

        void follow(Knot& head) {

            if ((std::abs(head.x - x) == 2) && (head.y - y == 0)) { // Move left or right same row
                if (head.x > x) {
                    x++;
                }
                else {
                    x--;
                }
            }
            if ((std::abs(head.y - y) == 2) && (head.x - x == 0)) { // Move up or down same column
                if (head.y > y) {
                    y++;
                }
                else {
                    y--;
                }
            }
            if (((std::abs(head.x - x) == 2) && (std::abs(head.y - y) == 1)) || ((std::abs(head.x - x) == 1) && (std::abs(head.y - y) == 2)) ) { // Move diagonally
                if (head.x > x) {
                    x++;
                }
                else {
                    x--;
                }
                if (head.y > y) {
                    y++;
                }
                else {
                    y--;
                }
            }
            if (((std::abs(head.x - x) == 2) && (std::abs(head.y - y) == 2)) || ((std::abs(head.x - x) == 1) && (std::abs(head.y - y) == 2)) ) { // Move diagonally
                if (head.x > x) {
                    x++;
                }
                else {
                    x--;
                }
                if (head.y > y) {
                    y++;
                }
                else {
                    y--;
                }
            }

        }

        void mark_place() {
            std::vector<int> pos = {x,y};
            bool visited = false;
            for (int i = 0; i < visited_places.size(); i++) {
                if ((visited_places[i][0] == pos[0]) && (visited_places[i][1] == pos[1])) {
                    visited = true;
                    break;
                }
            }
            if (!visited) {
                visited_places.push_back(pos);
            }
        }

        Knot() {
            mark_place();
        }
};

int main()
{
    std::fstream file_input("input");
    std::string line;
    Knot rope[10];

    char direction;
    int steps;
    while(getline(file_input, line)) {
        direction = line[0];
        steps = std::stoi(line.substr(2, line.length()));
        std::cout << direction << ", " << steps << std::endl;
        for (int i = 0; i < steps; i++) {
                if (direction == 'L') {
                    rope[0].left();
                }
                if (direction == 'R') {
                    rope[0].right();
                }
                if (direction == 'U') {
                    rope[0].up();
                }
                if (direction == 'D') {
                    rope[0].down();
                }
                for (int j = 1; j < 10; j++){
                    rope[j].follow(rope[j-1]);
                }
                rope[9].mark_place();
        }
    }
    std::cout << rope[9].visited_places.size() << std::endl;
}