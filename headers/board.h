#include <iostream>
#include "piece.h"

using namespace std;

class Board
{
    Piece * pieces;

    void createStartPieces();
    int posToIndex(char letter, int num);
public:
    Board();

    Piece & pieceAt(char letter, int num);
    friend ostream & operator << (ostream & out, Board & b);

    ~Board();
};