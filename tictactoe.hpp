#ifndef TICTACTOE
#define TICTACTOE

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Game {
    
public:
    // Default Constructor
    Game();
    // Constructor
    Game(std::string player1Name_in, std::string player2Name_in);

    // Broader game
    void play(); 

private:
    /* Helper Functions: */
    // Prints the board
    void boardPrint(); 

    // Update the board when the player makes a move, 
    void boardUpdate(int currentPlayer, int row, int col); 
    
     // 1 or 2 If someone won, -1 if draw, 0 if still going;
    int gameOver();

    // Procedure if game ended (print winner)
    void gameEnd(int roundOutcome); 

    // Returns player # that won if 3 in a row, or 0 if no win
    int checkRow(); 

    // Returns player # that won if 3 in a col, or 0 if no win
    int checkCol(); 

    // Returns player # that won if 3 in a diagonal, or 0 if no win
    int checkDiagonal(); 

    /* Member Variables */
    char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
    int round;
    std::map<char, int> placementToPlayer;
    std::string player1_name;
    std::string player2_name;    
};

#endif