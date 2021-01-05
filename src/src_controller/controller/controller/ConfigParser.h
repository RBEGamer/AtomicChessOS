#pragma once
#ifndef __CONFIG_PARSER_H__
#define __CONFIG_PARSER_H__

#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
#include <map>

///INCLUDE 3rd PARTY
#include "SHARED/inih-master/INIReader.h"
#include "SHARED/magic_enum-master/include/magic_enum.hpp"
#include "SHARED/json11-master/json11.hpp"

#define USE_STD_LOG


#define INI_SETTINGS_CATEGORY_TOKEN "SETTINGS"


#define INI_USER_DATA_CATEGORY_TOKEN "USER_DATA"
#define USER_DATA_CONFIG_ENTRY_PREFIX "USER_"
class ConfigParser
{
public:
	///PLEAE NOT BY EDIT/ADDING ENTRIES PLEASE EDIT ConfigParser::createConfigFile FUNCTION
	enum class CFG_ENTRY
	{
		NETWORK_BACKEND_URL = 0,
		NETWORK_HEARTBEAT_INTERVAL_SECS = 1,
		
		
		GENERAL_HWID_INTERFACE = 10,
		GENERAL_VERSION_FILE_PATH = 11,
		GENERAL_HWREV_FILE_PATH = 12,
		GENERAL_BOOT_PARTION_INFO_FILE_PATH = 13,
		GENERAL_SYSTEM_TICK_INTERVAL_MS = 14,
		GENERAL_ENABLE_RANDOM_MOVE_MATCH = 15,
		GENERAL_EN_ATCGUI_COMMUNICATION = 16,   //ENABLES THE ATC GUI COMMUNICATION IF DISBALED THE ATC QT GUI ID DISABLED AND THE WEBCLIENT IS USED
		//---------------------------------------------------------------- //
		// FOR THE MECHANIC PART PLEASE SEE THE  CALIBRATION GUIDE IMAGE
		//---------------------------------------------------------------- //
		
		MECHANIC_STEPS_PER_MM = 20,
		MECHANIC_INVERT_COILS = 21,
		//OFFSET COORDINATES FROM HOME POS TO H1
		MECHANIC_H1_OFFSET_MM_X = 22,
		MECHANIC_H1_OFFSET_MM_Y = 23,
		//DISTANCE BETWEEN COILS //IN THE MIDDLE IS THE NFC TAG
		MECHANIC_DISTANCE_COILS_MM = 24,
		//X POSITION WHRE TO SWITCH THE COILS NEED TO SWITCH
		MECHANIC_COIL_SWITCH_POSTION_TRIGGER = 25,
		//WIDTH OF EACH CHESS FIELD
		MECHANIC_CHESS_FIELD_WIDTH = 26,
		//WIDTH OF THE 8x8 CHESS BOARD TOTAL = MECHANIC_CHESS_FIELD_WIDTH*8
		MECHANIC_CHESS_BOARD_WIDTH = 27,
		//X AXIS OFFSET FROM HOME POS TO THE RIGHT/BLACK PARKING POS
		MECHANIC_PARK_POS_BLACK_X_LINE = 28,
		//Y AXIS OFFSET FROM HOME POS TO THE FIRST PARKING POS RIGHT/BLACK
		MECHANIC_PARK_POS_BLACK_FIRST_Y_OFFSET = 29,
		
		MECHANIC_PARK_POS_WHITE_X_LINE = 30,
		MECHANIC_PARK_POS_WHITE_FIRST_Y_OFFSET = 31,
		//DISTANCE BETWEEN EACH PARK POS TO THE NEXT
		MECHANIC_PARK_POS_CELL_SIZE = 32,
		MECHANIC_PARK_POS_CELL_BEFORE_OFFSET = 33,
		MECHANIC_BOARD_SIZE_550MM_WORKAROUND = 34,
		MECHANIC_WRITE_COIL_STATE_ALWAYS_MAKE_MOVE = 35,
		MECHANIC_WRITE_COIL_STATE_ALWAYS_WRITE_OFF = 36,
		MECHANIC_BOARD_HOME_AFTER_MAKE_MOVE = 37,
		
		MECHANIC_DISBABLE_COILSIWTCH_USE_COIL_A_ONLY = 38,//IN THE DK HARDWAERE OF THE ATC TABLE THERE ARE TWO COILS TO MOVE THE FIGURES IN THE PROD HARDWARE IS ONLY ONE AT POSTION A
		
