//
//  computerPlayer.cpp



#include "computerPlayer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
// Default constructor
ComputerPlayer::ComputerPlayer() 
{
    resetRNG();
}

// Custom constructor
ComputerPlayer::ComputerPlayer(const string& playerName) : Player(), rngStart(0), rngRange(100)
{
    setName(playerName);
}

// Resets range variables
void ComputerPlayer::resetRNG() 
{
    rngStart = 0;
    rngRange = 100;
}

// Override the base class method for the range
int ComputerPlayer::getGuess() const
{
    return rand() % rngRange + rngStart;
}

// Override the base class method for wrong guesses
void ComputerPlayer::wrongGuess(int guess, int answer)
{
    Player::wrongGuess(guess, answer);

    if (guess > answer) 
    {
        shiftRangeDown(guess);
    } else 
    {
        shiftRangeUp(guess);
    }
}

// shifts RNG range down based on the wrong guess
void ComputerPlayer::shiftRangeDown(int guess) 
{
    rngRange = guess - rngStart;
}

// shifts the RNG range up based on the wrong guess
void ComputerPlayer::shiftRangeUp(int guess)
{
    rngStart = guess + 1;
    rngRange = rngRange - (rngStart - guess);
}
