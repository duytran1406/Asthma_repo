#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#include "Handler/Utilities.h"

using namespace std;

enum SCENE {
    MAINMENU,
    PLAYERINFO,
    FIGHTING
};
enum FIGHTING {
    CACTUS ,
    MUSHROOM
};
static const char USERNAME[] = "USERNAME";
static const char USERAGE[] = "USERAGE";
static const char USERSEX[] = "USERSEX";

/******************** SplashScene *********************/

//SplashScene background
static const char splash_background[] = "res/SplashScene/splash_bg.png";
/******************** Loading Scene *********************/
static const char loading_name[] = "LOADING LAYER";
//pList charater
static const char p_loading_char[] = "res/LoadingScene/loading_char.plist";
//texture character
static const char i_loading_char[] = "res/LoadingScene/loading_char.png";

static const char p_loading_scene[] = "res/LoadingScene/loadingscene.plist";
static const char i_loading_scene[] = "res/LoadingScene/loadingscene.png";
static const char anim_ninjas[] = "res/LoadingScene/anim_load.plist";

/******************** Player Info *********************/
static const char p_player_info[] = "res/InfoScene/playerinfo.plist";
static const char i_player_info[] = "res/InfoScene/playerinfo.png";

/******************** Character plists *********************/
static const char p_male_char[] = "res/Character/Male/male.plist";
static const char i_male_char[] = "res/Character/Male/male.png";
static const char anim_male_char[] = "res/Character/Male/anim_char_male.plist";

static const char p_female_char[] = "res/Character/Female/female.plist";
static const char i_female_char[] = "res/Character/Female/female.png";
static const char anim_female_char[] = "res/Character/Female/anim_char_female.plist";
/******************** Fighting Scene *********************/
static const char fighting_scene[] = "FIGHTING SCENE LAYER";
static const char p_fight_assets[] = "res/FightingScene/fightingscene.plist";
static const char i_fight_assets[] = "res/FightingScene/fightingscene.png";


/******************** Main Menu **************************/
static const char p_main_assets[] = "res/MainMenu/mainmenu.plist";
static const char i_main_assets[] = "res/MainMenu/mainmenu.png";
/******************** Loading Vectors ********************/
//List loading for each scene
//Player Info
static const std::vector<std::string> player_info_texture = {i_player_info};
static const std::vector<std::string> player_info_plist = {p_player_info};
//Characters
static const std::vector<std::string> character_texture = {i_male_char, i_female_char};
static const std::vector<std::string> character_plist = {p_male_char, p_female_char};
//Main Menu
static const std::vector<std::string> mainmenu_texture = {i_main_assets};
static const std::vector<std::string> mainmenu_plist = {p_main_assets};
//Fighting Scene
static const std::vector<std::string> fighting_texture = {i_fight_assets};
static const std::vector<std::string> fighting_plist = {p_fight_assets};




//Z Order

static const int Z_CHARACTER = 5;

#endif // __RESOURCES_H__
