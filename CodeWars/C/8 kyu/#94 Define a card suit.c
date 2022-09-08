// You get any card as an argument. Your task is to return the suit of this card
// (in lowercase).
//
// Our deck (is preloaded):
//
// deck = ['2♣','3♣','4♣','5♣','6♣','7♣','8♣','9♣','10♣','J♣','Q♣','K♣','A♣',
//         '2♦','3♦','4♦','5♦','6♦','7♦','8♦','9♦','10♦','J♦','Q♦','K♦','A♦',
//         '2♥','3♥','4♥','5♥','6♥','7♥','8♥','9♥','10♥','J♥','Q♥','K♥','A♥',
//         '2♠','3♠','4♠','5♠','6♠','7♠','8♠','9♠','10♠','J♠','Q♠','K♠','A♠'];

#include <string.h>

extern const char* const deck[52];

enum CardSuit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum CardSuit get_suit(const char* card)
{
    // suits will have their unicode:
    // ♣ = 0xE2 99 A3, ♦ = 0xE2 99 A6, ♥ = 0xE2 99 A5, ♠ = 0xE2 99 A0
    // Using two's complement to transform the least significant byte, one would get
    // (♣) A3 = -93, (♦) A6 = -90, (♥) A5 = -91, (♠) A0 = -96
    switch (card[strlen(card) - 1])
    {
    case -93:
        return CLUBS;
    case -90:
        return DIAMONDS;
    case -91:
        return HEARTS;
    case -96:
        return SPADES;
    }
}
