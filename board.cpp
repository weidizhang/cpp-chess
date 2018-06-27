#include "headers/board.h"

Board::Board()
    : pieces(new Piece[64])
{
}

Board::~Board()
{
    delete [] pieces;
}