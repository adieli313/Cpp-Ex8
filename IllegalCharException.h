
#ifndef ILLEGALCHAREXCEPTION_HPP
#define ILLEGALCHAREXCEPTION_HPP


#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IllegalCharException : public exception {

    public:
    
        IllegalCharException(char Char);
    
       // IllegalCharException(int x, int y);
    
        char TheChar() const;

       // string getPoint() const;

    protected:

    private:

        int x , y;
        char Char;
};

#endif 
