#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "logic.h"
int main(){


	struct Randomstate *state_ptr;
	state_ptr = (struct Randomstate *)malloc(sizeof(struct Randomstate));


	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);


	for(int r = 0; r < 8; r++){
		for(int f = 0; f < 8; f++){
			int square = r * 8 + f;
			printf(" %d,", count_bits(rook_attacks_mask(square)));
		}
		printf("\n");
	
	}


	return 0;
}
