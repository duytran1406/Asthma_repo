//
// Created by Hanamichi on 1/18/2017.
//


#include "FightingScene.h"


USING_NS_CC;

using namespace CocosDenshion;

Scene* FightingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = FightingScene::create();
    layer->setName(fighting_scene);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool FightingScene::init()
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


    return true;
}

void FightingScene::distributeAssets(){
    Sprite* background =  Sprite::createWithSpriteFrameName(this->getBackground());
    background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background);
    Sprite* platform = Sprite::createWithSpriteFrameName("platform.png");
    platform->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    platform->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/3 + origin.y));
    this->addChild(platform);

    auto character = Character::getInstance();
    character->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - platform->getContentSize().height/4));
    character->standby();
    this->addChild(character);
}