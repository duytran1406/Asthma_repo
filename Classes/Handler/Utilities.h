/*
 * Utilities.h
 *
 *  Created on: Dec 26, 2016
 *      Author: Hanamichi
 */

#ifndef HANDLER_UTILITIES_H_
#define HANDLER_UTILITIES_H_

#include "cocos2d.h"
#include <vector>
using namespace std;
USING_NS_CC;
class Utilities {
private:
    Utilities();
    static Utilities *singleton;

public:
    static Utilities* getInstance();
	Animate	* getAnimFrames(std::string path, std::string anim_name);
    std::vector<std::string> plusArray(std::vector<std::string> a, std::vector<std::string> b);

    };



#endif /* HANDLER_UTILITIES_H_ */
