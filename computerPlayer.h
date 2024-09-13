//
//  computerPlayer.h
//  FinalProject.cpp
//
//  Created by Dennis Frenkel on 12/4/23.
//

#ifndef computerPlayer_h
#define computerPlayer_h
#include "player.h"

using namespace std; 
class ComputerPlayer : public Player {
public:
    // Default constructor
    ComputerPlayer();

    // Custom constructor
    ComputerPlayer(const string& playerName);

    // Resets RNG variables
    void resetRNG();

    // Overrides the base class method to getGuess
    int getGuess() const override;

    // Overrides the base class method for wrongGuess
    void wrongGuess(int guess, int answer);

private:
    int rngStart;
    int rngRange;

    // shifts the RNG range based on the wrong guess
    void shiftRangeDown(int guess);
    void shiftRangeUp(int guess);
};



#endif /* computerPlayer_h */
