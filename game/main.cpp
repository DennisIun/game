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

#define USER_TURN 1         // User turn to play
#define COMPUTER_TURN 2     // Computer turn to play

char board[MAX_BOARD_ROW][MAX_BOARD_COL] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};

/*
 Funcition: display_board()
 Description: Display the tac-toc-tao board which is stored in global variable char board[3][3];
 */
int display_board(const char board[][MAX_BOARD_COL]){
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

/*
 Function: update_board_with_input(char* board, const int input_box, const char display_char)
 Descirption: Update the board content at the input_box location with the display_char
 Input args:
    board - board array to update
    input_box - location to update
    display_char - update to this char at location input_box
 Return code:
    1 - Successful
    0 - Failure
 */
int update_board_with_input(char board[][MAX_BOARD_COL], const int input_box, const char display_char){
    // Step 1: check if input_box is between 1 and 9
    // Step 2: check if input_box is taken by 'X' or 'O'
    // Step 3: if not taken, update with display_char
    // return 0 if there is any error
    return 0;
}

/*
 Function: computer_select_a_box(char board[][MAX_BOARD_COL], const char display_char
 Descirption: Calculate which box the computer will take
 Input args:
    board - board array to update
    display_char - char that represent the computer move. Shoudl be 'O'
 Return code:
    1 - Selected a box
    0 - Something failed
 */
int computer_select_a_box(char board[][MAX_BOARD_COL], const char display_char){
    return 1;
}

/*
 Function: check_who_wins(const char board[][MAX_BOARD_COL], char& who_win)
 Descirption: Check if anyone wins the game
 Input args:
    board - board array to update
 Output args:
    who_win - 'X' or 'O';
 Return code:
    1 - Someone wins
    0 - Noone wins
 */
int check_who_wins(const char board[][MAX_BOARD_COL], char& who_win){
    who_win = 'X';
    return 1;
}

int main(int argc, const char * argv[]) {
    int input_box = 0; // Input from the user
    int rc = 0; // function return code
    char wins = '?'; // Who wins
    int number_of_box_selected = 0;
    int whos_turn = USER_TURN;
    
    cout << "Hello. Welcome to Tic Tok Tod. \n You are X and I am O \n You go first \n";
    display_board(board);
    do {
        if (whos_turn == USER_TURN){
            // User turn to move
            cout << "Please select the box you want to take (1 to 9): ";
            cin >> input_box;
            rc = update_board_with_input(board, input_box, 'X');
            if (rc == 0){
                cout << "Invalid input. Pleae try again \n";
                continue;
            }
        } else {
            // Computer turn to move
            cout << "Ok. My turn...\n Thinking ....\n";
            rc = computer_select_a_box(board, 'O');
            if (rc == 0){
                cout << "Something wrong. Let me think again. \n";
                continue;
            }
        }
        display_board(board);
        rc = check_who_wins(board, wins);
        if (rc) {
            cout << wins << " wins! \n";
            break;
        }
        whos_turn = (whos_turn == USER_TURN) ? COMPUTER_TURN : USER_TURN; // swap the turn
        number_of_box_selected++;
    } while (number_of_box_selected < MAX_BOARD_ROW * MAX_BOARD_COL);
    if (wins == '?'){
        cout << "It is a tie. \n";
    }
    return 0;
}
