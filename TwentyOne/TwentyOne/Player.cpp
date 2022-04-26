#include "Player.h"

Player::Player(const std::string& name) : GenericPlayer(name){}
Player::~Player() = default;
bool Player::needMore() const {
    std::cout << name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
void Player::win() const {
    std::cout << name << " wins!\n";
}
void Player::lose() const {
    std::cout << name << " loses!\n";
}
void Player::draw() const {
    std::cout << name << " is draw!\n";
}