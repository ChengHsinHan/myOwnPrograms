// Rock Paper Scissors
// Let's play! You have to return which player won! In case of a draw return
// Draw!.
//
// Examples(Input1, Input2 --> Output):
//
// "scissors", "paper" --> "Player 1 won!"
// "scissors", "rock" --> "Player 2 won!"
// "paper", "paper" --> "Draw!"

enum tool
{
    ROCK,
    PAPER,
    SCISSORS,
};

enum outcome
{
    P1_WON,
    P2_WON,
    DRAW,
};

enum outcome rps(enum tool p1, enum tool p2)
{
    return (enum outcome[3][3]) {
        [ROCK]     = { [ROCK] = DRAW,   [PAPER] = P2_WON, [SCISSORS] = P1_WON },
        [PAPER]    = { [ROCK] = P1_WON, [PAPER] = DRAW,   [SCISSORS] = P2_WON },
        [SCISSORS] = { [ROCK] = P2_WON, [PAPER] = P1_WON, [SCISSORS] = DRAW   }
    }[p1][p2];
}
