// Rock Paper Scissors
// Let's play! You have to return which player won! In case of a draw return
// Draw!.
//
// Examples(Input1, Input2 --> Output):
//
// "scissors", "paper" --> "Player 1 won!"
// "scissors", "rock" --> "Player 2 won!"
// "paper", "paper" --> "Draw!"

#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    // ASCII values: 'r' = 82, 'p' = 80, 's' = 83
    switch (p1[0] - p2[0])
    {
    case -1:
    case -2:
    case 3:
        return "Player 1 won!";
    case 1:
    case 2:
    case -3:
        return "Player 2 won!";
    default:
        return "Draw!";
    }
}
