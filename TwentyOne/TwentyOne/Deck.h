#ifndef TWENTY_ONE_DECK_H
#define TWENTY_ONE_DECK_H

#include <algorithm>
#include <random>
#include "Hand.h"
#include "GenericPlayer.h"

class Deck /* : public Hand */{
public:
    std::vector<Card *> cards;
    Deck();
    virtual ~Deck();
    void generate();
    void shuffle();
    void deal (Hand& hand);
    void addCards (GenericPlayer& player);
};

#endif //TWENTY_ONE_DECK_H
