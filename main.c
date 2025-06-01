#include <stdio.h>
#include "utils.h"
int main(){
	unsigned long long bitboard = 0ULL; 
	setBit(&bitboard, e2);
	printBitboard(bitboard);
	popBit(&bitboard, e2);
	printBitboard(bitboard);
	popBit(&bitboard, e2);
	return 0;
}
