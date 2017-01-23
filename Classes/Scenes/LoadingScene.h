//
// Created by Hanamichi on 1/17/2017.
//

#ifndef LoadingScene_hpp
#define LoadingScene_hpp

#include "cocos2d.h"
#include "Handler/CCLabelBMFontAnimated.h"
#include "Handler/Utilities.h"
#include "MainMenu.h"
#include "Dependencies/Resources.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "PlayerInfo.h"
#include <thread>
#include <mutex>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::ui;


class LoadingScene : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();
    void preloadTexture();


    LoadingBar* loadingBar;
    float lbIncrement;
    Size visibleSize;
    Vec2 origin;
    Scene* _nextScene;
//    CCLabelBMFontAnimated *label;
    SpriteFrameCache *imageCache;
CC_SYNTHESIZE(SCENE , nextScene, NextScene);
CC_SYNTHESIZE(std::vector<std::string>, list_texture, ListTexture);
CC_SYNTHESIZE(std::vector<std::string>, list_plist, ListPlist);

    // implement the "static create()" method manually
    CREATE_FUNC(LoadingScene);

private:
    void distributeAssets();


    void preloadPlist(Texture2D *texture);

    void preloadSound();

    //switchScene
    void changeScene();
};

#endif /* LoadingScene_hpp */
