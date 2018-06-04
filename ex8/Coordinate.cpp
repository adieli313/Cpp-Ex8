#include "Coordinate.h"

Coordinate::Coordinate(){
    this->row = 0;
    this->col = 0;
}

Coordinate::Coordinate(const uint x, const uint y){
    this->row = x;
    this->col = y;
}

void Coordinate::setRow(uint row){
    this->row = row;
}

void Coordinate::setCol(uint col){
    this->col = col;
}

int Coordinate::getRow() const{
    return this->row;
}

int Coordinate::getCol() const{
    return this->col;
}

 ostream& operator<< (ostream& out, const Coordinate& c) {
	return (out << c.getRow() << "," << c.getCol());
}