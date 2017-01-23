#include "SplashScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

using namespace CocosDenshion;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
	Layer layer;
    if ( !layer.init() )
    {
        return false;
    }
    Director::getInstance()->setClearColor(Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    Sprite *sprLogo = Sprite::create(splash_background);
    sprLogo->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprLogo->setPosition(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y);

    auto soundEngine = SimpleAudioEngine::getInstance();
    soundEngine->playBackgroundMusic("sound/yawn.mp3", false );

    this->addChild(sprLogo, 0);
    auto cb = CallFunc::create(this, callfunc_selector(SplashScene::changeScene));

    auto sequence = Sequence::create(DelayTime::create(1.0f),cb,NULL);
    this->runAction(sequence);
    
    
    return true;
}


void SplashScene::changeScene(){
    auto loadingScene = LoadingScene::createScene();
    auto loadLayer = dynamic_cast<LoadingScene*>(loadingScene->getChildByName(loading_name));
    auto p_name = UserDefault::getInstance()->getStringForKey(USERNAME,"");
    auto p_age =  UserDefault::getInstance()->getIntegerForKey(USERAGE,0);
    if(p_name == "" && p_age == 0) {

        loadLayer->setListTexture(Utilities::getInstance()->plusArray(player_info_texture, character_texture));
        loadLayer->setListPlist(Utilities::getInstance()->plusArray(player_info_plist, character_plist));
        loadLayer->setNextScene(SCENE::PLAYERINFO);
        loadLayer->preloadTexture();
    } else {
        loadLayer->setListTexture(Utilities::getInstance()->plusArray(character_texture,mainmenu_texture));
        loadLayer->setListPlist(Utilities::getInstance()->plusArray(character_plist,mainmenu_plist));
        loadLayer->setNextScene(SCENE::MAINMENU);
        loadLayer->preloadTexture();
    }

    auto transition = TransitionFade::create(0.5f, loadingScene);
    Director *pDirector = Director::getInstance();
    pDirector->pushScene(transition);
}

