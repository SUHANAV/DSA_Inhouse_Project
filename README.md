# Rock-Paper-Scissors Game

This is a simple console-based Rock-Paper-Scissors game written in C++. Players can either play against the computer or against another player. The game keeps track of scores and game history and provides various options for viewing and resetting this data.

## Features

- **Play against the computer or another player**: Choose to play against the computer or a friend.
- **Score tracking**: Keeps track of the number of wins for each player.
- **Game history**: Maintains a history of all game rounds.
- **Statistics**: Displays win percentages and total rounds played.
- **Reset functionality**: Reset scores and game history at any time.

## How to Play

1. **Choose Game Mode**: At the start, choose whether you want to play against the computer or another player.
2. **Make Your Move**: Enter your move by selecting a number from 1 to 3.
    - 1: Rock
    - 2: Paper
    - 3: Scissors
3. **View Results**: The game will display the moves of both players and the result of the round.
4. **Repeat or Exit**: Choose whether to play another round or exit the game.

## Menu Options

- **1, 2, 3**: Select Rock, Paper, or Scissors.
- **4**: View current scores.
- **5**: View game history.
- **6**: Reset scores and game history.


## Code Structure

- **`main`**: The entry point of the program. It initializes variables, displays the menu, and handles user input.
- **`displayMenu`**: Displays the game menu.
- **`getChoice`**: Converts a numeric choice to its corresponding string representation (Rock, Paper, or Scissors).
- **`determineWinner`**: Determines the winner of a game round based on the moves of the players.
- **`displayScores`**: Displays the current scores.
- **`displayHistory`**: Displays the history of all game rounds.
- **`displayStatistics`**: Displays game statistics such as total rounds played and win percentages.

## Example

Here is an example of how the game flow might look:

```
Do you want to play with the computer or with another player?
1. Play with Computer
2. Play with Another Player
Enter your choice (1-2): 1

=== Rock-Paper-Scissors Game ===
1. Rock
2. Paper
3. Scissors
4. View Scores
5. View History
6. Reset Scores and History
Enter your choice (1-6): 1

You chose: Rock
Computer chose: Scissors
Player 1 wins!

Do you want to play again? (y/n): y
```

## Notes

- The program uses the `rand` function to generate random moves for the computer. The random number generator is seeded using the current time.
- The game handles invalid inputs by prompting the user to enter a valid choice.
- The game continues to prompt the user for input until they choose to exit.

Enjoy playing Rock-Paper-Scissors!
