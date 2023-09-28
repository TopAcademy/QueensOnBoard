#pragma once
#include <iostream>

class ChessBoard
{
private:
	const static char QUEEN = '#';
	const static char EMPTY = '.';
	const static char ATTACK = 'x';
	unsigned short b_size;
	short*** board;
private:
	void display_2d_layer(short layer_no);
public:
	ChessBoard(unsigned short sz = 8);
	void display_3d(bool attacked = false);
	bool put_queen(short layer, short r, short c);
};
