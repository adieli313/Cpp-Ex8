#include "Champion.h"

using namespace std;


    const Coordinate Champion::play(const Board& board) {
    	
    	int count = 0;
    	int length = board.size() - 1;
    	
    	uint x1 = 0, x2 = length, y1 = 0, y2 = length;
    	
    	bool flag = true;
    	
    	while(count < board.size()){
    		
    		if(flag){
    			Coordinate coordinate{x1,y2};
    			
    			x1++;
    			y2--;
    			
    			flag = false;
    			count++;
    			
    			if(board[coordinate] == '.'){
    				return coordinate;
    			}
    			
    		}
    		
    		else{
    			Coordinate coordinate{x2,y1};
    			
    			x2--;
    			y1++;
    			
    			flag = true;
    			count++;
    			
    			if(board[coordinate] == '.'){
    				return coordinate;
    			
    			}
    		}
    	}
	return {0,0};  // did not find an empty square - play on the top-left
}
