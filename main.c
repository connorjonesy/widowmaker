#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"
#include "logic.h"
int main(){

	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);

	struct Randomstate *struct_ptr;
	struct_ptr = (struct Randomstate *)malloc(sizeof(struct Randomstate));
	struct_ptr->state = 1804289383; //pseudo rand from c random function
	printf("%lld \n", random_64bit_num(&struct_ptr->state));


/*
	for(int r = 0; r < 8; r++){
		for(int f = 0; f < 8; f++){
			int square = r * 8 + f;
			printf(" %d,", count_bits(rook_attacks_mask(square)));
		}
		printf("\n");
	
	}

*/	


	free(struct_ptr);
	return 0;
}
