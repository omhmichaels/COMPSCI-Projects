/*
 *
 * # Title: Lab 5 Loops
 * # Description: Mathematical strategy game based off Game of Nims
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 3-26-19
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Initialize empty int variables


void gcd(int firstNumber, int secondNumber){
	int placeholder;
	int numModulo = 0;
	while (secondNumber != 0) {
		placeholder = secondNumber;
		//cout << placeholder << endl;
		secondNumber = firstNumber % secondNumber;
		//cout << secondNumber << endl;
		firstNumber = placeholder;
		//cout << firstNumber << endl;
		numModulo += 1;
	}
	cout << "THE GCD IS: " << firstNumber << endl;
	cout << "MODULO PERFORMED: " << numModulo << " times\n";

}

// Declare randomness globally
//srand(time(NULL));
int randNumber = rand() % 101;

void guessing(int number) {

	if (number > randNumber) {
		cout << "Too High guess again\n";
	}
	else if (number < randNumber) {
		cout << "Too Low guess higher \n";
	}
	else if (number == randNumber) {
		cout << "LUCKY GUESS";
	}
	else {
		cout << "ENTER A VALID GUESS: ";
	}
}


void finobachi(int terms) {
	cout << " The sequence is : \n";
	int next, first = 0, second = 1;
	for (int counter; counter < terms; counter++) {
		if (terms <= 0) {
			break;
		}
		else {	
			next = first + second;
			first = second;
			second = next;
		}
		cout << next << endl;
	}
}

int main() {
	// GCD
	int firstNumber, secondNumber;
	cout << "Enter first number to find gcd: \n";
	cin >> firstNumber;
	cout << "Enter second number: \n";
	cin >> secondNumber;
	gcd(firstNumber, secondNumber);


    // GUESSING GAME
	int guess;

	cout << "Now lets play a guessing game\nI'm thinking of a number between 1 and 100\n";

	while (guess != randNumber) {
		cout << "ENTER YOUR GUESS: ";
		cin >> guess;
		guessing(guess);
	}
	
	int terms;
	// Finobachi Numbers
	cout << "Now lets do Finobachi Numbers!\n";
	cout << "Enter a positive number";
	cin >> terms;
	finobachi(terms);
}