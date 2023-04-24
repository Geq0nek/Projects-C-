#include <iostream>

int grid[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,7,9,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

bool numberInColumn(int column, int number) {
    for(int row = 0; row < 9; row++){
        if(grid[row][column] == number)
            return true;
    }

    return false;
}

bool numberInRow(int row, int number){
    for(int column = 0; column < 9; column++){
        if(grid[row][column] == number)
            return true;
    }

    return false;
}

bool numberInSmallBox(int boxStartRow, int boxStartColumn, int number){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(grid[boxStartRow + row][boxStartColumn + column] == number){
                return true;
            }
        }
    }

    return false;
}

bool findEmptyPlace(int& row, int& column){
    for(row = 0; row < 9; row++){
        for(column = 0; column < 9; column++){
            if(grid[row][column] == 0)
                return true;
        }
    }

    return false;
}

bool validCell(int row, int column, int number){
    return !numberInRow(row, number) && !numberInColumn(column, number) && !numberInSmallBox(row - row%3 ,column - column%3, number);
}

bool solveSudoku(){
    int row, column;

    if(!findEmptyPlace(row, column))
        return true;

    for (int number = 1; number <= 9; number++){ 
      if (validCell(row, column, number)){ 
         grid[row][column] = number;
         if (solveSudoku()) 
            return true;
         grid[row][column] = 0; 
      }
   }
   return false;
}

void displayGrid(){
    for(int row = 0; row < 9; row++){
        for(int column = 0 ; column < 9; column++){
            std::cout << grid[row][column];
        }
        std::cout << std::endl;
    }
}

int main(){

    if(solveSudoku() == true)
        displayGrid();
    else 
        std::cout << "There is no solution for this sudoku" << std::endl;

    return 1;
}