#ifndef CHECKBOARD_H
#define CHECKBOARD_H

#include <iostream>


#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

using namespace std;

class CheckBoard {

    public:

        //Constructor.
        
        CheckBoard();
        
        CheckBoard(char Char);

        //Operator

        void operator= (char Char);

        operator char() const;
    
        void setP(char Char);
        
        char getP() const;

        
   
        //Variables of the object.
        char piece;
        
        friend ostream& operator<< (ostream& os, const CheckBoard& piece);
};

#endif
