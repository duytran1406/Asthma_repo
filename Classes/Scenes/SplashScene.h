#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"
#include "Dependencies/Resources.h"
#include "LoadingScene.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "Handler/Utilities.h"

using namespace cocos2d;
using namespace CocosDenshion;
class SplashScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    Size visibleSize;
    Vec2 origin;

    //switchScene
    void changeScene();

    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);
};

#endif // __SPLASH_SCENE_H__
