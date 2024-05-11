#include "tictactoe-engine.hpp"
#include <iostream>

using namespace std;

void GameVisual::load_visuals() {
    // Load images & error checking:
    if (!X_image.loadFromFile("resources/X.png")) {
        std::cout << "File loading error for X_image\n";
        return;
    }
    if (!O_image.loadFromFile("resources/O.png")) {
        std::cout << "File loading error for O_image\n";
        return;
    }
    if (!board_image.loadFromFile("resources/board.png")) {
        std::cout << "File loading error for board_image\n";
        return ;
    }

    // Load textures & error checking:
    if (!X_texture.loadFromImage(X_image)) {
        std::cout << "Error loading X texture\n";
        return;
    }
    if (!O_texture.loadFromImage(O_image)) {
        std::cout << "Error loading O texture\n";
        return;
    }
    if (!board_texture.loadFromImage(board_image)) {
        std::cout << "Error loading board texture\n";
        return;
    }

    // Load font
    if (!font.loadFromFile("resources/Arial.ttf")) {
        std::cout << "Error loading font\n";
        return;
    }
    text.setFont(font);
}

void GameVisual::play_game(sf::Vector2f mousePosition) {
    while (!this->gameResult()) {
        play_turn(mousePosition);
    }
}

void GameVisual::play_turn(sf::Vector2f mousePosition) {
    // Display whose turn it is
    text.setString(msg);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);

    sf::Sprite currPiece;
    if (currentPlayer == 1) {
        currPiece.setTexture(X_texture);
    } else if (currentPlayer == 2) {
        currPiece.setTexture(O_texture);
    }


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        currPiece.setPosition(mousePosition);
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else if (currentPlayer == 2) {
        currentPlayer = 1;
    }
}