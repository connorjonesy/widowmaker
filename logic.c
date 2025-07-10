#include "logic.h"
#include <stdbool.h>
#include "utils.h"
#include <stdio.h>

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


unsigned long long knight_attacks_mask(int square){
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

unsigned long long bishop_attacks_mask(int square){ 
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	int test_square = square; //iterator
	//Northeast Diagonal
	while( (test_square+1) % 8 != 0 && (test_square+2) % 8 != 0 && test_square > 15 ){ //while NOT on G,H file AND NOT on 7,8th rank, keep adding to bitboard northeast diag
		attack_board |= bitboard >> 7;
		test_square -= 7;
		bitboard >>= 7;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Southeast Diagonal
	while(  (test_square+1) % 8 != 0 && (test_square+2) % 8 != 0 && test_square < 48 ){ //while NOT on G,H file AND NOT on 1,2nd rank, keep adding to bitboard Souththeast diag
		attack_board |= bitboard << 9;
		test_square += 9;
		bitboard <<=9;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Northwest Diagonal
	while(  (test_square-1) % 8 != 0 && test_square % 8 != 0 && test_square > 15 ){ //while NOT on A,B file AND NOT on 7,8th rank, keep adding to bitboard northwest diag
		attack_board |= bitboard >> 9;
		test_square -= 9;
		bitboard >>=9;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Southwest Diagonal
	while( (test_square-1) % 8 != 0 && test_square % 8 != 0 && test_square < 48 ){ //while NOT on A,B file AND NOT on 1,2nd rank, keep adding to bitboard southwest diag
		attack_board |= bitboard << 7;
		test_square += 7;
		bitboard <<=7;
	}
	return attack_board;
	
}

unsigned long long rook_attacks_mask(int square){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	int test_square = square; //iterator
	//east
	while( ((test_square+2) % 8 != 0 && test_square+1) % 8 != 0 ){ //while NOT on H,G file
		attack_board |= bitboard << 1;
		test_square += 1;
		bitboard <<= 1;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//west
	while((test_square-1) % 8 != 0 && test_square % 8 != 0 ){ //while NOT on A,B file
		attack_board |= bitboard >> 1;
		test_square -= 1;
		bitboard >>= 1;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//north
	while( test_square > 15 ){ //while NOT on 7,8th rank
		attack_board |= bitboard >> 8;
		test_square -= 8;
		bitboard >>= 8;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//south
	while( test_square < 48){ //while NOT on 1,2nd rank
		attack_board |= bitboard << 8;
		test_square += 8;
		bitboard <<= 8;
	}
	return attack_board;
}


unsigned long long queen_attacks_mask(int square){
	unsigned long long rook_attack_board = rook_attacks_mask(square);
	unsigned long long bishop_attack_board = bishop_attacks_mask(square);
	return rook_attack_board | bishop_attack_board;
}

unsigned long long king_attacks_mask(int square){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	if( (square+1) % 8 != 0) // not on H file
		attack_board |= bitboard << 1;
	if( (square+1) % 8 != 0 && square > 7 )//while NOT on H file AND NOT on 8th rank, add to bitboard northeast diag
		attack_board |= bitboard >> 7;
	if( square % 8 != 0) // not on A file
		attack_board |= bitboard >> 1;
	if( square % 8 != 0 && square > 7 )//while NOT on A file AND NOT on 8th rank, add to bitboard northwest diag
		attack_board |= bitboard >> 9;
	if( square < 56) // not on 1st rank
		attack_board |= bitboard << 8;
	if( (square+1) % 8 != 0 && square < 56 )//while NOT on H file AND NOT on 1st rank, add to bitboard southeast diag
		attack_board |= bitboard << 9;
	if( square > 7) // not on 8th rank
		attack_board |= bitboard >> 8;
	if( square % 8 != 0 && square < 56 )//while NOT on A file AND NOT on 1st rank, add to bitboard southwest diag
		attack_board |= bitboard << 7;
	return attack_board;
}

bool pawn_blocked(int square, int side, unsigned long long game_board){

	if(side){ //black
		if( (((1ULL << square) << 8) & game_board) !=0 ) //pawn is blocked
			return true;
	}else{ //white
		if( (((1ULL << square) >> 8) & game_board) !=0 ) //pawn is blocked
			return true;
	}
	return false;
}


//MAGIC BITBOARDS\\

unsigned long long generate_bishop_attacks(int square, unsigned long long occupied){
	
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	int test_square = square; //iterator
	//Northeast Diagonal
	while( (test_square+1) % 8 != 0  && test_square > 7 ){ //while NOT on H file AND NOT on 8th rank AND next spot isn't occupied, keep adding to bitboard northeast diag
		attack_board |= bitboard >> 7;
		test_square -= 7;
		bitboard >>= 7;
		if(bitboard & occupied) break;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Southeast Diagonal
	while(  (test_square+1) % 8 != 0 && test_square < 56 ){ //while NOT on H file AND NOT on 1st rank AND ..., keep adding to bitboard Souththeast diag
		attack_board |= bitboard << 9;
		test_square += 9;
		bitboard <<=9;
		if(bitboard & occupied) break;
	
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Northwest Diagonal
	while( test_square % 8 != 0 && test_square > 7 ){ //while NOT on A file AND NOT on 8th rank AND ..., keep adding to bitboard northwest diag
		attack_board |= bitboard >> 9;
		test_square -= 9;
		bitboard >>=9;
		if(bitboard & occupied) break;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//Southwest Diagonal
	while( test_square % 8 != 0 && test_square < 56 ){ //while NOT on A file AND NOT on 1st rank AND ..., keep adding to bitboard southwest diag
		attack_board |= bitboard << 7;
		test_square += 7;
		bitboard <<=7;
		if(bitboard & occupied) break;
	}
	return attack_board;


}

unsigned long long generate_rook_attacks(int square, unsigned long long occupied){
	unsigned long long attack_board = 0ULL;
	unsigned long long bitboard = 0ULL;
	set_bit(&bitboard, square);
	int test_square = square; //iterator
	//east
	while( (test_square+1) % 8 != 0 ){ //while NOT on H file
		attack_board |= bitboard << 1;
		test_square += 1;
		bitboard <<= 1;
		if(bitboard & occupied) break;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//west
	while(test_square % 8 != 0 ){ //while NOT on A file
		attack_board |= bitboard >> 1;
		test_square -= 1;
		bitboard >>= 1;
		if(bitboard & occupied) break;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//north
	while( test_square > 7 ){ //while NOT on 8th rank
		attack_board |= bitboard >> 8;
		test_square -= 8;
		bitboard >>= 8;
		if(bitboard & occupied) break;
	}
	test_square = square; //reset
	bitboard = 0ULL;
	set_bit(&bitboard, square);

	//south
	while( test_square < 56){ //while NOT on 1st rank
		attack_board |= bitboard << 8;
		test_square += 8;
		bitboard <<= 8;
		if(bitboard & occupied) break;
	}
	return attack_board;
}
