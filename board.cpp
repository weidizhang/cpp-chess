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

        pieceAt(c, 8) = createTopStartPiece(c, 8);
        pieceAt(c, 1) = createTopStartPiece(c, 1);
    }
}

Piece Board::createTopStartPiece(char letter, int num)
{
    char color = (num == 8) ? 'B' : 'W';
    switch (letter)
    {
        case 'a':
        case 'h':
            return Rook(color);

        case 'b':
        case 'g':
            return Knight(color);

        case 'c':
        case 'f':
            return Bishop(color);

        case 'd':
            return Queen(color);

        case 'e':
            return King(color);

        default:
            return Piece();
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
    out << "   a b c d e f g h" << endl;
    out << "  -----------------" << endl;

    for (int i = 8; i > 0; --i)
    {
        out << i << " ";
        for (char c = 'a'; c <= 'h'; ++c)
        {
            Piece p = b.pieceAt(c, i);
            out << "|" << p.getType();

            if (c == 'h')
                out << "| " << i;
        }

        out << endl;
    }

    out << "  -----------------" << endl;
    out << "   a b c d e f g h" << endl;

    return out;
}

Board::~Board()
{
    delete [] pieces;
}