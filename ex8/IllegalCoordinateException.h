#ifndef ILLEGALCOORDINATEEXCEPTION_H
#define ILLEGALCOORDINATEEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
#include <vector>

using namespace std;

class IllegalCoordinateException : public exception{
    
    public:
    
    IllegalCoordinateException(int x, int y);
    
    string theCoordinate() const;
    
    private:
        
    int x;
    int y;
    
};

#endif
