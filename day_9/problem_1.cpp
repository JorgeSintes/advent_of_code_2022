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
    Knot head;
    Knot tail;

    char direction;
    int steps;
    while(getline(file_input, line)) {
        direction = line[0];
        steps = std::stoi(line.substr(2, line.length()));
        for (int i = 0; i < steps; i++) {
                if (direction == 'L') {
                    head.left();
                }
                if (direction == 'R') {
                    head.right();
                }
                if (direction == 'U') {
                    head.up();
                }
                if (direction == 'D') {
                    head.down();
                }
                tail.follow(head);
                tail.mark_place();
        }
    }
    std::cout << tail.visited_places.size() << std::endl;
}