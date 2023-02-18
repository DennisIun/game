//
//  main.cpp
//  game-for-number-guessing
//
//  Created by Dennis Iun on 1/2/2023.
//  Adapted from orginal game projet to show reusing of
//  functions and program structure
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM_DIGITS 4    // Maximum number of digits for guessing

#define USER_TURN 1         // User turn to play
#define COMPUTER_TURN 2     // Computer turn to play

#define BOARD_ANSWER    0   // Answer digit is stored in the first position in board
#define BOARD_INPUT     1   // Input digit is stored in the 2nd position in board

/*
 Funcition: display_board()
 Description: Display the tac-toc-tao board which is stored in global variable char board[3][3];
 */
int display_board(const vector<int> board, const int numA, const int numB){
    cout << numA << "A " << numB << "B" << endl;
    cout << "   A is correct value and location \n   B is correct value but wrong location \n";
    return 1;
}

/*
 Function: update_board_with_input()
 Descirption: check if the input is valid
 Input args:
    board - board array to update
    input_box - location to update
 Return code:
    1 - Successful
    0 - Failure
 */
int update_board_with_input(vector<int> board, const int input_box, int *numA, int *numB){
    // Step 1: check if input_box is within range
    
    // Step 2: Calculate and update A & B values then update the value via the pointers
    
    return 1;
}

/*
 Function: computer_select_a_box()
 Descirption: This function is not used in this game
 Input args:
    board - board array to update
 Return code:
    1 - Selected a box
    0 - Something failed
 */
int computer_select_a_box(vector<int> answers_num){
    return 1;
}

/*
 Function: check_who_wins()
 Descirption: Check if anyone wins the game
 Input args:
    board - board
 Output args:
    who_win ;
 Return code:
    1 - Someone wins
    0 - Noone wins
 */
int check_who_wins(const vector<int> board, int numA, int numB, char& who_win){
    
    if (numA == MAX_NUM_DIGITS){
        who_win = 'U';
        return 1;
    } else {
        return 0; // noone wins
    }
}

int initialize_game(vector<int> board){
    
    srand((unsigned)time(NULL)); // Seed the randomn number generator first
    
    
    for (int i = 0; i < MAX_NUM_DIGITS; i++){
        int answer_digit = rand() % 9;
        board.push_back(answer_digit);
    }
    
    return 1;
}


// The main funcition
// We tried to reuse the main skeleton as much as possible

int main(int argc, const char * argv[]) {

    vector<int> board;          // board stored the digits of the answers
    int displayA = 0;           // number of correct number and position
    int displayB = 0;           // number of correct number but wrong position

    int input_box = 0; // Input from the user
    int rc = 0; // function return code
    char wins = '?'; // Who wins
    int number_of_box_selected = 0;
    int whos_turn = USER_TURN;

    initialize_game(board);
    
    cout << "Hello. Welcome to number guessing. \n Please guess a " << MAX_NUM_DIGITS << " numbers. \n";
//    display_board(board);
    do {
        if (whos_turn == USER_TURN){
            // User turn to move
            cout << "Please input a number to guess: ";
            cin >> input_box;
            rc = update_board_with_input(board, input_box, &displayA, &displayB);
            if (rc == 0){
                cout << "Invalid input. Pleae try again \n";
                continue;
            }
        } else {
            // Computer turn to move
            cout << "Ok. My turn...\n Thinking ....\n";
            rc = computer_select_a_box(board);
            if (rc == 0){
                cout << "Something wrong. Let me think again. \n";
                continue;
            }
        }
        display_board(board, displayA, displayB);
        rc = check_who_wins(board, displayA, displayB, wins);
        if (rc) {
            cout << wins << " wins! \n";
            break;
        }
//        Comment out as there is no computer turn in this game
//        whos_turn = (whos_turn == USER_TURN) ? COMPUTER_TURN : USER_TURN; // swap the turn
        number_of_box_selected++;
    } while (number_of_box_selected < 100);
    if (wins == '?'){
        cout << "It is a tie. \n";
    }
    cout << "Program exiting. \n";
    return 0;
}
