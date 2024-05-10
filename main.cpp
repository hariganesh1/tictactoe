#include "tictactoe.hpp"

int main(int argc, char **argv)
{
    if (argc == 0) { // Default 
        Game tictactoe = Game();
        tictactoe.play();
    } else if (argc != 3) { // Incorrect usage
        std::cout << "Usage: ./main.exe PLAYER_1_NAME PLAYER_2_NAME"
                  << "EG. ./main.exe BOB JEFF\n";
        return 1;
    }
    
    std::string player1_name = static_cast<std::string>(argv[1]);
    std::string player2_name = static_cast<std::string>(argv[2]);
    // Play game
    Game tictactoe = Game(player1_name, player2_name);
    tictactoe.play();

    return 0;
}
