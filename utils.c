#include <stdio.h>
#include "utils.h"
int get_bit(unsigned long long bitboard, int square){
	return (bitboard & (1ULL << square)) != 0; //returns 1 if square is occupied
}

void set_bit(unsigned long long *bitboard, int target){
	*bitboard |= (1ULL << target);

}
void pop_bit(unsigned long long *bitboard, int target){
	if(*bitboard & (1ULL << target))
		*bitboard &= ~(1ULL << target);
	else
		printf("Error: Nothing to Pop, my lord\n");
	
}
void init_bitboard(unsigned long long *bitboard){
	//init white pieces
	for(int i=63; i >=48; i--){
		set_bit(bitboard, i);
	}
	//init black pieces
	for(int i=0; i<16;i++){
		set_bit(bitboard, i);
	}

}
void print_bitboard(unsigned long long  bitboard){
	printf("\n//// Printing Bitboard %c%c%c%c \n\n", 92, 92, 92, 92);

	for(int rank = 0; rank <8; rank++){
		for(int file = 0; file < 8; file++){
			//convert file and rank into square index 0-63
			int square = rank * 8 + file;

			//print ranks
			if(!file){
				printf("%d  ", 8 - rank);
			}	

			printf("%d ", get_bit(bitboard,square));
		}
		printf("\n");
	
	}
	printf("\n   %c %c %c %c %c %c %c %c \n", 65,66,67,68,69,70,71,72);
	printf("Bitboard: 0x%llx\n", bitboard);
}

void print_chessboard(){

	printf("\n//// Printing Chessboard %c%c%c%c \n\n", 92, 92, 92, 92);

	for(int rank = 8; rank > 0; rank--){
		printf("\n   a%d, b%d, c%d, d%d, e%d, f%d, g%d, h%d,", rank, rank, rank, rank, rank, rank, rank, rank);
	}
	//future use
	//for(int rank = 8; rank > 0; rank--){
	//	printf("\n  \" a%d\", \"b%d\", \"c%d\", \"d%d\", \"e%d\", \"f%d\", \"g%d\", \"h%d\",", rank, rank, rank, rank, rank, rank, rank, rank);
	//}
	printf("\n");
}
