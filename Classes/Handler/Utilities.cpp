/*
 * Utilities.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: Hanamichi
 */

#include "Utilities.h"

Utilities* Utilities::singleton = NULL;

Utilities::Utilities(){
}
Utilities* Utilities::getInstance()
{
    if (singleton == NULL)
        singleton = new Utilities();
    return singleton;
}

Animate	* Utilities::getAnimFrames(std::string path, std::string anim_name){
	AnimationCache::purgeSharedAnimationCache();

	AnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
	// Add an animation to the Cache
	animCache->addAnimationsWithFile(path);
	Animation *animation = animCache->animationByName(anim_name);
	animation->setRestoreOriginalFrame(true);
    Animate *animN = CCAnimate::create(animation);

	return animN;
}

std::vector<std::string> Utilities::plusArray(std::vector<std::string> a, std::vector<std::string> b){
    a.insert(a.end(), b.begin(), b.end());
    return a;
}
