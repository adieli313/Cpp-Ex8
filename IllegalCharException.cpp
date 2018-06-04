#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char Char) {
    this->Char = Char;
}

char IllegalCharException::TheChar() const {
    return Char;
}
