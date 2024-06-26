#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

// Structure to hold the details of each game round
struct GameRound {
    string player1Move;
    string player2Move;
    string result;
};

// Function to display the game menu
void displayMenu() {
    cout << "\n=== Rock-Paper-Scissors Game ===\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "4. View Scores\n";
    cout << "5. View History\n";
    cout << "6. Reset Scores and History\n";
    cout << "Enter your choice (1-6): ";
}

// Function to convert numeric choice to string representation of the move
string getChoice(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid Choice";
    }
}

// Function to determine the winner of the game round
int determineWinner(int player1Choice, int player2Choice) {
    if (player1Choice == player2Choice) {
        return 0; // Tie
    } else if ((player1Choice == 1 && player2Choice == 3) ||
               (player1Choice == 2 && player2Choice == 1) ||
               (player1Choice == 3 && player2Choice == 2)) {
        return 1; // Player 1 wins
    } else {
        return -1; // Player 2 wins
    }
}

// Function to display the current scores
void displayScores(map<string, int> scores) {
    cout << "\n=== Scores ===\n";
    cout << "Player 1: " << scores["Player 1"] << "\n";
    cout << "Player 2: " << scores["Player 2"] << "\n";
}

// Function to display the game history
void displayHistory(list<GameRound> history) {
    cout << "\n=== Game History ===\n";
    if (history.empty()) {
        cout << "No game history available.\n";
    } else {
        for (const auto& round : history) {
            cout << "Player 1 chose: " << round.player1Move 
                 << ", Player 2 chose: " << round.player2Move 
                 << " => " << round.result << "\n";
        }
    }
}

// Function to display game statistics
void displayStatistics(map<string, int> scores, int totalRounds) {
    cout << "\n=== Statistics ===\n";
    cout << "Total Rounds Played: " << totalRounds << "\n";
    cout << "Player 1 Win Percentage: " << (totalRounds > 0 ? (scores["Player 1"] * 100.0 / totalRounds) : 0) << "%\n";
    cout << "Player 2 Win Percentage: " << (totalRounds > 0 ? (scores["Player 2"] * 100.0 / totalRounds) : 0) << "%\n";
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    int playerChoice, player2Choice;
    char playAgain;
    map<string, int> scores = {{"Player 1", 0}, {"Player 2", 0}};
    list<GameRound> history;
    int totalRounds = 0;
    int winStreak = 0;
    int longestWinStreak = 0;
    bool playWithComputer = true;
    string player1Name = "Player 1", player2Name = "Player 2";

    // Ask if the user wants to play with computer or another player
    cout << "\nDo you want to play with the computer or with another player?\n";
    cout << "1. Play with Computer\n";
    cout << "2. Play with Another Player\n";
    cout << "Enter your choice (1-2): ";
    int gameMode;
    cin >> gameMode;
    if (gameMode == 2) {
        playWithComputer = false;
        cout << "Enter Player 1's name: ";
        cin >> player1Name;
        cout << "Enter Player 2's name: ";
        cin >> player2Name;
        cout << "Let's start the game!\n";
    }

    do {
        displayMenu();
        cin >> playerChoice;

        if (playerChoice == 4) {
            displayScores(scores);
            displayStatistics(scores, totalRounds);
            continue;
        } else if (playerChoice == 5) {
            displayHistory(history);
            continue;
        } else if (playerChoice == 6) {
            scores = {{"Player 1", 0}, {"Player 2", 0}};
            history.clear();
            totalRounds = 0;
            winStreak = 0;
            longestWinStreak = 0;
            cout << "\nScores and history have been reset.\n";
            continue;
        } else if (playerChoice < 1 || playerChoice > 3) {
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }

        if (playWithComputer) {
            player2Choice = rand() % 3 + 1;
            cout << "\nYou chose: " << getChoice(playerChoice) << "\n";
            cout << "Computer chose: " << getChoice(player2Choice) << "\n";
        } else {
            // Player vs Player mode
            cout << player1Name << " chose: " << getChoice(playerChoice) << "\n";
            cout << player2Name << ", enter your choice (1-3): ";
            cin >> player2Choice;
            if (player2Choice < 1 || player2Choice > 3) {
                cout << "\nInvalid choice. Please enter a number between 1 and 3.\n";
                continue;
            }
            cout << player2Name << " chose: " << getChoice(player2Choice) << "\n";
        }

        int result = determineWinner(playerChoice, player2Choice);
        string resultStr;
        totalRounds++;
        if (result == 0) {
            resultStr = "It's a tie!";
            winStreak = 0;
        } else if (result == 1) {
            resultStr = player1Name + " wins!";
            scores["Player 1"]++;
            winStreak++;
            longestWinStreak = max(longestWinStreak, winStreak);
        } else {
            resultStr = player2Name + " wins!";
            scores["Player 2"]++;
            winStreak = 0;
        }
        cout << resultStr << "\n";

        history.push_back({getChoice(playerChoice), getChoice(player2Choice), resultStr});

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}
