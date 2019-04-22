//hw2
//game of nim for random generators 
// Joanna Taracena
// compsci 1
// 04-02-19
#include <iostream>
#include <string> 
#include <cmath> 
#include <iomanip> 
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
using namespace std;


int main() {
	int input;
	int comp;
	int n;
	cout << "***************The Game of Nim ******************" << endl;
	cout << "Rules of the game:" << endl;
	cout << "- Each player can remove 1,2, or 3 stones from the pile." << endl;
	cout << "- The player who makes the last move loses." << endl;

	cout << "Choose mode:" << endl;
	string mode;
	string e, h;
	cout << "Easy Mode (e) or Hard Mode (h): "; // this is the choice e || h
	cin >> mode;

	if ((mode == "e") || (mode == "E")) {

		cout << "You have chosen Easy Mode." << endl;
		srand(time(NULL)); //this is a null pointer to help my random var
		n = rand() % 21 + 10; // this is my random num generator.
		cout << "The initial number of stones is:  " << n << endl;
		cout << "Now a roll of the die to determine who plays first . . . ";



		srand(time(NULL));
		int turn;
		turn = rand() % 2 + 1;
		if (turn == 1) {
			cout << "It is your turn." << endl;
			do {
				cout << "Enter the number of stones you would like to remove: " << endl;
				cin >> input;

				if ((input < 1) || (input > 3)) {
					cout << "Invalid.";
					return 0;
				}
				else {
					int newS = n - input;
					cout << "The pile now has " << newS << " stones left." << endl;
					srand(time(NULL));
					comp = rand() % 3 + 1;
					cout << "The computer is choosing a move . . ." << endl;
					cout << "The computer removed " << comp << " stones." << endl;
					int newSS = newS - comp;
					cout << "The Number of Stones Remaining is: " << newSS << endl;
				}



			} while ((n > 0) && (n < !0));
		}
		else {
			cout << "You have chosen hard mode." << endl;
			cout << "Computer goes first." << endl;
			do {
				int computer;
				srand(time(NULL));
				computer = rand() % 3 + 1;
				cout << "The computer removed : " << computer << endl;
				int newsss = n - computer;
				cout << "The pile now has: " << newsss << endl;
				cout << "Enter the number of stones you would like to remove: ";
				int removed;
				cin >> removed;
				if ((removed < 1) || (removed > 3)) {
					cout << "Invalid.";
					return 0;
				}
				else {
					int pile = newsss - removed;
					cout << "The pile now has: " << pile << endl;
				}

			} while ((n > 0) && (n < !0));

		}
	}
}
