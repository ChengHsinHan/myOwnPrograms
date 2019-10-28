#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <string>

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANK,
};

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUIT,
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card)
{
    switch (card.rank)
    {
        case RANK_2:        std::cout << "2 of ";       break;
        case RANK_3:        std::cout << "3 of ";       break;
        case RANK_4:        std::cout << "4 of ";       break;
        case RANK_5:        std::cout << "5 of ";       break;
        case RANK_6:        std::cout << "6 of ";       break;
        case RANK_7:        std::cout << "7 of ";       break;
        case RANK_8:        std::cout << "8 of ";       break;
        case RANK_9:        std::cout << "9 of ";       break;
        case RANK_10:       std::cout << "10 of ";      break;
        case RANK_JACK:     std::cout << "Jack of ";    break;
        case RANK_QUEEN:    std::cout << "Queen of ";   break;
        case RANK_KING:     std::cout << "King of ";    break;
        case RANK_ACE:      std::cout << "Ace of ";     break;
    }

    switch (card.suit)
    {
        case SUIT_CLUB:     std::cout << "Club";    break;
        case SUIT_DIAMOND:  std::cout << "Diamond"; break;
        case SUIT_HEART:    std::cout << "Heart";   break;
        case SUIT_SPADE:    std::cout << "Spade";   break;
    }
}

void printDeck(const std::array<Card, 52> &deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << " ";
    }

    std::cout << '\n';
}

void swapCard(Card &card1, Card &card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    for (int index = 0; index < 52; ++index)
    {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(deck[index], deck[swapIndex]);
    }
}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case RANK_2:        return 2;
        case RANK_3:        return 3;
        case RANK_4:        return 4;
        case RANK_5:        return 5;
        case RANK_6:        return 6;
        case RANK_7:        return 7;
        case RANK_8:        return 8;
        case RANK_9:        return 9;
        case RANK_10:       return 10;
        case RANK_JACK:     return 10;
        case RANK_QUEEN:    return 10;
        case RANK_KING:     return 10;
        case RANK_ACE:      return 11;
    }

    return 0;
}

bool playBlackJack(const std::array<Card, 52> &deck)
{
    const Card *cardPtr = &deck[0];
    int numDealerAce = 0;
    int numPlayerAce = 0;

    if (cardPtr->rank == RANK_ACE)
        ++numDealerAce;
    std::cout << "Dealer got a ";
    printCard(*cardPtr);
    std::cout << '\n';
    int dealerPoint = getCardValue(*cardPtr++);

    if (cardPtr->rank == RANK_ACE)
        ++numPlayerAce;
    std::cout << "Player got a ";
    printCard(*cardPtr);
    int playerPoint = getCardValue(*cardPtr++);
    if (cardPtr->rank == RANK_ACE)
        ++numPlayerAce;
    std::cout << " and a ";
    printCard(*cardPtr);
    std::cout << '\n';
    playerPoint += getCardValue(*cardPtr++);

    std::cout << "Dealer has " << dealerPoint << " points now.\n";
    std::cout << "Player has " << playerPoint << " points now.\n";

    std::string playerChoice;
    do
    {
        std::cout << "Does player want to stand or hit? ";
        std::getline(std::cin, playerChoice);

        if (playerChoice == "hit")
        {
            std::cout << "It's a ";
            printCard(*cardPtr);
            std::cout << "!\n";
            if (cardPtr->rank == RANK_ACE)
                ++numPlayerAce;

            playerPoint += getCardValue(*cardPtr++);
            if (playerPoint > 21)
            {
                if (numPlayerAce > 0)
                {
                    playerPoint -= 10;
                    --numPlayerAce;
                    std::cout << "Player has " << playerPoint << " points now.\n";
                }
                else
                {
                    std::cout << "Player has " << playerPoint << " points now.\n";
                    return false;
                }
            }
        }
    }
    while (playerChoice != "stand");

    std::cout << "\nDealer's time!\n";
    while (dealerPoint < 17)
    {
        std::cout << "It's a ";
        printCard(*cardPtr);
        std::cout << "!\n";
        if (cardPtr->rank == RANK_ACE)
            ++numDealerAce;

        dealerPoint += getCardValue(*cardPtr++);
        if (dealerPoint > 21)
        {
            if (numDealerAce > 0)
            {
                std::cout << "Dealer has " << dealerPoint << " points now.\n";
                dealerPoint -= 10;
                --numDealerAce;
            }
            else
            {
                std::cout << "Dealer has " << dealerPoint << " points now.\n";
                return true;
            }
        }
    }

    std::cout << '\n';
    std::cout << "Dealer has " << dealerPoint << " points.\n";
    std::cout << "Player has " << playerPoint << " points.\n";

    return (playerPoint > dealerPoint);
}

bool playAgain()
{
    char choice;
    do
    {
        std::cout << "Do you want to play again? (y/n) ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');
    }
    while (choice != 'y' && choice != 'n');

    return (choice == 'y');
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    std::array<Card, 52> deck;

    int card = 0;
    for (int suit = 0; suit < MAX_SUIT; ++suit)
        for (int rank = 0; rank < MAX_RANK; ++rank)
        {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }

    do
    {
        shuffleDeck(deck);

        if (playBlackJack(deck))
            std::cout << "Player wins!\n";
        else
            std::cout << "Dealer wins!\n";
    }
    while(playAgain());
}
