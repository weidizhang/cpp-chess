#include "headers/board.h"

Board::Board()
    : pieces(new Piece[64])
{
    createStartPieces();
}

void Board::createStartPieces()
{
    for (char c = 'a'; c <= 'h'; ++c)
    {        
        pieceAt(c, 7) = Pawn('B');
        pieceAt(c, 2) = Pawn('W');
    }
}

int Board::posToIndex(char letter, int num)
{
    int offset = 96; // 'a' is 97
    int position = (letter - offset) + ((num - 1) * 8) - 1;
    return position;
}

Piece & Board::pieceAt(char letter, int num)
{
    return pieces[posToIndex(letter, num)];
}

ostream & operator << (ostream & out, Board & b)
{
    for (int i = 8; i > 0; --i)
    {
        for (char c = 'a'; c <= 'h'; ++c)
        {
            out << c << i << ": ";
            Piece p = b.pieceAt(c, i);
            out << p.getType() << endl;
        }

        out << endl;
    }

    return out;
}

Board::~Board()
{
    delete [] pieces;
}