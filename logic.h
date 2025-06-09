#ifndef LOGIC_H
#define LOGIC_H

//pawn attacks table [side] [sqaure]
unsigned long long pawn_attacks[2][64];
//get pawn attacks
unsigned long long pawn_attacks_mask(int, int);



#endif
