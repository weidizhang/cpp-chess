#ifndef PIECE_H
#define PIECE_H

class Piece
{
    char type;
    char color;
    int val;
public:
    Piece();
    Piece(char newType, char newColor, int newVal);

    char getType();
    char getColor();
    int getValue();
};

struct King : public Piece { King(char newColor); };
struct Queen : public Piece { Queen(char newColor); };
struct Rook : public Piece { Rook(char newColor); };
struct Bishop : public Piece { Bishop(char newColor); };
struct Knight : public Piece { Knight(char newColor); };
struct Pawn : public Piece { Pawn(char newColor); };

#endif