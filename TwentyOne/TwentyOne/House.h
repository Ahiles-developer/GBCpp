#ifndef TWENTY_ONE_HOUSE_H
#define TWENTY_ONE_HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
    House(const std::string& name = "House");
    virtual ~House();
    virtual bool needMore() const;
    void flipTopCard();
};

#endif //TWENTY_ONE_HOUSE_H
