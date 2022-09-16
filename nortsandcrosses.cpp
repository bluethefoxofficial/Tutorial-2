#include <iostream>
#include <string>
#include "windows.h"
#include "nortsandcrosses.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;


//v a r i a b l e s.
int playeronewins = 0;
int playertwowins = 0;
bool playeroneturn = true;
bool playertwoturn = false;
string currentplayer = "";
char P1 = 'X';
char P2 = 'O';
string playeronename = "";
string irrelevent = "";
string playertwoname = "";
//matrix grid for the board
char grid[3][3] = { '1','2','3','4','5','6','7','8','9' };
int norts() {
	//introduction and asking the first players name
	cout << "=========== hello welcome to tic X tac 0 toe ============\nPlayer one what is your name?\n>";
	Beep(600, 200);
	cin >> playeronename;
	Clear();
	//player two name
	cout << "Player two whats your name?\n>";
	cin >> playertwoname;
	currentplayer = playeronename;
	Beep(400, 200);
	Beep(500, 200);
	Beep(600, 200);
	Clear();

	//the game itself after   settingup the players
	game();

	return 0;
}

//void for player turn changing
void playerturn() {
	//change the turn of the player.
	playeroneturn = !playeroneturn;
	playertwoturn = !playertwoturn;
	if (playeroneturn) {
		currentplayer = playeronename;
	}
	else {
		currentplayer = playertwoname;
	}
	game();
	}

//game mechanics and player placement of peice and checks win conditions.
void game() {
	Clear();

	printui();
	string column = "";
	string row = "";
	
	cout << "\n" << currentplayer << " pick a space row>";
	cin >> row;
		cout << "\n" << currentplayer << " pick a space column>";
	cin >> column;

	if (stoi(row) > 3) {
		cout << "\n You cant go beyond 3 try again";
		game();
	}
	if (stoi(row) < 1) {
		cout << "\n You cant go under 1 try again";
		game();
	}
	if (stoi(column) > 3) {
		cout << "\n You cant go beyond 3 try again";
		game();
	}
	if (stoi(column) < 1) {
		cout << "\n You cant go under 1 try again";
		game();
	}
	//check if the space is taken
	if (grid[stoi(row) - 1][stoi(column) - 1] == P1 || grid[stoi(row) - 1][stoi(column) - 1] == P2) {


		cout << "space taken try again";
		Sleep(1000);
		game();
	}else{
		//place the players symbol in the space
		if (playeroneturn) {
			grid[stoi(row) - 1][stoi(column) - 1] = P1;
		}
		else {
			grid[stoi(row) - 1][stoi(column) - 1] = P2;
		}
		//check if the player has won
		if (checkwin()) {
			if (playeroneturn) {
				cout << playeronename << " HAS WON 1 POINT!";
				playeronewins++;
			}

			else {
				cout << playertwoname << " HAS WON 1 POINT!";
				playertwowins++;
			}
			//ask if they want to play again
			cout << "would you like to play again? y/n\n>";
			cin >> irrelevent;
			if (irrelevent == "y") {
				//reset the board
				resetgrid();
			
				game();
			}
			else {
				//exit the game
				exit(0);
			}
		}
		else {
			//change the turn
			playerturn();
		}
	}

		playerturn();

	
}
//prints the ui for the game
void printui() {
	cout << "current player: " << currentplayer;
	cout << "\n" << "===" << playeronename << " | " << playeronewins << " " << playertwowins << " | " << playertwoname << "===\n";
	printgrid();
}

void printgrid(){
	//prints the grid and the border with 123 being what the user can select
	cout << "     " << "=" << "=" << "=" << "=" << "=" << "\n";
	cout << "<1> :" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << endl;
	cout << "<2> :" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl;
	cout << "<3> :" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
	cout << "     " << "=" << "=" << "=" << "=" << "=" << "\n";
}

bool checkwin() {
	//check if the player has won by checking each win condition via the matrix note this has no logix for players it simpily checks if it has the same char in each bit.
	if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {
		return true;
	}
	else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {
		return true;
	}
	else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
		return true;
	}
	else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {
		return true;
	}
	else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {
		return true;
	}
	else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) {
		return true;
	}
	else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		return true;
	}
	else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		return true;
	}
	else {
		return false;
	}
}

void resetgrid() {
	//resets the grid
	grid[0][0] = '1';
	grid[0][1] = '2';
	grid[0][2] = '3';
	grid[1][0] = '4';
	grid[1][1] = '5';
	grid[1][2] = '6';
	grid[2][0] = '7';
	grid[2][1] = '8';
	grid[2][2] = '9';
	//also performs a clear on the variables
	playeroneturn = true;
	playertwoturn = false;
	currentplayer = playeronename;
}
void Clear()
{
	//clears the console making it empty and ready for the next output via cout
	cout << "\x1B[2J\x1B[H";
}