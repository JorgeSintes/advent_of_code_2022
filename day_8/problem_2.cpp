#include <fstream>
#include <iostream>

int scenic_score(int** array, int x, int y, int no_rows, int no_cols)
{
    int val = array[x][y];
    int score_up, score_down, score_left, score_right;
    bool encountered_tree = false;

    for (int i = x-1; i > 0; i--) { // Check up
        if (array[i][y] >= val) {
            score_up = x-i;
            encountered_tree = true;
            break;
        }
    }
    if (!encountered_tree) {
        score_up = x;
    }
    encountered_tree = false;
            
    for (int i = x+1; i < no_cols; i++) { // Check down
        if (array[i][y] >= val) {
            score_down = i-x;
            encountered_tree = true;
            break;
        }
    }
    if (!encountered_tree) {
        score_down = no_cols - x - 1;
    }
    encountered_tree = false;

    for (int j = y-1; j > 0; j--) { // Check left
        if (array[x][j] >= val) {
            score_left = y - j;
            encountered_tree = true;
            break;
        }
    }
    if (!encountered_tree) {
        score_left = y;
    }
    encountered_tree = false;

    for (int j = y+1; j < no_cols; j++) { //Check right
        if (array[x][j] >= val) {
            score_right = j - y;
            encountered_tree = true;
            break;
        }
    }
    if (!encountered_tree) {
        score_right = no_rows - y - 1;
    }
    encountered_tree = false;

    return score_up * score_down * score_left * score_right;
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
    int score = 0;
    int max_scenic_score = 0;

    // std::cout << array[1][3] << std::endl;
    // std::cout << is_visible(array, 1, 3, no_rows, no_cols) << std::endl;
    for (int i=1; i < no_rows-1; i++) {
        for (int j=1; j < no_cols-1; j++) {
            score = scenic_score(array, i, j, no_rows, no_cols);
            if (score > max_scenic_score) {
                max_scenic_score = score;
            }
        }
    }
    std::cout << max_scenic_score << std::endl;
}
