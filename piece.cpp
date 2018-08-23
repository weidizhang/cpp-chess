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

int Piece::getColorInt()
{
    return color == 'W' ? 1 : -1;
}

int Piece::getValue()
{
    return val;
}

bool Piece::isPositionEmpty(Piece ** fullPieces, char letter, int num)
{
    return fullPieces[Board::posToIndex(letter, num)] == nullptr;
}

vector<string> Piece::getMoves(Piece ** fullPieces, char myLetter, int myNum)
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

vector<string> Pawn::getMoves(Piece ** fullPieces, char myLetter, int myNum)
{
    // TODO: implement support for en passant capture, which would require tracking the previous move on the board

    vector<string> moves;

    int fwdStep = myNum + getColorInt();
    if (isPositionEmpty(fullPieces, myLetter, fwdStep))
    {
        moves.push_back(Board::posToString(myLetter, fwdStep));

        int dblFwdStep = myNum + (2 * getColorInt());
        if (firstMove && isPositionEmpty(fullPieces, myLetter, dblFwdStep))
            moves.push_back(Board::posToString(myLetter, dblFwdStep));
    }

    // TODO: implement adding possible captures
    // POSSIBLE TODO: split normal moves & capture moves into two different functions, then getMoves returns
    // returns both returned move vectors combined.

    return moves;
}