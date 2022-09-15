#include <iostream>
#include "windows.h"
#include "nortsandcrosses.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int playeronewins = 0;
int playertwowins = 0;
char P1 = 'X';
char P2 = 'O';
string playeronename = "";
string irrelevent = "";
string playertwoname = "";

int norts() {
	
	cout << "XOXOXOXOXOXO hello welcome to the game XOXOXOXOXOXOX\nPlayer one what is your name?\n>";
	Beep(600, 200);
	cin >> playeronename;
	Clear();
	cout << "Player two whats your name?\n>";
	cin >> playertwoname;
	Beep(400, 200);
	Beep(500, 200);
	Beep(600, 200);
	Clear();


	cout << "-" << playeronename << "|" << playeronewins << "===" << playertwowins << "|" << playertwoname << "-\n";
	
	return 0;
}
void Clear()
{
	cout << "\x1B[2J\x1B[H";
}