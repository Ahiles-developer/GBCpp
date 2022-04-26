#ifndef TWENTY_ONE_PLAYER_H
#define TWENTY_ONE_PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
    Player(const std::string& _name = "");
    virtual ~Player();
    virtual bool needMore() const;
    void win() const;
    void lose() const;
    void draw() const;
};
#endif //TWENTY_ONE_PLAYER_H
