#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

using namespace std;

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
    bool isPositionEmpty(Piece ** fullPieces, int index);

    virtual vector<string> getMoves(Piece ** fullPieces, int myIndex);

    virtual ~Piece();
};

struct King : public Piece { King(char newColor); };
struct Queen : public Piece { Queen(char newColor); };
struct Rook : public Piece { Rook(char newColor); };
struct Bishop : public Piece { Bishop(char newColor); };
struct Knight : public Piece { Knight(char newColor); };

class Pawn : public Piece
{
    bool firstMove;
public:
    Pawn(char newColor);

    virtual vector<string> getMoves(Piece ** fullPieces, int myIndex);
};

#endif