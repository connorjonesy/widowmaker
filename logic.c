#include "logic.h"
#include "utils.h"

//params: the side to move, the pawn's current square
//objective: get a bitboard mask of possible attacks for the pawn
unsigned long long pawn_attacks_mask(int side, int square){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	if(square % 8 != 0 && (square+1) % 8 != 0){ //file is not A or H
		if(side){ //black
			attack_board |= bitboard << 7; //7 or 9
			attack_board |= bitboard << 9; 
		}else{ //white
			attack_board |= bitboard >> 7; 
			attack_board |= bitboard >> 9; 
		}
	}else{ // piece file is A or H
		if(side){ // black
			if ((square+1) % 8 ==0) // file is H
				attack_board |= bitboard << 7;
			else // file is A
				attack_board |= bitboard << 9; 
		}else{ //white
		       	if (square % 8 == 0) //file is A
				attack_board |= bitboard >> 7;
		       	else //file is H
				attack_board |= bitboard >> 9; 
		}
	}	

	return attack_board;
} // confirmed this works but probably sucks because so many ifs... 
