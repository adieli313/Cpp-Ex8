#pragma once

#include <iostream>


#include "Player.h"

using namespace std;

class Champion : public Player{

    public:
    
        const string name() const override { return "Ido & Adiel"; }
        
        const Coordinate play(const Board& board) override;
        
    protected:

    private:
    
};

