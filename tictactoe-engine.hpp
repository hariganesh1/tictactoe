#include <SFML/Graphics.hpp>
#include <iostream>

class GameVisual {
public:
    // Load X's and O's and board
    void load_visuals();

    // Broader play game function
    void play_game(sf::Vector2f mousePosition);

    // Play each individual turn
    void play_turn(sf::Vector2f mousePosition);

private:
/* Private Helper Functions */

    // Returns 1 if P1 won, 2 if P2 won, 0 if still going, -1 if draw
    int gameResult();

/* Private Member Variables */
    // VISUALS:
    sf::Image X_image;
    sf::Texture X_texture;
    sf::Image O_image;
    sf::Texture O_texture;
    sf::Image board_image; // Specifically the grid
    sf::Texture board_texture;
    sf::Font font;
    sf::Text text;
    std::string msg;

    // Other stuff
    int currentPlayer; // X = 1, O = 2
};