/*
 *
 * # Title: Lab 5 Functions
 * # Description: Face Function and mpgKPG
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 4-19
 */



#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

using namespace std;

// int mood;
char userMood;

// Character array size defaults
const int S = 75;
const int L = 200;

// Sleep time defaults
const int HALF_SECOND = 500;
const int SECOND = 1000;

void dLay(int a) {
	Sleep(a);
}

void stylishDelay() {
	// Clears Screen
	for (int i = 0; i < 10; i++) {
		cout << "\n\n\n\n\n\n\n\n\n";
	}
	// Load Prompt
	cout << "WELCOME TO ANOTHER SPECIAL OMHM EDITION LAB\n";
	for (int WIDTH = 1; WIDTH <= 20; WIDTH ++ ){
		cout << "LOADING:";
		cout << setw(WIDTH) << setfill('*') << "*\n";
		dLay(100);
	}
	cout << "DONE:\n\n";

}

// FACE FUN
void happyFace() {
	cout << setw(9) << right <<  " _____\n";
	cout << setw(10) << right << " _/ - - \\_ \n";
	cout << setw(11) << right << "(o / | \\ o)\n";
	cout << setw(10) << right << " || o|o ||\n";
	cout << setw(10) << right << " | \\_|_/ |\n";
	cout << setw(10) << right << " |  ___  |\n";
	cout << setw(10) << right << " | (___) |\n";
	cout << setw(10) << right << " |\\_____/|\n";
	cout << setw(10) << right << " | \\_|_/ |\n";
	cout << setw(10) << right << " \\       /\n";
	cout << setw(10) << right << "   |||||  \n";
 }

void normalFace() {
	cout << setw(9) << right << " _____\n";
	cout << setw(10) << right << " _/ - - \\_ \n";
	cout << setw(11) << right << "(o / | \\ o)\n";
	cout << setw(10) << right << " || X|X ||\n";
	cout << setw(10) << right << " | \\_|_/ |\n";
	cout << setw(10) << right << " | _____ |\n";
	cout << setw(10) << right << " | |* *| |\n";
	cout << setw(10) << right << " |    _/ |\n";
	cout << setw(10) << right << " | __/   |\n";
	cout << setw(10) << right << " \\       /\n";
	cout << setw(10) << right << "   |||||  \n";
}

void sadFace() {
	cout << setw(9) << right << " _____\n";
	cout << setw(10) << right << " _/ _ _ \\_ \n";
	cout << setw(11) << right << "(o /_|_\\ o)\n";
	cout << setw(10) << right << " || &|& ||\n";
	cout << setw(10) << right << " | \\_|_/ |\n";
	cout << setw(10) << right << " | o    o|\n";
	cout << setw(10) << right << " |o __   o\n";
	cout << setw(10) << right << " o /  \\ |\n";
	cout << setw(10) << right << "o|/    \\|\n";
	cout << setw(10) << right << " \\______/\n";
	cout << setw(10) << right << "   |||||  \n";
}

void greeting() {
	cout << "Hello my friend. It has been a while since I have seen you ....\n\n";
	dLay(SECOND);
	cout << "I was worried about you after all those rumors that were going around...\n\n";
	dLay(SECOND);
	cout << "Well forget that nonsense mate......\nHow have been lad???\n\n";
	dLay(SECOND);
}

char getMood() {
	char a;
	cout << "Please use enter one of the following keys: \n\n";
	dLay(HALF_SECOND);
	cout << "For 'Happy' \nENTER:  h\n\n";
	cout << "For 'Sad' \nENTER:  s\n\n";
	cout << "For 'Anything Else' \nENTER:  any character\n\n";
	dLay(HALF_SECOND);
	cin >> a;
	// Possible Error Check
	return a;
}


void checkMood_v2(char mood) {
	// cout << "Mood is:" << mood << endl;
	if (mood == 'h') {
		happyFace();
	}
	else if (mood == 's') {
		// cout << "Sad face function here .\n";
		sadFace();
	}
	else {
		//cout << "Normal face here\n";
		normalFace();
	}

}

// PART 2: MPG KPG



void greeting2() {
	cout << "Hey Hey Hey your back again\n\n";
	dLay(SECOND);
	//cout << "ENTER (1) for mpg to kpl conversion. \n";
	//cout << "ENTER (2) for kpl to mpg conversion. \n\n";
	cout << "ENTER  the mpg for conversion to kpl. \n\n";
}



int getChoice() {
	int choice;
	cin >> choice;
	return choice;
}

double getInput() {
	double input;
	cin >> input;
	return input;
}

mpgToKPL(double mpg){
	const double LITER_PER_GALLON = 0.264172;
	const double KILOMETER_PER_MILE = 0.621371;

	return ((mpg / LITER_PER_GALLON) / KILOMETER_PER_MILE);
	
	}
//////////////////////////////////////
/////////////////////////////////




// PART A

void partA() {
	stylishDelay();
	greeting();
	char userMood = getMood();
	//cout << "User Mood is: " << userMood << endl;
	//ERROR CHECK: cout << "Moods value is: " << mood;
	checkMood_v2(userMood);

}

// Part B

void partB() {
	stylishDelay();
	cout << "PART TWOOOO \n\n\n";
	dLay(SECOND);
	greeting2();

	double userMPG = getInput();
	double KPL = mpgToKPL(userMPG);
	dLay(HALF_SECOND);
	cout << "\n\nYour mpg in kpl is:  " << KPL << endl;

}

int main() {

	partA();
	//partB();
	return (0);
}