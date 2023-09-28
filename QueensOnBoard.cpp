
#include <iostream>
#include "ChessBoard.h"

int main()
{
	ChessBoard b(4);
	b.put_queen(0, 0, 0);
	b.put_queen(1, 1, 2);
	b.put_queen(2, 2, 0);
	b.display_3d();
}

