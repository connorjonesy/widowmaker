#include <stdio.h>
#include <stdint.h>
#include "utils.h"
void printBitboard(uint64_t bitboard){
	printf("printing bitboard\n");

	for(int rank = 0; rank <8; rank++){
		for(int file = 0; file < 8; file++){
			//convert file and rank into square index
			int square = rank * 8 + file; 

			printf("%d ", (bitboard & (1ULL << square)) ? 1 : 0); // print a 1 if piece is on this square
		}
		printf("\n");
	
	}
}
