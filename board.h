#ifndef BOARD_H
#define BOARD_H

//In memory
//"a1"
//a = 91 decimal, 1 = 1 decimal
//91 = 2^6 + 2^4 + 2^3 + 2^1 + 2^0 = 0101 1011
//1 = 0000 0001
//"a1" = 0101 1011 0000 0001 ---> 2 Bytes * 64 = 128 Bytes needed
//nested array will look like char squares[Row][Column], eg, a1 = 'a''1''\0'



char board_squares[64][3] = {
	"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
	"b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8",
	"c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8",
	"d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8",
	"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8",
	"f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8",
	"g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8",
	"h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8",
};


#endif 
