//
//  player.h
//  FinalProject.cpp
//
//  Created by Dennis Frenkel on 12/4/23.
//

#ifndef player_h
#define player_h
#include <string>

using namespace std;

class Player {
public:
    // Default constructor
    Player();
    int getWins() const // used for the tie case (I wasnt sure how to do it another way)
    {
        return wins;
    }

    // Mutator and accessor for the name member variable
    void setName(const string& playerName);
    string getName() const;

    // Method to get the guess for the game
    virtual int getGuess() const;
    
    // Method called when the user enters the wrong guess
    void wrongGuess(int guess, int answer) const;

    // Method to end the round, taking a bool argument indicating if the player won
    void endRound(bool hasWon);

    // Operator overloaded functions
    bool operator>(const Player& other) const;
    friend ostream& operator<<(ostream& os, const Player& player);

private:
    string name;
    int wins;
};


#endif /* player_h */
