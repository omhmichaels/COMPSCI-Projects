/*
 *
 * # Title: GAME OF TIMS
 * # Description: Mathematical strategy game based off Game of Nims
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 3-26-19
 */



#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

using namespace std;

const int S = 100;           // Small prompt
const int L = 300;            // Large Prompt

// Tims Variables
// srand(time(NULL));           // Seed Number From Computer Clock for Random number generation Algorithm
int numTims = (rand() %11) + 10  ;		 // Generate randonm number between 11 and 1 and then add 10 to it   
int timsTaken;

// Global Prompts
char numTimsPrompt[S] = "The number of TIMS remaining is: %i\n";
char errorPrompt[S] = "You have selected %i\nPlease try again with a valid input";

// Turn Variables
int  movement;

int mode;			// Mode Selection Variable


// BEAUTIFICATION FUNCTIONS
void dLay() {
	Sleep(500);
}

void newLine() {
	cout << "\n\n";
}

void beautify() {
	cout << setfill('-') << setw(65);
	newLine();
}

void ending() {
	cout << setfill('*') << setw(50) << "Thank you for playing" << setw(50);
}

void loading() {
	cout << "LOADING:5%" << setfill('-') << setw(2) << "-\n";
	dLay();
	cout << "LOADING:10%" << setfill('-') << setw(5) << "-\n";
	cout << "LOADING:15%" << setfill('-') << setw(10) << "-\n";
	cout << "LOADING:20%" << setfill('-') << setw(14) << "-\n";
	dLay();
	cout << "LOADING:25%" << setfill('-') << setw(17) << "-\n";
	cout << "LOADING:30%" << setfill('-') << setw(20) << "-\n";
	cout << "LOADING:35%" << setfill('-') << setw(25) << "-\n";
	dLay();
	cout << "LOADING:40%" << setfill('-') << setw(28) << "-\n";
	cout << "LOADING:45%" << setfill('-') << setw(31) << "-\n";
	cout << "LOADING:50%" << setfill('-') << setw(34) << "-\n";
	dLay();
	cout << "LOADING:55%" << setfill('-') << setw(38) << "-\n";
	cout << "LOADING:60%" << setfill('-') << setw(42) << "-\n";
	cout << "LOADING:65%" << setfill('-') << setw(45) << "-\n";
	dLay();
	cout << "LOADING:70%" << setfill('-') << setw(48) << "-\n";
	cout << "LOADING:75%" << setfill('-') << setw(51) << "-\n";
	cout << "LOADING:80%" << setfill('-') << setw(53) << "-\n";
	dLay();
	cout << "LOADING:85%" << setfill('-') << setw(55) << "-\n";
	cout << "LOADING:90%" << setfill('-') << setw(58) << "-\n";
	cout << "LOADING:95%" << setfill('-') << setw(60) << "-\n";
	dLay();
	cout << "LOADING:100%" << setfill('-') << setw(65) << "-\n";
}

void firstTurn() {
	if ((numTims / 2) % 2 == 0) {
		movement = 0;
		cout << "Its your lucky day, you will get to select a few pairs first.\n";
		dLay();
	}
	else {
		movement = 1;
		cout << "Aye bud I gotta let old boy here go first he just shot me a 100$\n";
		cout << "Wait right here while he makes a selection\n\n";
		dLay();

	}
}


// GAME TURN CONTROL FUNCTIONS
void playerMove(){

	char numTimsPrompt[S] = "The number of TIMS remaining is: %i\n";
	char movePrompt[L] = "Your up bud!\n\nChoose 1, 2, or 3 pairs of TIMS to take during this round\n";
	char getMovePrompt[S] = "How many pairs of TIMS will you be taking:  \n";
	char confirmMovePrompt[L] = "You have selected %i pairs of TIMS\n";
	char compMovePrompt[L] = "Alright looks like you got yourself some fine TIMS\nNow hold up while old boy chooses a few pairs before you go again.\n\n";
	char errorPrompt[L] = "ERROR: You chose %i\nPlease use select 1, 2, 3 pairs of TIMS\n";

	printf(numTimsPrompt, numTims);
	cout << movePrompt;
	dLay();
	cout << getMovePrompt;
	dLay();
	cin >> timsTaken;
	cout << "\n\n";
	dLay();
	printf(confirmMovePrompt, timsTaken);

	// Tims Taken Logic
	if (((timsTaken == 1) || (timsTaken == 2) || (timsTaken == 3)) && (numTims-timsTaken >= 0)) {
		// Change Tims Remaining
		numTims -= timsTaken;
		movement += 1;
	}
	else if (timsTaken != 1 || 2 || 3) {
		printf(errorPrompt, timsTaken);
		playerMove();
	}
	else {
		printf(errorPrompt, timsTaken);
		playerMove();
	}
	cout << compMovePrompt;

}



