//hw2
//game of nim for random generators 
// Joanna Taracena
// compsci 1
// 04-02-19
/*
Changes made lines marked with comments and ##

Original code commented out at the bottom.

/*

This is going to be the structure of the code.

	1) Intro
		a) Gather input for easy or hard mode
		b) Gather value for initial number of stones
		c) Gather value for whos turn is first

	2) Check value of easy or hard mode to determine mode

	3) While loop initialization
		a) check value of whos turn to see who goes first
		b) Gameplay

 // Basically for the while loop this is the structure of the whole code

 while number of stones is greater than 0

   > if easy mode
	 > if whosTurn = 0
	   - Player turn
			a) Choose stones taken
			b) stones in pile minus stones taken
			c) change value of whosTurn for computers turn
	 > else if whosTurn = 1
	   - computer turn
			a) Choose stones taken
			b) stones in pile minus stones taken
			c) change value of whosTurn for computers turn

  > else if hard mode // this should essentially be the same except added logic is needed
						  please see my code for an example of how this was done.
	 > if whosTurn = 0
	   - Player turn
			a) Choose stones taken
			b) stones in pile minus stones taken
			c) change value of whosTurn for computers turn
	 > else if whosTurn = 1
	   - computer turn
			a) Choose stones taken
			b) stones in pile minus stones taken
			c) change value of whosTurn for computers turn

And thats the whole game. Here is a sample  of the logic for the hard mode.

void compMoveHardLogic() {
	// Tims taken login
	if (numTims % 4 == 0) {
		timsTaken = 3;
	}
	else if (numTims % 4 == 3) {
		timsTaken = 2;
	}
	else if (numTims % 4 == 2) {
		timsTaken = 1;
	}
	else if (numTims % 4 == 1) {
		timsTaken = 1;
	}
}
*/



#include <iostream>
#include <string> 
#include <cmath> 
#include <iomanip> 
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

// ## ADDED WINDOWS HEADER , its a lowercase w
#include <windows.h>

// ## NESSACARY VARIABLES

// ## Turn control
int whosTurn = 0;    // ## This will control whos turn it is
					 // ## We will do this by saying if its value is 0 it will
                     // ## be our players turn. If it is 1, it will be the computers turn
                     // ## We will give the next person their turn by adding one to 
                     // ## at the end of the players turn and subtracting one at the
                     // ## end of the computers turn.

// ## Number of Stones
// This will be the variable to wich we assign the number of stones in the pile.
// We can use this same variable throughout the program to hold the number of stones in the
// pile
int numberOfStones;

// ## Stones taken by player and computer
// We will use one variable to hold the value of stones have been taken from the pile
int stonesTaken;

using namespace std;


