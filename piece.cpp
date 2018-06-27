#include "headers/piece.h"

Piece::Piece()
{    
}

Piece::Piece(char newType, int newVal)
    : type(newType), val(newVal)
{
}

char Piece::getType()
{
    return type;
}

int Piece::getValue()
{
    return val;
}