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

bool Piece::isPositionInBounds(char letter, int num)
{
    return letter >= 'a' && letter <= 'h' && num >= 1 && num <= 8;
}

bool Piece::isOpponentPiece(Piece ** fullPieces, char letter, int num)
{
    Piece * p = fullPieces[Board::posToIndex(letter, num)];
    return p != nullptr && p->getColor() != getColor();
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
    if (isPositionInBounds(myLetter, fwdStep) && isPositionEmpty(fullPieces, myLetter, fwdStep))
    {
        moves.push_back(Board::posToString(myLetter, fwdStep));

        int dblFwdStep = myNum + (2 * getColorInt());
        if (firstMove && isPositionEmpty(fullPieces, myLetter, dblFwdStep)) // no need for bound check because it must be in bounds if it is the first move
            moves.push_back(Board::posToString(myLetter, dblFwdStep));
    }

    char leftL = myLetter - getColorInt();
    char rightL = myLetter + getColorInt();
    
    if (isPositionInBounds(leftL, fwdStep) && isOpponentPiece(fullPieces, leftL, fwdStep))
        moves.push_back(Board::posToString(leftL, fwdStep));
    if (isPositionInBounds(rightL, fwdStep) && isOpponentPiece(fullPieces, rightL, fwdStep))
        moves.push_back(Board::posToString(rightL, fwdStep));    

    return moves;
}