void compMovePrompts() {
	char prompt[L] = "Looks like he picked out %i pairs.\nYour up next rememmber second to last person to pick a few pairs wins a new Caddillac.\n";

	printf(prompt, timsTaken);
}

void compMove() {
	// Change Tims Remaining
	compMovePrompts();
	numTims -= timsTaken;
	movement -= 1;
}

void compMoveEasy() {
	// Random Number of timsTaken by bot
	timsTaken = ((rand() %3)+1);

	compMove();
}

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

void compMoveHard() {
	compMoveHardLogic();
	compMove();
}

void turnControlEasy() {
	char endPrompt1[L] = "\nOOOP Looks like were out of TIMS\nWell Well Well, looks like you won.\nHeres the keys to your new cadillac.\n See you next week!";
	char endPrompt2[L] = "\n\nOOP Looks like were out of TIMS.Well Well Well, looks like you lost.\n See you next week!";


	while (numTims >= 0) {
		if (movement == 0) {
			playerMove();
		}
		else {
			compMoveEasy();
		}
	}
	if (movement == 0) {
		cout << endPrompt1;
		ending();
	}
	else {
		cout << endPrompt2;
		ending();
	}
}



void turnControlHard() {
	char endPrompt1[L] = "\nOOOP Looks like were out of TIMS\nWell Well Well, looks like you won.\nHeres the keys to your new cadillac.\n See you next week!";
	char endPrompt2[L] = "\n\nOOP Looks like were out of TIMS.Well Well Well, looks like you lost.\n See you next week!";

	while (numTims >= 0) {
		if (movement== 0) {
			playerMove();
		}
		else {
			compMoveHard();
		}
	}
	if (movement == 1) {
		cout << endPrompt1;
	}
	else {
		cout << endPrompt2;
	}
}


// GamePlay Initialization
void gameInit() {
	// Inro Prompts
	char prompt1[S] = "THE GAME OF TIMS!";
	char prompt2[L] = "RULEZ:\n1)Player may take 1, 2, or 3 pairs of Tim's from the stolen truck during thier turn.\n";
	char prompt3[L] = "2) The player who makes the last move loses.\n\n";
	char startPrompt[L] = "You know the deal!\nThe TIMS Truck is hot on the block be the last one to pick a few pairs and win a new CADDY!\n";
	char numTimsPrompt[S] = "Alright my boy, We had %i pairs of Tims come in this week.\n";



	// INTRO
	beautify();
	cout << setfill('-') << setw(25) << prompt1 << setw(50) << '-' << endl;
	dLay();
	cout << prompt2 << prompt3;
	beautify();
	dLay();

	// Mode Selection Prompts
	char choosePrompt[L] = "Choose mode: \nEnter 1 for Easy Mode Enter \nEnter 2 for Hard Mode Enter : \n";
	char confirmPrompt[S] = "You CHOSE:\n%i) %s MODE\n\n";
	char e[S] = "Way To easy if your smart,";
	char h[S] = "You'll probally lose its so hard, MODE\n";

	cout << choosePrompt;
	cin >> mode;
	loading();
	newLine();
	dLay();



	// Easy Mode
	if (mode == 1) {
		printf(confirmPrompt, mode, e);
		dLay();
		firstTurn();
		printf(numTimsPrompt, numTims);
		turnControlEasy();
	}
	// Hard Mode
	else if (mode == 2) {
		printf(confirmPrompt, mode, h);
		dLay();
		firstTurn();
		printf(numTimsPrompt, numTims);
		turnControlHard();
	}
	// Error Handling
	else {
		printf(errorPrompt,mode);
		dLay();
		gameInit();
	}


}


int main(){
	gameInit();
}



