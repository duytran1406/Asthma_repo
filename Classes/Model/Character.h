//
// Created by Hanamichi on 1/17/2017.
//

#ifndef MYGAME_CHARACTER_H
#define MYGAME_CHARACTER_H
#include "cocos2d.h"
#include "Dependencies/Resources.h"
#include "Handler/Utilities.h"


using namespace std;
USING_NS_CC;
class Character: public cocos2d::Sprite {
    CC_SYNTHESIZE(std::string,char_name,CharName);
    CC_SYNTHESIZE(bool, charSex, CharSex );
    CC_SYNTHESIZE(int, char_age, CharAge);

public:
    static Character* getInstance();
    void standby();
    void runUpward();
    void runDownward();
    void runLeftward();
    void runRightward();

private:
    Character();
    static Character *singleton;
};
#endif //MYGAME_CHARACTER_H
