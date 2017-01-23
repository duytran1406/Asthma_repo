#ifndef __Joystick_h__
#define __Joystick_h__

#include "cocos2d.h"
#include "Constant.h"
#include "Resources.h"

using namespace cocos2d;


class JoystickDelegate {
public:
	virtual void responeWhenUsingJoystick(MOVE_DIRECTION key_direction) {};
};

class Joystick: public CCLayer {

private:

CC_SYNTHESIZE(JoystickDelegate*,_delegate,Delegate);

	Vec2 kCenter;
	Vec2 positionInVisibleSize;
	Vec2 velocity;

	Sprite* thumbPad;
	Sprite *joystickBackground;
	bool isMoved;



public:
	CREATE_FUNC(Joystick);
	static Joystick* createWithPosition(Vec2 positionInVisibleSize);
	bool initWithPositionInVisibleSize(Vec2 positionInVisibleSize);

	void update(float delta);
	void updateThumbPad(Vec2 point);
	void resetJoystick();
	void handleLastTouch();
	Vec2 convertToCoordinate(Vec2 point);
	bool isPointInCircle(Vec2 point, Vec2 center, float radius);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchCancelled(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};
#endif
