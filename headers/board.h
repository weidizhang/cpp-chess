#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "piece.h"

using namespace std;

class Board
{
    Piece ** pieces;

    void createStartPieces();
    Piece * createTopStartPiece(char letter, int num);
public:
    Board();

    Piece *& pieceAt(char letter, int num);
    vector<string> validMovesForPieceAt(char letter, int num);

    static int posToIndex(char letter, int num);
    static pair<char, int> indexToPos(int index);
    static string indexToString(int index);

    friend ostream & operator << (ostream & out, Board & b);

    ~Board();
};

#endif