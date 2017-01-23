//
// Created by Hanamichi on 1/17/2017.
//

#include "Character.h"

Character* Character::singleton = NULL;
Character* Character::getInstance()
{
    if (singleton == NULL)
        singleton = new Character();
    return singleton;
}

Character::Character() {
    this->init();
    this->setLocalZOrder(Z_CHARACTER);
}

void Character::standby()
{
    this->stopAllActions();
    Animate	* idleFrames;
    if(this->getCharSex())
        idleFrames = Utilities::getInstance()->getAnimFrames(anim_male_char, "male_walk_right");
    else
        idleFrames = Utilities::getInstance()->getAnimFrames(anim_female_char, "female_walk_right");
    RepeatForever *repeat = RepeatForever::create(idleFrames);
    this->runAction(repeat);
}
void Character::runUpward()
{
    this->stopAllActions();
    Animate	* upwardFrames;
    if(this->getCharSex())
        upwardFrames = Utilities::getInstance()->getAnimFrames(anim_male_char, "male_walk_up");
    else
        upwardFrames = Utilities::getInstance()->getAnimFrames(anim_female_char, "female_walk_up");
    RepeatForever *repeat = RepeatForever::create(upwardFrames);
    this->runAction(repeat);
}
void Character::runDownward()
{
    this->stopAllActions();
    Animate	* downwardFrames;
    if(this->getCharSex())
        downwardFrames = Utilities::getInstance()->getAnimFrames(anim_male_char, "male_walk_down");
    else
        downwardFrames = Utilities::getInstance()->getAnimFrames(anim_female_char, "female_walk_down");
    RepeatForever *repeat = RepeatForever::create(downwardFrames);
    this->runAction(repeat);
}
void Character::runLeftward()
{
    this->stopAllActions();
    Animate	* leftwardFrames;
    if(this->getCharSex())
        leftwardFrames = Utilities::getInstance()->getAnimFrames(anim_male_char, "male_walk_left");
    else
        leftwardFrames = Utilities::getInstance()->getAnimFrames(anim_female_char, "female_walk_left");
    RepeatForever *repeat = RepeatForever::create(leftwardFrames);
    this->runAction(repeat);
}
void Character::runRightward()
{
    this->stopAllActions();
    Animate	* rightwardFrames;
    if(this->getCharSex())
        rightwardFrames = Utilities::getInstance()->getAnimFrames(anim_male_char, "male_walk_right");
    else
        rightwardFrames = Utilities::getInstance()->getAnimFrames(anim_female_char, "female_walk_right");
    RepeatForever *repeat = RepeatForever::create(rightwardFrames);
    this->runAction(repeat);
}