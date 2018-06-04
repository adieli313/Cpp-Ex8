#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Board.h"

using namespace std;


class Player {

    public:
    
        char myChar;
    
        virtual const string name() const{ return "Player"; }
        
        virtual const Coordinate play(const Board& board) { return {0,0}; }
        
        char getChar() const;
        
        void setChar(char Char);
        
        
    protected:

    private:
    
    //char myChar;
    
};

#endif
