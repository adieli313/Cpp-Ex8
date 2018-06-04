#include <stdio.h>
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

#include "Board.h"

Board::Board(){
    
} 


        Board::Board(const int squer){
            this->squer = squer;
            board = new CheckBoard*[squer];
            for(int i = 0; i < squer; ++i){
                board[i] = new CheckBoard[squer];
            }
            for (int i = 0; i < squer; i++) {
                for (int  j = 0; j <  squer; j++) {
                    board[i][j] = '.';
                }
            }
        }
        
        Board::Board(const Board& _board) {
          squer = _board.squer;
          board = new CheckBoard*[squer];
          for(int i = 0; i < squer; i++)
                board[i] = new CheckBoard[squer];
                
              for (int i = 0; i < squer; i++) {
               for (int j = 0; j < squer; j++) {
            board[i][j] = _board.board[i][j];
        }
    }
}

Board::~Board(){
    for (int i = 0; i <squer ; ++i) {
            delete[] board[i];
    }delete[] board;

}

    
        CheckBoard& Board::operator[] (vector<int> point) {
            if (point.at(0) < 0 || point.at(0) >= squer || point.at(1) < 0 || point.at(1) >= squer)
            throw IllegalCoordinateException(point.at(0), point.at(1));
            return board[point.at(0)][point.at(1)];
}   

        CheckBoard& Board::operator[] (Coordinate coordinate) const{
            if (coordinate.getRow() < 0 || coordinate.getRow() >= squer || coordinate.getCol() < 0 || coordinate.getCol() >= squer)
            throw IllegalCoordinateException(coordinate.getRow(), coordinate.getCol());
            return board[coordinate.getRow()][coordinate.getCol()];
}             


   const Board& Board::operator= (char Char) const{
        if(Char != '.' && Char != 'X' && Char != 'O')
        throw IllegalCharException(Char);
       
    for (int i = 0; i < squer; i++) {
        for (int j = 0; j < squer; j++) {
            board[i][j] = Char;
        }
    }
 
    return *this;
}

    Board& Board::operator=(const Board& b) {
    squer=b.squer;
    this->board=new CheckBoard*[squer];
    for (int i = 0; i < squer; ++i) {
        board[i] = new CheckBoard[squer];
    }
    for (int i = 0; i <squer ; ++i) {
        for (int j = 0; j < squer; ++j) {
            board[i][j].setP(b.board[i][j].getP());
        }
    }
    return *this;
}

    istream& operator>> (istream& is, Board& b){
    	string line;
    	is>>line;
    	int len=line.length();
    	int i=0;
    	Board tmp{(int)line.length()};
    	b=tmp;
      	while (is){
    		for (int j=0; j<line.length(); j++){
    			b.board[i][j]=line.at(j);
    		}
    		i++;
    		is>>line;
      	}
    	
    	return is;
    	
    }



   ostream& operator<<(ostream& os , const Board& board) {
           for(int i=0; i < board.squer; i++){
               for(int j=0; j < board.squer; j++){
                   os << board.board[i][j];
               }
               os<< endl;
           }
    return os;
    }
    
int Board::size() const{
    return squer;
}



void Board::setBoard(const int dimension) {
    setDimension(dimension);
    setMatrix(dimension);
}

void Board::setDimension(const int dimension) {
    this->squer = dimension;
}

void Board::setMatrix(const int dimension) {
    board = new CheckBoard*[dimension];
    for(int i = 0; i < dimension; i++)
        board[i] = new CheckBoard[dimension];
}

string Board::draw(int const n){
	file_num++;
	while(true){
		ifstream f("draw"+to_string(file_num)+".ppm");
		if(!f.good())
			break;
		else
			file_num++;
			
	}
	string file_name="draw"+to_string(file_num)+".ppm";
  	ofstream imageFile(file_name, ios::out | ios::binary);
  	imageFile << "P6" << endl <<n<<" " <<n<< endl << 255 << endl;
  	RGB image[n*n];
	int cell_size=(n-squer+1)/squer;
  	for (int j = 0; j < n; ++j)  {  // row
    		for (int i = 0; i < n; ++i) { // column
			image[n*j+i].red = (252);
			image[n*j+i].blue = (162);
			image[n*j+i].green = (201);
			if(i%cell_size==0||(j)%cell_size==0){
				for(int N = 0 ; N < 5 ; N++){
				    image[n*j+i+N].red = (0);
			    	image[n*j+i+N].blue = (0);
				    image[n*j+i+N].green = (0);
				}
			}
   		 }
  	}
	for(int i=0;i<squer;i++){
		for(int j=0;j<squer;j++){
			if(board[i][j]=='X'){
				int row=(i)*cell_size+1;
				int col=(j)*cell_size+1;
				
				
				for(int p=(n*row)+col; p<((n*row+col)+(n*cell_size)); p+=n+1){
				             
      						image[p].red = (255);
							image[p].blue = (0);
							image[p].green = (0);
							
                            for(int N = 1 ; N < 5 ; N++){
            				    image[p+N].red = (255);
            			    	image[p+N].blue = (0);
            				    image[p+N].green = (0);
            				}
				    
				}
				
				row+=cell_size;
				for(int p=(n*row)+col; p>((n*row+col)-(n*cell_size)); p=p+1-n){
				   
      						image[p].red = (255);
							image[p].blue = (0);
							image[p].green = (0);
							for(int N = 1 ; N < 5 ; N++){
            				    image[p+N].red = (255);
            			    	image[p+N].blue = (0);
            				    image[p+N].green = (0);
            				}
				    
				}
				
			}
				
			if(board[i][j]=='O'){
				int row=(i)*cell_size+1;
				int col=(j)*cell_size+1;
				int r=(cell_size-(cell_size/10))/3;

				int mid_x=(col+col+cell_size)/2;
				int mid_y=(row+row+cell_size)/2;
			
				for (int k = row; k < row+cell_size; ++k)  {  // row
    					for (int l =col; l < col+cell_size; ++l) { // column
						int dis=sqrt((k-mid_y)*(k-mid_y)+(l-mid_x)*(l-mid_x));
						if(dis>r-1&&dis<r+1){
							image[n*k+l].red = (0);
							image[n*k+l].blue = (255);
							image[n*k+l].green = (0);
							for(int N = 1 ; N < 5 ; N++){
            				    image[n*k+l+N].red = (0);
            			    	image[n*k+l+N].blue = (255);
            				    image[n*k+l+N].green = (0);
            				}
						}
					}	
				}
			}
		
		}
	}	
  	imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
  	imageFile.close();
	return file_name;
}
