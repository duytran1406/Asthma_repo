#ifndef __CCLabelAnimated__CCLabelAnimated__
#define __CCLabelAnimated__CCLabelAnimated__

#include <stdio.h>
#include "cocos2d.h"

class CCLabelBMFontAnimated : public cocos2d::Label {
public:
    
    // ONLY USE THIS FUNCTION FOR CREATION
    static CCLabelBMFontAnimated* createWithBMFont(const std::string& bmfontFilePath, const std::string& text,const cocos2d::TextHAlignment& alignment /* = TextHAlignment::LEFT */, int maxLineWidth /* = 0 */, const cocos2d::Vec2& imageOffset /* = Vec2::ZERO */);
    static CCLabelBMFontAnimated* createWithTTF(const std::string& text, const std::string& fontFile, float fontSize, const cocos2d::Size& dimensions /* = Size::ZERO */, cocos2d::TextHAlignment hAlignment /* = TextHAlignment::LEFT */, cocos2d::TextVAlignment vAlignment /* = TextVAlignment::TOP */);
    
    //FUNCTIONS TO SET BASIC CHARACTER SPRITE PROPERTIES AT INDEX
    void setCharScale(int index, float s);
    void setCharOpacity(int index, float o);
    void setCharRotation(int index, float r);
    
    //FUNCTIONS TO SET BASIC PROPERTIES OF ALL CHARACTER SPRITES
    void setAllCharsScale(float s);
    void setAllCharsOpacity(float o);
    void setAllCharsRotation(float r);
    void offsetAllCharsPositionBy(cocos2d::Point offset);
    
    //FUNCTIONS TO RUN CUSTOM ACTIONS ON CHARATER SPRITES
    void runActionOnSpriteAtIndex(int index, cocos2d::FiniteTimeAction* action);
    
    void runActionOnAllSprites(cocos2d::Action* action);
    void runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion);
    void runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void stopActionsOnAllSprites();
    
    //for the 'run actions sequentially' functions, duration refers to the total time to complete actions on all letters, minus the duration of the action itself
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion);
    void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration);
    
    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion, cocos2d::CallFunc *callFuncOnCompletion);
    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, bool removeOnCompletion);
    void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration);
    
    //ANIMATIONS
    
    //fly ins
    void animateInFlyInFromLeft(float duration);
    void animateInFlyInFromRight(float duration);
    void animateInFlyInFromTop(float duration);
    void animateInFlyInFromBottom(float duration);
    
    //misc animate ins
    void animateInTypewriter(float duration);
    void animateInDropFromTop(float duration);
    void animateInSwell(float duration);
    void animateInRevealFromLeft(float duration);
    void animateInSpin(float duration, int spins);
    void animateInVortex(float duration, int spins);
    
    //misc animations
    void animateSwell(float duration);
    void animateJump(float duration, float height);
    void animateStretchElastic(float stretchDuration, float releaseDuration, float stretchAmount);
    void animateRainbow(float duration);
    void flyPastAndRemove();
    
private:
    
    int numLetters();
    void animateInVortex(bool removeOnCompletion, bool createGhosts, float duration, int spins);
    
};

#endif /* defined(__CCLabelAnimated__CCLabelAnimated__) */