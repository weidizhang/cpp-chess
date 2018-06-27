#ifndef PIECE_H
#define PIECE_H

class Piece
{
    char type;
    int val;
public:
    Piece(char newType = '\0', int newVal = 0);

    char getType();
    int getValue();
};

#endif