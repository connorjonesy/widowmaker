#include <stdio.h>
#include "utils.h"
#include <stdint.h>
int main(){
	uint64_t bitboard = 65535ULL; //Prints the black starting positions
	printBitboard(bitboard);
	printChessboard();
	return 0;
}
