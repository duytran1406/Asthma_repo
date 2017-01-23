#include "Joystick.h"

#define JOYSTICK_RADIUS   120.0f //Ban kinh trong Joystick ma onTouchBegan co the nhan duoc
#define THUMB_RADIUS      50.0f //Ban kinh ma thumb di chuyen trong JoyStick

bool Joystick::initWithPositionInVisibleSize(Vec2 positionInVisibleSize) {
	this->positionInVisibleSize = positionInVisibleSize;
	kCenter = Vec2(JOYSTICK_RADIUS, JOYSTICK_RADIUS);

	velocity = Vec2::ZERO;
	isMoved = false;

	joystickBackground = Sprite::create(s_gamescene_joystick_background);
	joystickBackground->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	joystickBackground->setScale(4);
	joystickBackground->setPosition(kCenter + positionInVisibleSize);
	this->addChild(joystickBackground, 0);

	thumbPad = Sprite::create(s_gamescene_joystick_thumbpad);
	thumbPad->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	thumbPad->setScale(1.5);
	thumbPad->setPosition(kCenter + positionInVisibleSize);
	this->addChild(thumbPad, 1);

	//Handling touch event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Joystick::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
	listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

	return true;
}

Joystick* Joystick::createWithPosition(Vec2 positionInVisibleSize) {
	Joystick* joyStick = new Joystick();
	if (joyStick && joyStick->initWithPositionInVisibleSize(positionInVisibleSize))
		return joyStick;

	CC_SAFE_DELETE(joyStick);
	return nullptr;

}
void Joystick::update(float delta) {
	if (isMoved) {
		if (!_delegate) {
			CCLog("delegate null");
			return;
		}

		MOVE_DIRECTION key_direction;
		auto degree = CC_RADIANS_TO_DEGREES(-ccpToAngle(velocity));
		if (degree >= -45 && degree < 45)
			key_direction = MOVE_DIRECTION::RIGHT;
		else if (degree >= 45 && degree < 135)
			key_direction = MOVE_DIRECTION::DOWN;
		else if (degree >= 135 || (degree >= -180 && degree < -135))
			key_direction = MOVE_DIRECTION::LEFT;
		else if (degree >= -135 && degree < -45)
			key_direction = MOVE_DIRECTION::UP;

		_delegate->responeWhenUsingJoystick(key_direction);
	}
}

void Joystick::updateThumbPad(Vec2 point) {
	float dx = point.x - kCenter.x;
	float dy = point.y - kCenter.y;

	float distance = sqrt(dx * dx + dy * dy);
	float angle = atan2(dy, dx); // in radians

	if (distance > JOYSTICK_RADIUS) {
		dx = cos(angle) * JOYSTICK_RADIUS;
		dy = sin(angle) * JOYSTICK_RADIUS;
	}

	velocity = CCPointMake(dx / JOYSTICK_RADIUS, dy / JOYSTICK_RADIUS);

	if (distance > THUMB_RADIUS) {
		point.x = kCenter.x + cos(angle) * THUMB_RADIUS;
		point.y = kCenter.y + sin(angle) * THUMB_RADIUS;

		isMoved = true;
	} else
		isMoved = false;

	thumbPad->setPosition(point + positionInVisibleSize);
}

void Joystick::resetJoystick() {
	this->updateThumbPad(kCenter);
}

void Joystick::handleLastTouch() {
	this->resetJoystick();
	isMoved = false;
}

bool Joystick::onTouchBegan(Touch* touch, Event* event) {

	auto pt = touch->getLocationInView();

	//Khong biet tai sao 1 cai + 1 cai -
	pt.x -= positionInVisibleSize.x;
	pt.y += positionInVisibleSize.y;

	pt = convertToCoordinate(pt);
	if (isPointInCircle(pt, kCenter, JOYSTICK_RADIUS))
		this->updateThumbPad(pt);

	return true;
}

void Joystick::onTouchMoved(Touch* touch, Event* event) {
	auto pt = touch->getLocationInView();

	//Khong biet tai sao 1 cai + 1 cai -
	pt.x -= positionInVisibleSize.x;
	pt.y += positionInVisibleSize.y;

	pt = convertToCoordinate(pt);
	this->updateThumbPad(pt);
}

void Joystick::onTouchCancelled(Touch* touch, Event* event) {
	handleLastTouch();
}

void Joystick::onTouchEnded(Touch* touch, Event* event) {
	handleLastTouch();
}


Vec2 Joystick::convertToCoordinate(Vec2 point) {
	return Director::getInstance()->convertToGL(point);
}

bool Joystick::isPointInCircle(Vec2 point, Vec2 center, float radius) {
	float dx = (point.x - center.x);
	float dy = (point.y - center.y);
	return (radius >= sqrt((dx * dx) + (dy * dy)));
}
