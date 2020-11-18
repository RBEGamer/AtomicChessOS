#pragma once
class ChessField
{
	
	
	
public:
	ChessField();
	~ChessField();
	
	
	
	
	
	enum CHESS_FILEDS
	{
		CHESS_FIELD_A1                    = 0,
		CHESS_FIELD_A2                    = 1,
		CHESS_FIELD_A3                    = 2,
		CHESS_FIELD_A4                    = 3,
		CHESS_FIELD_A5                    = 4,
		CHESS_FIELD_A6                    = 5,
		CHESS_FIELD_A7                    = 6,
		CHESS_FIELD_A8                    = 7,
		
		CHESS_FIELD_B1                    = 8,
		CHESS_FIELD_B2                    = 9,
		CHESS_FIELD_B3                    = 10,
		CHESS_FIELD_B4                    = 11,
		CHESS_FIELD_B5                    = 12,
		CHESS_FIELD_B6                    = 13,
		CHESS_FIELD_B7                    = 14,
		CHESS_FIELD_B8                    = 15,
		
		CHESS_FIELD_C1                    = 16,
		CHESS_FIELD_C2                    = 17,
		CHESS_FIELD_C3                    = 18,
		CHESS_FIELD_C4                    = 19,
		CHESS_FIELD_C5                    = 20,
		CHESS_FIELD_C6                    = 21,
		CHESS_FIELD_C7                    = 22,
		CHESS_FIELD_C8                    = 23,
		
		CHESS_FIELD_D1                    = 24,
		CHESS_FIELD_D2                    = 25,
		CHESS_FIELD_D3                    = 26,
		CHESS_FIELD_D4                    = 27,
		CHESS_FIELD_D5                    = 28,
		CHESS_FIELD_D6                    = 29,
		CHESS_FIELD_D7                    = 30,
		CHESS_FIELD_D8                    = 31,
		
		CHESS_FIELD_E1                    = 32,
		CHESS_FIELD_E2                    = 33,
		CHESS_FIELD_E3                    = 34,
		CHESS_FIELD_E4                    = 35,
		CHESS_FIELD_E5                    = 36,
		CHESS_FIELD_E6                    = 37,
		CHESS_FIELD_E7                    = 38,
		CHESS_FIELD_E8                    = 39,

		CHESS_FIELD_F1                    = 40,
		CHESS_FIELD_F2                    = 41,
		CHESS_FIELD_F3                    = 42,
		CHESS_FIELD_F4                    = 43,
		CHESS_FIELD_F5                    = 44,
		CHESS_FIELD_F6                    = 45,
		CHESS_FIELD_F7                    = 46,
		CHESS_FIELD_F8                    = 47,

		CHESS_FIELD_G1                    = 48,
		CHESS_FIELD_G2                    = 49,
		CHESS_FIELD_G3                    = 50,
		CHESS_FIELD_G4                    = 51,
		CHESS_FIELD_G5                    = 52,
		CHESS_FIELD_G6                    = 53,
		CHESS_FIELD_G7                    = 54,
		CHESS_FIELD_G8                    = 55,

		CHESS_FIELD_H1                    = 56,
		CHESS_FIELD_H2                    = 57,
		CHESS_FIELD_H3                    = 58,
		CHESS_FIELD_H4                    = 59,
		CHESS_FIELD_H5                    = 60,
		CHESS_FIELD_H6                    = 61,
		CHESS_FIELD_H7                    = 62,
		CHESS_FIELD_H8                    = 63,
		
		
		CHESS_FIELD_PARK_POSTION_WHITE_1  = 64,
		CHESS_FIELD_PARK_POSTION_WHITE_2  = 65,
		CHESS_FIELD_PARK_POSTION_WHITE_3  = 66,
		CHESS_FIELD_PARK_POSTION_WHITE_4  = 67,
		CHESS_FIELD_PARK_POSTION_WHITE_5  = 68,
		CHESS_FIELD_PARK_POSTION_WHITE_6  = 69,
		CHESS_FIELD_PARK_POSTION_WHITE_7  = 70,
		CHESS_FIELD_PARK_POSTION_WHITE_8  = 71,
		CHESS_FIELD_PARK_POSTION_WHITE_9  = 72,
		CHESS_FIELD_PARK_POSTION_WHITE_10 = 73,
		CHESS_FIELD_PARK_POSTION_WHITE_11 = 74,
		CHESS_FIELD_PARK_POSTION_WHITE_12 = 75,
		CHESS_FIELD_PARK_POSTION_WHITE_13 = 76,
		CHESS_FIELD_PARK_POSTION_WHITE_14 = 77,
		CHESS_FIELD_PARK_POSTION_WHITE_15 = 78,
		CHESS_FIELD_PARK_POSTION_WHITE_16 = 79,
		
		CHESS_FIELD_PARK_POSTION_BLACK_1  = 80,
		CHESS_FIELD_PARK_POSTION_BLACK_2  = 81,
		CHESS_FIELD_PARK_POSTION_BLACK_3  = 82,
		CHESS_FIELD_PARK_POSTION_BLACK_4  = 83,
		CHESS_FIELD_PARK_POSTION_BLACK_5  = 84,
		CHESS_FIELD_PARK_POSTION_BLACK_6  = 85,
		CHESS_FIELD_PARK_POSTION_BLACK_7  = 86,
		CHESS_FIELD_PARK_POSTION_BLACK_8  = 87,
		CHESS_FIELD_PARK_POSTION_BLACK_9  = 88,
		CHESS_FIELD_PARK_POSTION_BLACK_10 = 89,
		CHESS_FIELD_PARK_POSTION_BLACK_11 = 90,
		CHESS_FIELD_PARK_POSTION_BLACK_12 = 91,
		CHESS_FIELD_PARK_POSTION_BLACK_13 = 92,
		CHESS_FIELD_PARK_POSTION_BLACK_14 = 93,
		CHESS_FIELD_PARK_POSTION_BLACK_15 = 94,
		CHESS_FIELD_PARK_POSTION_BLACK_16 = 95
		
	};
	
	static int field2Index(ChessField::CHESS_FILEDS _field);
};
