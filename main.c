#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "logic.h"
int main(){



	unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);
	set_bit(&bitboard, e4);

	bool test = pawn_blocked(e5,1,bitboard);
	printf("%d",test);
//	print_bitboard(king_attacks[d7]);
	return 0;
}
