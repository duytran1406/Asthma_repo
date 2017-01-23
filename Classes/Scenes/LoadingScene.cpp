//
// Created by Hanamichi on 1/17/2017.
//

#include "LoadingScene.h"

USING_NS_CC;

Scene* LoadingScene::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = LoadingScene::create();
    layer->setName(loading_name);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LoadingScene::init() {
    //////////////////////////////
    // 1. super init first
    Layer layer;
    if (!layer.init()) {
        return false;
    }
    //	Director::getInstance()->setClearColor(Color4F(1.0f, 1.0f, 1.0f, 1.0f));


    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    imageCache = SpriteFrameCache::sharedSpriteFrameCache();

    imageCache->addSpriteFramesWithFile(p_loading_scene, i_loading_scene);

    auto soundEngine = SimpleAudioEngine::getInstance();
    soundEngine->playBackgroundMusic("sound/loading_bgm.mp3", false );
    lbIncrement = 0;



    //Set background for Loading scene


    //Distribute assets of Loading Scene

    distributeAssets();

    return true;
}

void LoadingScene::distributeAssets() {
    Sprite *bg = Sprite::createWithSpriteFrame(imageCache->getSpriteFrameByName("BG.png"));
    bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    bg->setPosition(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y);
    this->addChild(bg,0);

    //Loading label
    CCLabelBMFontAnimated *label = CCLabelBMFontAnimated::createWithBMFont("fonts/Ninja.fnt", "",
                                                                           cocos2d::TextHAlignment::CENTER, visibleSize.width,
                                                                           cocos2d::Vec2(0, 0));
    label->setPosition(origin.x + visibleSize.width / 2,
                       origin.y + visibleSize.height / 2);
    label->setString("Loading...");
    label->animateInSwell(2.7);
    label->setLocalZOrder(9999);
    this->addChild(label);

    Sprite *border = Sprite::create("res/LoadingScene/border.png");
    border->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3 - 50.0f));
    this->addChild(border);
    loadingBar =  LoadingBar::create();
    loadingBar->setName("LOADINGBAR");
    loadingBar->loadTexture("res/LoadingScene/loadingbar.png");
    loadingBar->setPercent(0);
    loadingBar->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3 - 50.0f));
    this->addChild(loadingBar);


}

void LoadingScene::preloadTexture(){
    if(list_texture.size() >0){
        std::string filepath = list_texture.front();
        log("%s", filepath.c_str());
        Director::getInstance()->getTextureCache()->addImageAsync(filepath, CC_CALLBACK_1(LoadingScene::preloadPlist, this));
    }
    else{
        LoadingScene::changeScene();
    }
}
void LoadingScene::preloadPlist(Texture2D* texture){
    std::string filepath = list_plist.front();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(filepath, texture);

    bool checkLoaded = false;
    while(checkLoaded ==false){
        checkLoaded = SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(filepath);
        if(checkLoaded){
            if(lbIncrement==0) {
                lbIncrement = 100 / list_texture.size();
            }
            log("increment : %f", lbIncrement);
            loadingBar->setPercent(MIN((loadingBar->getPercent() + lbIncrement),100));
            list_texture.erase(list_texture.begin());
            list_plist.erase(list_plist.begin());
            auto cb = CallFunc::create(this, CC_CALLFUNC_SELECTOR(LoadingScene::preloadTexture));
            auto sequence = Sequence::create(DelayTime::create(0.5f),cb,NULL);
            this->runAction(sequence);
        }
    }

}

void LoadingScene::changeScene(){
    switch(nextScene) {
        case (MAINMENU): {
            _nextScene = MainMenu::createScene();
            break;
        }
        case (PLAYERINFO): {
            _nextScene = PlayerInfo::createScene();
            break;
        }
        case (FIGHTING): {
            _nextScene = FightingScene::createScene();
            auto mLayer = dynamic_cast<FightingScene*>(_nextScene->getChildByName(fighting_scene));
            mLayer->setBackground("background_1.png");
            mLayer->distributeAssets();
            break;
        }
    }
    auto soundEngine = SimpleAudioEngine::getInstance();
    soundEngine->stopBackgroundMusic();
    Director::getInstance()->pushScene(TransitionFade::create(0.5, _nextScene));
}
