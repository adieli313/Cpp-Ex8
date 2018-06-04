#include "CheckBoard.h"



CheckBoard::CheckBoard(){
    setP('.');
    
}

CheckBoard::CheckBoard(char Char){
    setP(Char);
}

void CheckBoard::operator= (char Char) {
   setP(Char);
}

char CheckBoard::getP() const {
    return piece;   
}

void CheckBoard::setP(char Char){
    if (Char != '.' && Char != 'X' && Char != 'O')
    throw IllegalCharException(Char);
    piece = Char;
}

CheckBoard::operator char() const {
    return piece;
}

ostream& operator<< (ostream& os, const CheckBoard& piece) {
    os << piece.piece;
    return os;
}