//
// Created by Hanamichi on 1/20/2017.
//

#include "MainMenu.h"


USING_NS_CC;

using namespace CocosDenshion;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
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

    Fighting_1 = Button::create("fight_1.png", "fight_1.png", "fight_1.png",
                                cocos2d::ui::Button::TextureResType::PLIST);
    Fighting_1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2+ origin.y));
    Fighting_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    Fighting_1->setTouchEnabled(true);
    Fighting_1->setPressedActionEnabled(true);
    Fighting_1->addTouchEventListener([this](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
                                      {
                                          if(type == cocos2d::ui::Widget::TouchEventType::ENDED)
                                          {
                                              auto loadingScene = LoadingScene::createScene();
                                              auto loadLayer = dynamic_cast<LoadingScene*>(loadingScene->getChildByName(loading_name));
                                              loadLayer->setListTexture(fighting_texture);
                                              loadLayer->setListPlist(fighting_plist);
                                              loadLayer->setNextScene(SCENE::FIGHTING);
                                              loadLayer->preloadTexture();
                                              changeScene(loadingScene);
                                          }
                                      });
    this->addChild(Fighting_1,999);




    return true;
}
void MainMenu::changeScene(Scene* scene){

    auto transition = TransitionFade::create(0.5f, scene);
    Director *pDirector = Director::getInstance();
    pDirector->pushScene(transition);
}