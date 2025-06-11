#include <stdio.h>
#include "utils.h"
#include "logic.h"
int main(){
	unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);
	unsigned long long tester = pawn_attacks_mask(1,a5);
	print_bitboard(tester);
	return 0;
}
