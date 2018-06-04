#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(int x, int y){
    
    this->x = x;
    this->y = y;
    
}

string IllegalCoordinateException::theCoordinate() const {
    return to_string(x) + "," + to_string(y);
}