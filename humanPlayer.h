//
//  humanPlayer.h


#ifndef humanPlayer_h
#define humanPlayer_h
#include "player.h"

using namespace std;

class HumanPlayer : public Player 
{
public:
    // Default constructor
    HumanPlayer();

    // Custom constructor
    HumanPlayer(const string& playerName);
    
    // Overrides the base class method to get the guess from user
    int getGuess() const override;
};


#endif /* humanPlayer_h */
