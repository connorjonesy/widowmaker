#ifndef UTILS_H
#define UTILS_H

void print_bitboard(unsigned long long);
void print_chessboard();
int get_bit(unsigned long long, int);
void set_bit(unsigned long long*, int);
void pop_bit(unsigned long long*, int);
void init_bitboard(unsigned long long*);
int count_bits(unsigned long long);
int get_least_significant_bit(unsigned long long);
unsigned int generate_pseudo_rand_number(unsigned int*);
unsigned long long random_64bit_num(); // Tord Ramstod's proposed method
enum squares {
   a8, b8, c8, d8, e8, f8, g8, h8,
   a7, b7, c7, d7, e7, f7, g7, h7,
   a6, b6, c6, d6, e6, f6, g6, h6,
   a5, b5, c5, d5, e5, f5, g5, h5,
   a4, b4, c4, d4, e4, f4, g4, h4,
   a3, b3, c3, d3, e3, f3, g3, h3,
   a2, b2, c2, d2, e2, f2, g2, h2,
   a1, b1, c1, d1, e1, f1, g1, h1
};

enum sides { white, black };


typedef struct{
	unsigned long long bpawns;
	unsigned long long wpawns;
	unsigned long long bknights;
	unsigned long long wknights;
	unsigned long long bbishops;
	unsigned long long wbishops;
	unsigned long long brooks;
	unsigned long long wrooks;
	unsigned long long bqueen;
	unsigned long long wqueen;
	unsigned long long bking;
	unsigned long long wking;
}Pieceboards;


struct Randomstate{
	unsigned int state;
};



#endif


