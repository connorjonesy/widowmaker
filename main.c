#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "logic.h"
int main(){



	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);



	print_bitboard(rook_attacks_mask(d4));


	return 0;
}
