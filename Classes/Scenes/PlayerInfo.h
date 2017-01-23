//
// Created by Hanamichi on 1/21/2017.
//

#ifndef MYGAME_PLAYERINFO_H
#define MYGAME_PLAYERINFO_H


#include "cocos2d.h"
#include "Dependencies/Resources.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "Model/Character.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::ui;
class PlayerInfo : public cocos2d::Layer, public cocos2d::ui::EditBoxDelegate
{
private:
    std::string player_name;
    int player_age;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    Size visibleSize;
    Vec2 origin;

    //switchScene
    void changeScene();

    void nameAgeDialog();

    void CharSelection();

    // implement the "static create()" method manually
    CREATE_FUNC(PlayerInfo);

    /**
         * This method is called when an edit box gains focus after keyboard is shown.
         * @param editBox The edit box object that generated the event.
         */
    virtual void editBoxEditingDidBegin(EditBox* editBox);


    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidEnd(EditBox* editBox);

    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     */
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);

    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxReturn(EditBox* editBox);
};


#endif //MYGAME_PLAYERINFO_H
