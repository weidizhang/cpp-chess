#ifndef PIECE_H
#define PIECE_H

class Piece
{
    char type;
    int val;
public:
    Piece();
    Piece(char newType, int newVal);

    char getType();
    int getValue();
};

#endif