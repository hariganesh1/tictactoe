#include "tictactoe.hpp"

Game::Game() {
    player1_name = "Player 1";
    player2_name = "Player 2";
    round = 1;
};

Game::Game(std::string player1Name_in, std::string player2Name_in) {
        player1_name = player1Name_in;
        player2_name = player2Name_in;
        round = 1;
        placementToPlayer['X'] = 1;
        placementToPlayer['O'] = 2;
    };

void Game::play()
{
    std::cout << "Welcome to Tic Tac Toe! Input Player 1 and Player 2's name below:\n"
              << "In the following format: ~Name Name~ (Eg. Bob Jeff) --> Player 1: "
              << "Bob, Player 2: Jeff\n";
    int currPlayerTurn = 1;
    while (!gameOver())
    {
        std::cout << "It's Round: " << round << " Here is the current board:\n";
        std::cout << "GameOver?: " << gameOver() << std::endl;
        
        boardPrint();
        int row;
        int col;
        std::cout << "It's Player " << currPlayerTurn << "'s Turn, Input where"
                  << " you'd like to place an X in the following format: row"
                  << " col (eg. 0 1 for top middle)\n";
        std::cin >> row >> col;
        boardUpdate(currPlayerTurn, row, col); // Play move
        ++round;
        if (currPlayerTurn == 1)
        { // Update who's turn it is
            currPlayerTurn = 2;
        }
        else
        {
            currPlayerTurn = 1;
        }
    }
    if (this->gameOver())
    {
        this->boardPrint();
        this->gameEnd(gameOver());
    }
}

void Game::boardPrint()
{
    std::cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
    std::cout << "X's are Player 1's current placements. O's are Player 2's current "
              << "placements. Spaces are free spots available for placement.\n";
}

void Game::boardUpdate(int currentPlayer, int row, int col)
{
    if (board[row][col] != ' ') // If the spot is already taken
    {
        std::cout << "Error: Cannot place there, there's already an " << board[row][col]
                  << " there, choose a different row and column in the format row col "
                  << "(eg. 0 1 for top middle)\n";
        int row;
        int col;
        std::cin >> row >> col;
        boardUpdate(currentPlayer, row, col);
    }
    else // Update board accordingly
    {
        if (currentPlayer == 1)
        {
            board[row][col] = 'X';
        }
        else if (currentPlayer == 2)
        {
            board[row][col] = 'O';
        }
    }
}

int Game::gameOver()
{
    if (checkRow())
    {
        return checkRow();
    }
    else if (checkCol())
    {
        return checkCol();
    }
    else if (checkDiagonal())
    {
        return checkDiagonal();
    }
    else if (round == 9)
    {
        return 3; // Draw
    }
    else
    {
        return 0; // Round not over
    }
}

void Game::gameEnd(int roundOutcome)
{
    std::cout << "Game Over!\n";
    if (roundOutcome == 1)
    {
        std::cout << "Player 1, " << player1_name << " (X) Wins!\n";
    }
    else if (roundOutcome == 2)
    {
        std::cout << "Player 2, " << player2_name << " (O) Wins!\n";
    }
    else if (roundOutcome == 3)
    {
        std::cout << "It's a Tie!\n";
    }
}

int Game::checkRow()
{
    for (int row = 0; row < 3; row++)
    { // Check every row
        if ((board[row][0] == board[row][1]) && (board[row][0] == board[row][2]) && 
            ((board[row][0] != ' ')))
        {
            return placementToPlayer[board[row][0]];
        }
    }
    return 0; // Return 0 if no three in a row
}

int Game::checkCol()
{
    for (int col = 0; col < 3; col++)
    { // Check every col
        if ((board[0][col] == board[1][col]) && (board[0][col] == board[2][col]) && 
            ((board[0][col] != ' ')))
        {
            return placementToPlayer[board[0][col]];
        }
    }
    return 0; // Return 0 if no three in a col
}

int Game::checkDiagonal()
{
    if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) &&
        ((board[0][0] != ' ')))
    { // Check top left to bottom right
        return placementToPlayer[board[0][0]];
    }
    else if ((board[2][0] == board[1][1]) && (board[2][0] == board[0][2]) &&
        ((board[2][0] != ' ') && (board[1][1] != ' ') && (board[0][2] != ' ')))
    { // Check top right to bottom left
        return placementToPlayer[board[2][0]];
    }
    return 0; // Return 0 if no three in a diag
}