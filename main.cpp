// Dennis Frenkel
// main.cpp


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

using namespace std;

// Function declarations
void play(Player& player1, Player& player2);
bool checkForWin(Player& player, int answer);
void outputGameStats(const Player& player1, const Player& player2);

int main()
{
    // random number generation
    srand(time(0));

    int numPlayers;
    Player* p1, * p2;

    // Initializes the players
    HumanPlayer h1("Player 1"), h2("Player 2");
    ComputerPlayer c1("CPU 1"), c2("CPU 2");

    char playAgain;

    // Loop for gameplay
    do
    {
        // Determine the number of players using user input in a do-while loop
        do
        {
            cout << "How many human players (0, 1, or 2): ";
            cin >> numPlayers;

            // Play with two computer players
            if (numPlayers == 0)
            {
                ComputerPlayer c1("CPU 1");
                ComputerPlayer c2("CPU 2");
                play(c1, c2);
                p1 = &c1;
                p2 = &c2;
            }
            // Play with one human and one computer player
            else if (numPlayers == 1)
            {
                play(h1, c1);
                outputGameStats(h1, c1);
                p1 = &h1;
                p2 = &c1;
            }
            // Play with two human players
            else if (numPlayers == 2)
            {
                HumanPlayer h2("Player 2");
                play(h1, h2);
                outputGameStats(h1, h2);
                p1 = &h1;
                p2 = &h2;
            }
            else
            {
                cout << "Invalid input. Please enter 0, 1, or 2." << endl;
            }
        } while (numPlayers < 0 || numPlayers > 2);

        do
        {
            // Ask the user if they want to play again
            cout << "Would you like to play again? (Y/N): ";
            cin >> playAgain;
            if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n')
            {
                cout << "Invalid input. Please enter Y or N." << endl;
            }
        } while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');

        cout << endl;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

void play(Player& player1, Player& player2)
{
    int answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess. ";
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        cout << "Congratulations, " << player.getName() << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}

void outputGameStats(const Player& player1, const Player& player2)
{
    cout << "Final Results:" << endl;
    cout << player1 << endl;
    cout << player2 << endl;

    if (player1.getWins() == player2.getWins())
    {
        cout << "It's a tie!" << endl;
    }
}

