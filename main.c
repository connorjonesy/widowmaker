#include <stdio.h>
#include "utils.h"
#include "logic.h"
int main(){

	for(int i=0; i < 64; i++){
		printf("%lluULL, ", bishop_attacks_mask(i));
	}
	printf("\n");

	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);
	

	print_bitboard(bishop_attacks[h8]);
	return 0;
}
