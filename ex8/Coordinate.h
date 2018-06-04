#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Coordinate {

    public:
    
    	Coordinate();
    	
    	Coordinate(const uint x,const uint y);
    	
    	void setRow(uint row);
    	
    	void setCol(uint col);
    	
    	int getRow() const;
    	
    	int getCol() const;
    	
    	friend ostream& operator<< (ostream& out, const Coordinate& c);
    	
    protected:

    private:
    
		int row;
		int col;
};

#endif
