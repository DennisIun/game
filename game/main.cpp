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
int display_board(void){
    for (int x = 0; x < MAX_BOARD_ROW; x++){
        cout << " ";
        for (int y = 0; y < MAX_BOARD_COL; y++){
            cout << board [x][y];
            if (y != (MAX_BOARD_COL-1)) {    // Don't need to print for the last column
                cout << " | ";
            }
        }
        if ((x != (MAX_BOARD_ROW-1))){      // Don't need to print for the last row
            cout << endl << "---|---|---" << endl;
        }
    }
    cout << endl;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    display_board();
    return 0;
}
