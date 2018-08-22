#include "headers/piece.h"
#include "headers/board.h"

Piece::Piece()
    : type(' ')
{
}

Piece::Piece(char newType, char newColor, int newVal)
    : type(newType), color(newColor), val(newVal)
{
}

char Piece::getType()
{
    return type;
}

char Piece::getColor()
{
    return color;
}

int Piece::getValue()
{
    return val;
}

bool Piece::isPositionEmpty(Piece ** fullPieces, int index)
{
    return fullPieces[index] == nullptr;
}

vector<string> Piece::getMoves(Piece ** fullPieces, int myIndex)
{
    return vector<string>();
}

Piece::~Piece()
{
}

King::King(char newColor) : Piece('K', newColor, 10000) {}
Queen::Queen(char newColor) : Piece('Q', newColor, 1000) {}
Rook::Rook(char newColor) : Piece('R', newColor, 525) {}
Bishop::Bishop(char newColor) : Piece('B', newColor, 350) {}
Knight::Knight(char newColor) : Piece('N', newColor, 350) {}
Pawn::Pawn(char newColor) : Piece('P', newColor, 100), firstMove(true) {}

vector<string> Pawn::getMoves(Piece ** fullPieces, int myIndex)
{
    // TODO: implement support for en passant capture, which would require tracking the previous move on the board

    vector<string> moves;

    int stepOffset = getColor() == 'W' ? 8 : -8;
    int fwdStep = myIndex + stepOffset;
    if (isPositionEmpty(fullPieces, fwdStep))
    {
        moves.push_back(Board::indexToString(fwdStep));

        int dblFwdStep = myIndex + (2 * stepOffset);
        if (firstMove && isPositionEmpty(fullPieces, dblFwdStep))
            moves.push_back(Board::indexToString(dblFwdStep));
    }

    return moves;
}