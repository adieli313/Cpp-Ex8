
#include "TicTacToe.h"
#include "DummyPlayers.h"

#include "Champion.h"
#include "Board.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;

	return 0;
}
