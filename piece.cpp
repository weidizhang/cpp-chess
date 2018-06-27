#include "headers/piece.h"

Piece::Piece()
{
}

Piece::Piece(char newType, char newColor, int newVal)
    : type(newType), color(newColor), val(newVal)
{
}

char Piece::getType()
{
    return type;
}

char Piece::getColor()
{
    return color;
}

int Piece::getValue()
{
    return val;
}

King::King(char newColor) : Piece('K', newColor, 10000) {}
Queen::Queen(char newColor) : Piece('Q', newColor, 1000) {}
Rook::Rook(char newColor) : Piece('R', newColor, 525) {}
Bishop::Bishop(char newColor) : Piece('B', newColor, 350) {}
Knight::Knight(char newColor) : Piece('N', newColor, 350) {}
Pawn::Pawn(char newColor) : Piece('P', newColor, 100) {}
