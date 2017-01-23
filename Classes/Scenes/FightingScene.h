//
// Created by Hanamichi on 1/18/2017.
//

#ifndef MYGAME_FIGHTINGSCENE_H
#define MYGAME_FIGHTINGSCENE_H


#include "cocos2d.h"
#include "Dependencies/Resources.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "FightingScene.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::ui;
class FightingScene : public cocos2d::Layer
{
CC_SYNTHESIZE(std::string, background,Background);
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    Size visibleSize;
    Vec2 origin;

    void distributeAssets();

    //switchScene
//    void changeScene(Scene* scene);

    // implement the "static create()" method manually
    CREATE_FUNC(FightingScene);
};




#endif //MYGAME_FIGHTINGSCENE_H
