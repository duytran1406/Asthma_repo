//
// Created by Hanamichi on 1/21
#include "PlayerInfo.h"

#include <SimpleAudioEngine.h>

USING_NS_CC;

using namespace CocosDenshion;

Scene *PlayerInfo::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = PlayerInfo::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PlayerInfo::init() {
    //////////////////////////////
    // 1. super init first
    Layer layer;
    if (!layer.init()) {
        return false;
    }
    Director::getInstance()->setClearColor(Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    Sprite *sprBG = Sprite::createWithSpriteFrameName("info_bg.png");
    sprBG->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprBG->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    player_name = UserDefault::getInstance()->getStringForKey(USERNAME, "");
    player_age = UserDefault::getInstance()->getIntegerForKey(USERAGE, 0);
    this->addChild(sprBG, 0);
    nameAgeDialog();

    return true;
}

void PlayerInfo::nameAgeDialog() {
    Sprite *dialog = Sprite::createWithSpriteFrameName("info_board.png");
    dialog->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    dialog->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height * 0.6 + origin.y);
    dialog->setName("INFOBOARDDIALOG");
    this->addChild(dialog);

    /**Adding components to info board**/
    Size boardSize = dialog->getContentSize();
    TTFConfig label_config;
    //Set the TTF file of TTFConfig, this attribute should not be omitted
    label_config.fontFilePath = "fonts/Marker Felt.ttf";
    label_config.fontSize = 50;
    //create the LabelTTF through the label config
    auto lblName = Label::createWithTTF(label_config, "NAME");
    lblName->setColor(Color3B::WHITE);
    lblName->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    lblName->setPosition(Vec2(boardSize.width / 2, boardSize.height * 0.8));
    dialog->addChild(lblName);

    auto _editName = EditBox::create(Size(526, 90), Scale9Sprite::createWithSpriteFrameName("info_editbox.png"));
    _editName->setPosition(Vec2(boardSize.width / 2, boardSize.height * 0.65));
    _editName->setFontSize(50);
    _editName->setFontColor(Color3B::WHITE);
    _editName->setMaxLength(16);
    _editName->setInputMode(EditBox::InputMode::SINGLE_LINE);
    _editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    _editName->setName("EDITNAME");
    _editName->setDelegate(this);
    dialog->addChild(_editName);

    auto lblAge = Label::createWithTTF(label_config, "AGE");
    lblAge->setColor(Color3B::WHITE);
    lblAge->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    lblAge->setPosition(Vec2(boardSize.width / 2, boardSize.height * 0.5));
    dialog->addChild(lblAge);

    auto _editAge = EditBox::create(Size(526, 90), Scale9Sprite::createWithSpriteFrameName("info_editbox.png"));
    _editAge->setPosition(Vec2(boardSize.width / 2, boardSize.height * 0.35));
    _editAge->setFontSize(50);
    _editAge->setFontColor(Color3B::WHITE);
    _editAge->setInputMode(EditBox::InputMode::NUMERIC);
    _editAge->setMaxLength(3);
    _editAge->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    _editAge->setName("EDITAGE");
    _editAge->setDelegate(this);
    dialog->addChild(_editAge);


    auto btnOK = Button::create("info_btn_ok.png", "info_btn_ok.png", "info_btn_ok.png",
                                cocos2d::ui::Button::TextureResType::PLIST);
    btnOK->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 5 + origin.y));
    btnOK->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    btnOK->setTouchEnabled(true);
    btnOK->setPressedActionEnabled(true);
    btnOK->setName("BTNOK");
    btnOK->addTouchEventListener([this](Ref *sender, cocos2d::ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            if(player_name == "" || player_age == 0){
                MessageBox("ERROR!!!", "Please enter your name and your age.");
            } else {
                UserDefault::getInstance()->setStringForKey(USERNAME, player_name);
                UserDefault::getInstance()->setIntegerForKey(USERAGE, player_age);
                CharSelection();
            }
            log("OK!!");
        }
    });
    this->addChild(btnOK, 999);

}
void PlayerInfo::CharSelection() {
    auto dialog = this->getChildByName("INFOBOARDDIALOG");
    dialog->removeAllChildren();
    this->removeChildByName("INFOBOARDDIALOG",true);
    this->removeChildByName("BTNOK",true);

    TTFConfig label_config;
    //Set the TTF file of TTFConfig, this attribute should not be omitted
    label_config.fontFilePath = "fonts/Marker Felt.ttf";
    label_config.fontSize = 100;
    //create the LabelTTF through the label config
    auto lblName = Label::createWithTTF(label_config, "ARE YOU A BOY OR A GIRL?");
    lblName->setColor(Color3B::WHITE);
    lblName->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    lblName->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.9 + origin.y));
    this->addChild(lblName);


    auto btnMale = Button::create("male_portrait.png", "male_portrait.png", "male_portrait.png",
                                  cocos2d::ui::Button::TextureResType::PLIST);
    btnMale->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    btnMale->setPosition(Vec2(visibleSize.width*0.25 + origin.x, visibleSize.height*0.45 + origin.y));
    btnMale->setTouchEnabled(true);
    btnMale->setScale(0.5);
    btnMale->setPressedActionEnabled(true);
    btnMale->addTouchEventListener([this](Ref *sender, cocos2d::ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            UserDefault::getInstance()->setBoolForKey(USERSEX,true);
            auto mCharacter = Character::getInstance();
            mCharacter->setCharAge(player_age);
            mCharacter->setCharName(player_name);
            mCharacter->setCharSex(true);
            changeScene();

            log("MALE!!");
        }
    });
    this->addChild(btnMale);


    auto btnFemale = Button::create("female_portrait.png", "female_portrait.png", "female_portrait.png",
                                  cocos2d::ui::Button::TextureResType::PLIST);
    btnFemale->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    btnFemale->setPosition(Vec2(visibleSize.width*0.75 + origin.x, visibleSize.height*0.45 + origin.y));
    btnFemale->setTouchEnabled(true);
    btnFemale->setScale(0.5);
    btnFemale->setPressedActionEnabled(true);
    btnFemale->addTouchEventListener([this](Ref *sender, cocos2d::ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            UserDefault::getInstance()->setBoolForKey(USERSEX,false);
            auto mCharacter = Character::getInstance();
            mCharacter->setCharAge(player_age);
            mCharacter->setCharName(player_name);
            mCharacter->setCharSex(false);
            changeScene();

            log("FEMALE!!");
        }
    });
    this->addChild(btnFemale);

}
void PlayerInfo::changeScene() {
    auto loadingScene = LoadingScene::createScene();
    auto loadLayer = dynamic_cast<LoadingScene*>(loadingScene->getChildByName(loading_name));

    loadLayer->setListTexture(mainmenu_texture);
    loadLayer->setListPlist(mainmenu_plist);
    loadLayer->setNextScene(SCENE::MAINMENU);
    loadLayer->preloadTexture();

    auto transition = TransitionFade::create(0.5f, loadingScene);
    Director *pDirector = Director::getInstance();
    pDirector->pushScene(transition);
}


void PlayerInfo::editBoxEditingDidBegin(EditBox *editBox) {

}


void PlayerInfo::editBoxEditingDidEnd(EditBox *editBox) {
}


void PlayerInfo::editBoxTextChanged(EditBox *editBox, const std::string &text) {
}


void PlayerInfo::editBoxReturn(EditBox *editBox) {
    if (editBox->getName() == "EDITNAME") {
        player_name = editBox->getText();
    } else {
        String text = editBox->getText();
        player_age = text.intValue();
    }
}