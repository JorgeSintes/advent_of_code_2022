#include <fstream>
#include <iostream>

bool is_visible(int** array, int x, int y, int no_rows, int no_cols)
{
    int val = array[x][y];
    int not_visible = 0;

    for (int i = 0; i < x; i++) { // Check up
        if (array[i][y] >= val) {
            not_visible++;
            break;
        }
    }
    for (int i = x+1; i < no_cols; i++) { // Check down
        if (array[i][y] >= val) {
            not_visible++;
            break;
        }
    }
    for (int j = 0; j < y; j++) { // Check left
        if (array[x][j] >= val) {
            not_visible++;
            break;
        }
    }
    for (int j = y+1; j < no_cols; j++) { //Check right
        if (array[x][j] >= val) {
            not_visible++;
            break;
        }
    }
    if (not_visible == 4) {
        return false;
    }

    return true;
}

int main()
{
    std::string line;
    std::fstream input_file("input");
    std::getline(input_file, line);
    int no_cols = line.length();

    int* array[no_cols];
    int i = 0;

    while(true) {
        array[i] = (int*)malloc(no_cols*sizeof(int));
        for (int j = 0; j < no_cols; j++) {
            array[i][j] = line[j] - '0';
        }
        i++;
        if (!getline(input_file, line))
        {
            break;
        }
    }
    
    int no_rows = i;
    int visible_trees = no_cols*2 + (no_rows-2)*2;

    for (int i=1; i < no_rows-1; i++) {
        for (int j=1; j < no_cols-1; j++) {
            if (is_visible(array, i, j, no_rows, no_cols)) {
                visible_trees++;
            }
        }
    }
    std::cout << visible_trees << std::endl;
}