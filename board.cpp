#include "headers/board.h"

Board::Board()
    : pieces(new Piece*[64])
{
    createStartPieces();
}

void Board::createStartPieces()
{
    for (char c = 'a'; c <= 'h'; ++c)
    {        
        pieceAt(c, 7) = new Pawn('B');
        pieceAt(c, 2) = new Pawn('W');

        pieceAt(c, 8) = createTopStartPiece(c, 8);
        pieceAt(c, 1) = createTopStartPiece(c, 1);
    }
}

Piece * Board::createTopStartPiece(char letter, int num)
{
    char color = (num == 8) ? 'B' : 'W';
    switch (letter)
    {
        case 'a':
        case 'h':
            return new Rook(color);

        case 'b':
        case 'g':
            return new Knight(color);

        case 'c':
        case 'f':
            return new Bishop(color);

        case 'd':
            return new Queen(color);

        case 'e':
            return new King(color);

        default:
            return nullptr;
    }
}

int Board::posToIndex(char letter, int num)
{
    /*
     * The board is represented with a1 being index 0, a2 being index 1,
     * b1 being index 8, b2 being index 9, etc.
     */   

    int offset = 96; // 'a' is 97
    int position = (letter - offset) + ((num - 1) * 8) - 1;
    return position;
}

pair<char, int> Board::indexToPos(int index)
{
    char letter = (index % 8) + 97;
    int num = (index / 8) + 1;
    return make_pair(letter, num);
}

string Board::indexToString(int index)
{
    pair<char, int> pos = indexToPos(index);

    string s;
    s.push_back(pos.first);
    s += to_string(pos.second);
    return s;
}

Piece *& Board::pieceAt(char letter, int num)
{
    return pieces[posToIndex(letter, num)];
}

vector<string> Board::validMovesForPieceAt(char letter, int num)
{
    Piece * p = pieceAt(letter, num);
    int index = posToIndex(letter, num);

    vector<string> moves = p->getMoves(pieces, index);
    return moves;
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
            Piece * p = b.pieceAt(c, i);
            char type = (p == nullptr) ? ' ' : p->getType();

            out << "|" << type;

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
    for (int i = 0; i < 64; ++i)
        if (pieces[i] != nullptr)
            delete pieces[i];
    delete [] pieces;
}