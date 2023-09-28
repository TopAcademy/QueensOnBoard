// Class ChessBoard methods definitions
#include "ChessBoard.h"


// Default constructor
ChessBoard::ChessBoard(unsigned short sz)
{
	int i, j, k;
	this->b_size = sz;
	board = new short** [sz];
	for (i = 0; i < sz; i++) {
		board[i] = new short* [sz];
		for (int j = 0; j < sz; j++) {
			board[i][j] = new short[sz];
			for (k = 0; k < sz; k++) {
				board[i][j][k] = 0;
			}
		}
	}
}


// Display all layers of 3d-board array
void ChessBoard::display_3d(bool attacked)
{
	int z;
	for (z = 0; z < this->b_size; z++) {
		display_2d_layer(z);
		std::cout << std::endl << std::endl;
	}
}


// INNER FUNC: display one layer of 3d array - z-axis
void ChessBoard::display_2d_layer(short layer_no)
{
	short** layer = this->board[layer_no];
	int c, r;
	char cell_symbol;
	for (r = 0; r < b_size; r++) {
		for (c = 0; c < b_size; c++) {
			switch (layer[r][c]) {
				case 0: cell_symbol = EMPTY; break;
				case 1: cell_symbol = QUEEN; break;
				case -1: cell_symbol = ATTACK; break;
			}
			std::cout << cell_symbol << ' ';
		}	
		std::cout << std::endl;
	}
}


// Put queen into given position (silly)
bool ChessBoard::put_queen(short layer, short r, short c)
{
	this->board[layer][r][c] = 1;
	return true;
}