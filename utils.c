#include <stdio.h>
#include <stdint.h>
#include "utils.h"
int getBit(uint64_t bitboard, int square){
	return bitboard & (1ULL << square);
}

void setBit(uint64_t bitboard, int target){} //TODO

void printBitboard(uint64_t bitboard){
	printf("\n//// Printing Bitboard %c%c%c%c \n\n", 92, 92, 92, 92);

	for(int rank = 0; rank <8; rank++){
		for(int file = 0; file < 8; file++){
			//convert file and rank into square index 0-63
			int square = rank * 8 + file;

			//print ranks
			if(!file){
				printf("%d  ", 8 - rank);
			}	

			printf("%d ", getBit(bitboard,square) ? 1 : 0); // print a 1 square is occupied
		}
		printf("\n");
	
	}
	printf("\n   %c %c %c %c %c %c %c %c \n", 65,66,67,68,69,70,71,72);
}

void printChessboard(){

	printf("\n//// Printing Chessboard %c%c%c%c \n\n", 92, 92, 92, 92);

	for(int rank = 8; rank > 0; rank--){
		printf("\n   a%d b%d c%d d%d e%d f%d g%d h%d", rank, rank, rank, rank, rank, rank, rank, rank);
	}
	printf("\n");
}
