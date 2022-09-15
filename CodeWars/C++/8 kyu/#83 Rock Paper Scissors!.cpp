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
#include <unordered_map>

std::string rps(const std::string& p1, const std::string& p2)
{
    std::unordered_map<std::string, std::string> winOver = {
        { "rock", "paper" },
        { "paper", "scissors" },
        { "scissors", "rock" }
    };

    if (p1 == winOver[p2])
        return "Player 1 won!";
    else if (p2 == winOver[p1])
        return "Player 2 won!";
    else
        return "Draw!";
}