int main() {
	int input;
	int comp;
	int n;

	// INTRO TO GAME
	cout << "***************The Game of Nim ******************" << endl;
	cout << "Rules of the game:" << endl;
	cout << "- Each player can remove 1,2, or 3 stones from the pile." << endl;
	cout << "- The player who makes the last move loses." << endl;



	// MODE SELECTION
	cout << "Choose mode:" << endl;
	string mode;

	// ## This is not needed as far as I can see
	// ## Mstring e, h;
	cout << "Easy Mode (e) or Hard Mode (h): "; // this is the choice e || h
	cin >> mode;
	// ## Print debugging
	cout << "User input: " << mode << "For our mode variable\n\n";



	// EASY MODE 
	// Good use of or || 
	if ((mode == "e") || (mode == "E")) {

		cout << "You have chosen Easy Mode." << endl;
		srand(time(NULL)); //this is a null pointer to help my random var

		// INITIALIZE NUMBER OF STONES
		numberOfStones = rand() % 21 + 10; // this is my random num generator.
		cout << "The initial number of stones is:  " << n << endl;
		cout << "Now a roll of the die to determine who plays first . . . \n\n";


		// ## MY EDITED VERISION.	
		srand(time(NULL));

		// ## Used my variable instead for understanding 
		//int turn;
	
		// ### Changed to give a 1 or a 0
		whosTurn = rand() % 1 ;
		// Check value of whos turn for bugs
		cout << "whosTurn = " << whosTurn << " before the start of our while loop\n";


		// ## This is where you need to begin your while loop. Just use a regular 
		// ## While loop for simplicity
		// We will set the while loop to continue for as long as the numberOfStones is 
		// greater than zero which will end the game.
		// We essentially want each step underneath to be repeated until no stones remain.
		cout << "INITIATE WHILE LOOP\n_____________________________\n\n";
		while (numberOfStones > 0) {

			// We will use a cout to check the number of stones and whosTurn at the begining of each iteration
			// of our while loop for debugging
			cout << "Current number of stones is " << numberOfStones << endl;
			cout << "whosTurn = " << whosTurn << endl;


			// ## Slight edit to make users turn be when whosTurn is 0
			if (whosTurn == 0) {
				cout << "It is your turn." << endl;

				cout << "Enter the number of stones you would like to remove: " << endl;
				// ## INSTEAD WE WANT THIS TO BE ASSIGNED DIRECTLY TO THE STONES TAKEN
				// VARIABLE.

				cin >> stonesTaken;



				// Here we want to get the user to reenter a choice if the made a mistake.
				// This is didffucult to achieve properly. Refer to my code. To see a way to implement this properly
				// This is a quick fix and noot implemented in a maintainable way
				if ((stonesTaken < 1) || (stonesTaken > 3)) {
					cout << "Invalid. Please select a valid option\n";
					cin >> stonesTaken;
				}

				// ## Now that we have our check for a proper selection and the number of stones taken
				// for our user we need to use that to change the number of stones in the pile
				// This seems complicated but can be done fairly easlily using reassignment.
				cout << "The number of stones before stones taken: " << numberOfStones << endl;
				// This subtracts the number of stones taken from the total number of stones
				numberOfStones -= stonesTaken;

				// cout for debugging
				cout << "The value of stones taken is currently: " << stonesTaken << endl;
				cout << "The number of Stones is now: " << numberOfStones << endl;

				// Lastly we give the computer its turn by incrementing the value of whosTurn by 1
				whosTurn++;
			}
			// ####### END PLAYER MOVE ########


			// ## COMPUTERS TURN
			// Next we do the same basic steps only for the computers turn. Notice that I am still
			// coding for the if block that starts just under our while loop. 


			else if (whosTurn == 1) {
				// ## Not needed int newS = n - input;
				cout << "The pile now has " << numberOfStones << " stones left." << endl;
				srand(time(NULL));

				// We can use our stonesTaken variable again here since we are reassigning the value 
				// for each players turn.
				// Computer stones takens
				stonesTaken = rand() % 3 + 1;
				cout << "The computer is choosing a move . . ." << endl;
				cout << "The computer removed " << stonesTaken << " stones." << endl;

				// Change the value of total stones in pile
				numberOfStones -= stonesTaken;
				cout << "The Number of Stones Remaining is: " << numberOfStones << endl;

				// Change the value of whosTurn so that the player has there turn next
				whosTurn--;

				// ######## END COMP TURN ########
			}

			// #### END WHILE LOOP/ GAME ####
		}
	// #### END EASY MODE ######
	}

	// #### END MAIN ####
		return (0);
}

/*
	// YOUR ORIGINAL CODE WITH COMMENTS AND EDITS
	srand(time(NULL));
	int turn;
	turn = rand() % 2 + 1;
	if (turn == 1) {
		// ## I believe you meant to initiate your while loop here.
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
			*/
			/*
			 # PROBLEM WITH DO WHILE

			 The codes inside the body of loop is executed at least once. Then, only the test expression is checked.
			If the test expression is true, the body of loop is executed. This process continues until the test expression becomes false.
			When the test expression is false, do...while loop is terminated.

			*//*
						} while ((n > 0) && (n < !0));
						// Check syntax of  n doesnt equal zero. Should look like (n != 0)
						// Check the value of n for our loop
						cout << "The value of n is: " << n << endl;
					}
			*/


/*
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
*/