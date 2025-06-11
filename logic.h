#ifndef LOGIC_H
#define LOGIC_H

//pawn attacks table [side] [square]
//unsigned long long pawn_attacks[2][64]; //hold pawn attack masks for easy lookup
//get pawn attacks
unsigned long long pawn_attacks_mask(int, int);



#endif
