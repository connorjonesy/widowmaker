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


unsigned long long knight_attacks_mask(int side, int square){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard,square);
	if(square % 8 != 0 && (square+1) % 8 != 0 && square > 15 && square < 48){ //file is not AB or GH, rank is not 1 2 or 7 8
		attack_board |= bitboard >> 6; 
		attack_board |= bitboard >> 10; 
		attack_board |= bitboard >> 15; 
		attack_board |= bitboard >> 17; 
		attack_board |= bitboard << 6; 
		attack_board |= bitboard << 10; 
		attack_board |= bitboard << 15; 
		attack_board |= bitboard << 17; 
	}else{ // piece file is AB or GH
		if(square % 8 == 0) // A
		     	attack_board |= bitboard >> 6;
			attack_board |= bitboard >> 15;
			attack_board |= bitboard << 10;
			attack_board |= bitboard << 17;
		if((square-1) % 8 == 0 ) // B
		     	attack_board |= bitboard >> 6;
			attack_board |= bitboard >> 15;
			attack_board |= bitboard >> 17;
			attack_board |= bitboard << 10;
			attack_board |= bitboard << 15; 
			attack_board |= bitboard << 17; 
		if((square+2) % 8 == 0) // G
		     	attack_board |= bitboard << 6;
			attack_board |= bitboard << 15;
			attack_board |= bitboard << 17;
			attack_board |= bitboard >> 17;
			attack_board |= bitboard >> 15; 
			attack_board |= bitboard >> 10; 
		if((square+1) % 8 == 0) // H
		     	attack_board |= bitboard >> 10;
			attack_board |= bitboard >> 17;
			attack_board |= bitboard << 6; 
			attack_board |= bitboard << 15; 
	}

	return attack_board;

} 
