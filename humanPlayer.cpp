//
//  humanPlayer.cpp

#include "humanPlayer.h"
#include <iostream>

using namespace std;

// Default constructor
HumanPlayer::HumanPlayer() {}

// Custom constructor
HumanPlayer::HumanPlayer(const string& playerName)
{
    setName(playerName);
}

int HumanPlayer::getGuess() const 
{
    int guess;

    if (!(cin >> guess))
    {
        cout << "Invalid input. Please enter a number between 0 and 99." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        // Discards invalid input
    }
    else if (guess < 0 || guess > 99)
    {
        cout << "Invalid guess. Please enter a number between 0 and 99." << endl;
    }
    return guess;
}
