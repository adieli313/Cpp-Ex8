#include "TicTacToe.h"

 TicTacToe::TicTacToe(const int board_size){
     
        this->gameSize = board_size;
      	gameBoard.setBoard(board_size);
 }
 
void TicTacToe::play(Player& player1, Player& player2){
     
    int count = 0;
    int attempts = gameBoard.size() * gameBoard.size();
     
    player1.setChar('X');
    player2.setChar('O');
     
    while(count < attempts){
         
        //player1's turn
        if(turnIsLegal(player1)){
        	gameBoard[player1.play(gameBoard)] = 'X';
        		if(checkForWin(gameBoard) == 1){
            		win = &player1; 
            		//gameIsRunning = false;
            		return;
        		}
    	}
        else{
        	win = &player2;
        	return;
        } 
        count++;
         
        //player2's turn
        if(turnIsLegal(player2)){
        	gameBoard[player2.play(gameBoard)] = 'O';
        		if(checkForWin(gameBoard) == 2){
            		win = &player2; 
            		//gameIsRunning = false;
            		return;
        		}
    	}
        else if(count == attempts){
	    	//incase of tie. player2 is a defualt winner.
    		win = &player2;
        	return;
        }
        else{
        	win = &player1;
        	return;
        } 
        count++;
        
    }

}


bool TicTacToe::turnIsLegal(Player& player){
	try{
		Coordinate coordinate;
		
		coordinate = player.play(gameBoard);
        if (gameBoard[coordinate] != '.'){
           throw string("Illegal Move.");
        }
        
        return true;
	}
	catch(...){
		return false;
	}
}




//1 for 'X' - player1
//2 for 'O' - player2
//0 for none -  
int TicTacToe::checkForWin(Board& board){
    
    if(checkRowVictory(board) == 1 || checkColVictory(board) == 1 ||
    	checkMainDiagVictory(board) == 1 || checkSecDiagVictory(board) == 1){
        //player 1 win
        return 1;
    }
    else if(checkRowVictory(board) == 2 || checkColVictory(board) == 2 ||
    			checkMainDiagVictory(board) == 2 || checkSecDiagVictory(board) == 2){
        //player 2 win
        return 2;
    }
    else
    return 0;
}


//1 for 'X' -
//2 for 'O' -
//0 for none -  
int TicTacToe::checkRowVictory(Board& board){
    int rowCountX = 0, rowCountO = 0;
    
    for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
		    Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        rowCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        rowCountO++;
		    }
		}
		
		if(rowCountX == board.size()){
		    return 1;
		}
		else if(rowCountO == board.size()){
		    return 2;
		}
		
		rowCountO = 0;
		rowCountX = 0;
	}

	return 0;

}

//1 for 'X' -
//2 for 'O' -
//0 for none - 
int TicTacToe::checkSecDiagVictory(Board& board){
	int diagCountX = 0, diagCountO = 0;
	int count = 0;
	
	uint x1 = 0, x2 = board.size() - 1;
	
	while(count < board.size()){
		Coordinate c{x1,x2};
		    if(board[c] == 'X')
		    {
		        diagCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        diagCountO++;
		    }
		    
		    x1++;
		    x2--;
		    count++;
	}
	
		if(diagCountX == board.size()){
			return 1;
		}
		else if(diagCountO == board.size()){
	    	return 2;
		}
		
	return 0;
}

//1 for 'X' -
//2 for 'O' -
//0 for none - 
int TicTacToe::checkColVictory(Board& board){
    int colCountX = 0, colCountO = 0;
    
    for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
            Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        colCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        colCountO++;
		    }
		}
		
		if(colCountX == board.size()){
			return 1;
		}
		else if(colCountO == board.size()){
	    	return 2;
		}
		
		colCountO = 0;
		colCountX = 0;
	}
	
	return 0;
}

//1 for 'X' -
//2 for 'O' -
//0 for none - 
int TicTacToe::checkMainDiagVictory(Board& board){
    int diagCountX = 0, diagCountO = 0;
    
	for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
            if(x == y){
            Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        diagCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        diagCountO++;
		    }
        }
	}
}
	
	if(diagCountX == board.size()){
		return 1;
	}
	else if(diagCountO == board.size()){
	    return 2;
	}
	else{
	return 0;
	}
}
 
 
Player& TicTacToe::winner() const{
	gameBoard = '.';
    return *win;
}

Board TicTacToe::board() const{
	return gameBoard;
}