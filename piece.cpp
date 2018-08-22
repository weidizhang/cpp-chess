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

vector<string> Piece::getMoves(Piece ** fullPieces, int myIndex)
{
    cout << "DEBUG Piece::getMoves called" << endl;
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
Pawn::Pawn(char newColor) : Piece('P', newColor, 100), firstMove(false) {}


vector<string> Pawn::getMoves(Piece ** fullPieces, int myIndex)
{
    // TODO: implement support for en passant capture, which would require tracking the previous move on the board

    vector<string> moves;

    int fwdStep = myIndex + (getColor() == 'W' ? 8 : -8);
    //int fwdStepFirstMove = firstMove ? fwdStep * 2 : 0; // if non 0 and not taken add this?

    moves.push_back(Board::indexToString(fwdStep)); // add check if that spot is taken on board;
    cout << "DEBUG Pawn::getMoves called" << endl; // not printed

    return moves;
}