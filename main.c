#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "logic.h"
int main(){



	//unsigned long long bitboard = 0ULL; 
	//init_bitboard(&bitboard);

	//init occupancy
	unsigned long long occupied = 0ULL;
	set_bit(&occupied, b6);
	set_bit(&occupied, g7);
	set_bit(&occupied, e3);
	int bits = count_bits(occupied);
	printf("%d", bits);
	print_bitboard(occupied);
	print_bitboard(generate_rook_attacks(b1, occupied));


	return 0;
}
