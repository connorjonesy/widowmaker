#include <stdio.h>
#include "utils.h"
#include "logic.h"
int main(){
/*

	for(int i=0; i < 64; i++){
		printf("%llu , ", knight_attacks_mask(white, i));
	}
	printf("\n");
	for(int i=0; i < 64; i++){
		printf("%llu , ", knight_attacks_mask(black, i));
	}

*/
	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);
	

	print_bitboard(knight_attacks[black][e4]);
	return 0;
}
