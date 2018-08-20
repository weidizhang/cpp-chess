#include "headers/board.h"
#include "headers/piece.h"

int main()
{
    Board b;
    cout << b;

    vector<string> moves = b.validMovesForPieceAt('e', 2);
    //for (auto pos : moves)
    //    cout << pos << endl;

    return 0;
}