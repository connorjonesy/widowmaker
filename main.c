#include <stdio.h>
#include "utils.h"
int main(){
	unsigned long long bitboard = 0ULL; 
	init_bitboard(&bitboard);
	print_bitboard(bitboard);
	return 0;
}
