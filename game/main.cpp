//
//  main.cpp
//  game
//
//  Created by Dennis Iun on 1/2/2023.
//

#include <iostream>
using namespace std;

#define MAX_BOARD_ROW 3     // Maximum board row size
#define MAX_BOARD_COL 3     // Maximum board column size

char board[MAX_BOARD_ROW][MAX_BOARD_COL] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};

/*
 Funcition: display_board()
 Description: Display the tac-toc-tao board which is stored in global variable char board[3][3];
 */
int display_board(char board[][MAX_BOARD_COL], int max_board_row, int max_board_col){
    for (int x = 0; x < max_board_row; x++){
        cout << " ";
        for (int y = 0; y < max_board_col; y++){
            cout << board [x][y];
            if (y != (max_board_col-1)) {    // Don't need to print for the last column
                cout << " | ";
            }
        }
        if ((x != (max_board_row-1))){      // Don't need to print for the last row
            cout << endl << "---|---|---" << endl;
        }
    }
    cout << endl;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    display_board(board, MAX_BOARD_ROW, MAX_BOARD_COL);
    return 0;
}
