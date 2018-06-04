#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "CheckBoard.h"
#include "Coordinate.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

using namespace std;
    
static int file_num = 0;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board {
    public:
    
        
        Board();
        
        Board(const int squer);
        
        Board(const Board& board); 
        
        ~Board();
        
        const Board& operator= (char Char) const;
        
        Board& operator= (const Board& board);

        CheckBoard& operator [](vector<int> point);
        
        CheckBoard& operator [](Coordinate coordinate) const;
        
        
        friend istream& operator>> (istream& is, Board& b);
        friend ostream& operator<< (ostream& os, const Board& board);
        
        void printBoard();
        
        int size() const;
        
        void setBoard(const int dimension);
        
        void setDimension(const int dimension);
        
        void setMatrix(const int dimension);
        
        string draw(int const squer);
    
        CheckBoard** board;
        int squer;

};

#endif

