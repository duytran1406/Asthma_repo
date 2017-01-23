//
// Created by Hanamichi on 1/20/2017.
//

#ifndef MYGAME_MAINMENU_H
#define MYGAME_MAINMENU_H


#include "cocos2d.h"
#include "Dependencies/Resources.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "FightingScene.h"
#include "Model/Character.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::ui;
class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    Size visibleSize;
    Vec2 origin;
    Button* Fighting_1;
    Button* Fighting_2;
    Button* I_Spy;
    Button* Quiz;
    Button* Tower_Defense;
    Button* Boss;

    //switchScene
    void changeScene(Scene* scene);

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};


#endif //MYGAME_MAINMENU_H