		BOARD_PRESET_START_POSITION_FEN = 50,
		
		
		HWARDWARE_REVISION = 60,  //DETERMS THE HW REV OF THE TABLE DK,PROD
		HARDWARE_MARLIN_BOARD_SERIAL_PORT = 61,  //IF USING A MARLIN COMPTIBLE BOARD TO CONTROL THE STEPPERS WRITE THE SERIAL PORT PATH HERE
		HARDWARE_MARLIN_BOARD_SERIAL_BAUD = 62,  //USED BAUD RATE OF THE MARLIN BOARD
		
		
		HARDWARE_MARLIN_SERVO_COIL_A_INDEX = 63,
		HARDWARE_MARLIN_SERVO_COIL_B_INDEX = 64,
		HARDWARE_MARLIN_SERVO_COIL_BOTTOM_POS = 65,
		HARDWARE_MARLIN_SERVO_COIL_UPPER_POS = 66,
		
		
		//-------- USER_ SECTION FOR USER DATA WHICH ARE DYN LOADED FROM SERVER ---- //
		//SOME REVERSE ENTRIES FOR CUSTOM  SAVE STUFF
		
		USER_GENERAL_ENABLE_RANDOM_MOVE_MATCH = 100, //USED TO PLAY AUTOMATICLY SIMPLY SENDS A RANDOM VALID MOVE IF ITS PLAYERS TURN
        USER_GENERAL_ENABLE_AUTO_MATCHMAKING_ENABLE = 101, //USED TO AUTOMATICLY ENABLE SEARCHING FOR A MATCH USING THE MATCHMAKING ALGORITHM
        USER_GENERAL_ENABLE_AUTOLOGIN = 102, //PERFOM A AUTOLOGIN AND DOES STRAIGHT INTO THE MAIN MENU
        USER_RESERVED_SKIP_CHESS_PLACEMENT_DIALOG = 103, //SKIPS THE FIRST DIALOG WHICH ASKS THE USER TO PLACE THE FIGURE CORRECTLY
        USER_RESERVED_5 = 104,
        USER_RESERVED_6 = 105,
        USER_RESERVED_7 = 106,
        USER_RESERVED_8 = 107,
        USER_RESERVED_9 = 108,
        USER_RESERVED_10 = 109,
        USER_RESERVED_11 = 110,
        USER_RESERVED_12 = 111,
        USER_RESERVED_13 = 112,
        USER_RESERVED_14 = 113,
        USER_RESERVED_15 = 114,
        USER_RESERVED_16 = 115,
        USER_RESERVED_17 = 116,
        USER_RESERVED_18 = 117,
        USER_RESERVED_19 = 118,
        USER_RESERVED_20 = 119
		
	};
	
	static ConfigParser* getInstance();
	
	bool loadConfigFile(std::string _file);
	bool createConfigFile(std::string _file, bool _load_directly); //GENERATES A CONFIG FILE WITH DEFAULTS
	
	bool configLoaded();
	
	std::string get(ConfigParser::CFG_ENTRY _entry);
	void set(ConfigParser::CFG_ENTRY _entry, std::string _value, std::string _conf_file_path); //SETS A CONFIG VALUE FOR ENTRY IF _conf_file_path IS NOT EMPTY THE NEW CONFIG WILL BE WRITTEN TO FILE
	bool writeConfigFile(std::string _file);
	
	bool getInt(ConfigParser::CFG_ENTRY _entry, int& _ret);
	int getInt_nocheck(ConfigParser::CFG_ENTRY _entry); //SAME AS getInt BUT WITH NO SUCCESS CHECK IF ENTRY FOUND; RETURN 0 IF ENTRY WAS NOT FOUND 
	bool getBool(ConfigParser::CFG_ENTRY _entry, bool& _ret);
	void loadDefaults();
	bool getBool_nocheck(ConfigParser::CFG_ENTRY _entry);//SAME AS getBool BUT WITH NO SUCCESS CHECK IF ENTRY FOUND; RETURN FALSE IF ENTRY WAS NOT FOUND 
	std::string toJson();
	bool loadFromJson(std::string _jsonstr, bool load_only_user_data); //loads config from json  load_only_user_data is TRUE = updates only the user data section with the new data from json
    bool loadFromJson(json11::Json::object _jsobj, bool load_only_user_data);

private:
    //USED IN toJson/loadFromJson
    struct KV_PAIR{
        std::string key = "";
        std::string value = "";
        KV_PAIR(std::string _k, std::string _v){
            key = _k;
            value = _v;
        }
        KV_PAIR(){
        }
    };

	static ConfigParser* instance;
	static std::mutex acces_lock_mutex;
	
	bool cfg_loaded_success = false;
	ConfigParser();
	~ConfigParser();
	//STORES THE ACUTAL CONFIG FILE
	std::map<ConfigParser::CFG_ENTRY, std::string> config_store;
	INIReader reader;
};
#endif