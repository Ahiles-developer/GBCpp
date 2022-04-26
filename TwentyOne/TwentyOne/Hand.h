#ifndef TWENTY_ONE_HAND_H
#define TWENTY_ONE_HAND_H

#include "Card.h"
#include <vector>

class Hand {
protected:
    std::vector<Card *> cards;
public:
    Hand();
    virtual ~Hand();
    void add(Card* card);
    void clear();
    int getPoints() const;
};



#endif //TWENTY_ONE_HAND_H
