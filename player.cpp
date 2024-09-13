//
//  player.cpp
//  FinalProject.cpp
//
//  Created by Dennis Frenkel on 12/4/23.
//
#include "player.h"
#include <iostream>


using namespace std;


// Default constructor
Player::Player() : wins(0) {}

// Mutator and accessor for the name member variable
void Player::setName(const string& playerName) 
{
    name = playerName;
}

string Player::getName() const 
{
    return name;
}

// Method to get the guess for the game
int Player::getGuess() const 
{
    return 0; // Default
}

// Method called when the user enters the wrong guess
// Tells the user if the guess is too high or too low compared to the answer
void Player::wrongGuess(int guess, int answer) const 
{
    if (guess > answer) 
    {
        cout << "Your guess is too high." << endl;
    } else 
    {
        cout << "Your guess is too low." << endl;
    }
}

// This method ends the round
// This function is called at the end of each round to update the player's wins
void Player::endRound(bool hasWon) {
    if (hasWon) {
        wins++;
    }
}

// Operator overloaded function for comparison
bool Player::operator>(const Player& other) const {
    return wins > other.wins;
}
// Operator overloaded function for output stream
ostream& operator<<(ostream& os, const Player& player) {
    os << player.name << "\n" << "Number of win(s): " << player.wins;
    return os;
}

