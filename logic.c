#include "logic.h"


//params: the side to move, the pawn's current square
//objective: get a bitboard mask of possible attacks for the pawn
unsigned long long pawn_attacks_mask(int side, int square){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(bitboard, square);
	if(side){ //black
		attack_board |= bitboard << 7; //7 or 9
		attack_board |= bitboard << 9; 
	}else{ //white
		attack_board |= bitboard >> 7; 
		attack_board |= bitboard >> 9; 
	}
	//todo :: handle A and H file attack masks
}
