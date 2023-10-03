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


// Попытка установки ферзя на позицию [r;c] на слой layer
// Возвращаем true, если ферзь установлен
// или false в противном случае (ячейка пробивается или уже занята)
bool ChessBoard::put_queen(short layer, short r, short c)
{
	// Проверяем, не бито ли поле, куда пытаемся поставить ферзя
	bool under_attack = false;
	// ...
	if (under_attack) return false;

	// Если мы здесь, значит на поле [r;c] можно ставить ферзя

	// Помечаем пробиваемые ферзем ячейки

	// Помечаем горизонталь и вертикаль, на которой находится ферзь
	for (int i = 0; i < this->b_size; i++) {
		this->board[layer][i][c] = -1;
		this->board[layer][r][i] = -1;
	}
		
	// Помечаем две диагонали
	// 1. Диагональ "сверху вниз"
	short r_start = (r > c) ? (r - c) : 0;
	short c_start = (c > r) ? (c - r) : 0;

	for (int i = r_start, j = c_start; (i < b_size) && (j < b_size); j++, i++)
	{
		board[layer][j][i] = -1;
	}

	// 2. Диагональ "снизу вверх"
	// 3 - r == c;
	//r - строка
	//с - столбец/колонка
	r_start = ((b_size - 1 - r) > c) ? (r+c) : b_size-1; //Определили левое нижнее начало диагонали
	c_start = (c < r) ? (c - r) : 0; //Не завершено !!!!!!!!!!!!!!!!!!!!!!

	// Наконец, ставим ферзя
	this->board[layer][r][c] = 1;
	return true;
}