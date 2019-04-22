/*

# Title: Debugging Health Data Calculator
# Author: Somhmxxgh0u1
# Description: Debug the code

int main() {
   int userAgeYears;
   int userAgeDays;

   cout << "Enter your age in years: ";
   cin  >> userAgeYears;
   userAgeDays = userAgeYears * 365;

   cout << "You are " << userAgeDays << " days old." << endl;

   if(userAgeYears < 99){
	  cout << “Also, your too young to drive!”
   } else{ cout << you can drive!”;

   return 0;
}
Enter your age in years: 19
You are 6935 days old.

// Find and describe three errors in the code.

*/


// Error 1 includes were not included
/*
Debugging method included running the code through a compiler then 
reading the debugging output. 
Fixed by simply adding in the needed includes
Please note that pch.h is needed to run in VScode but may not be needed
in other compilers.

*/
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

// Error 2) Missing "using namespace std;"
/*
Debugging method included running the code through a compiler then
reading the debugging output.

After adding includes cout remained syntax highlighted. This was
due to the namespace not being specified. This problem could also be 
remedied by adding std:: in front of cout and cin.
*/
using namespace std;


// Global Variables 
int userAgeYears;
int userAgeDays;
int userAgeHours;
int userAgeSeconds;
int userAgeMinutes;
int userAgeHeartbeats;

// Gather user's age
void getAge() {
	char prompt1[40] = "Enter your age in years : \n";
	cout << setw(20) << setfill('-') << endl;
	cout << prompt1;
	cin >> userAgeYears;
}

// Age Days
void ageDays() {
	char prompt[50] = "Your age in days is: %d\n";
	userAgeDays = userAgeYears * 365;
	printf(prompt, userAgeDays);
}

// Age in Hours
void ageHours() {
	char prompt[50] = "Your age in hours is: %d\n";
	userAgeHours = userAgeDays * 24;
	printf(prompt, userAgeHours);
}

// Age in Minutes
void ageMinutes(){
	char prompt[50] = "Your age in minutes is: %d\n";
	userAgeMinutes = userAgeHours * 60;
	printf(prompt, userAgeMinutes);
}

// Age in Seconds
void ageSeconds() {
	char prompt[50] = "Your age in seconds is: %d\n";
	userAgeSeconds = userAgeMinutes * 60;
	printf(prompt, userAgeSeconds);
}

// Age in Heartbeats
void ageHeartbeats() {
	char prompt[50] = "Your age in heartbeats is: %d\n";
	userAgeHeartbeats = userAgeMinutes * 72;
	printf(prompt, userAgeHeartbeats);
}

// ERROR 3 If else statement is not showing
/*
This error was found by looking at the output from the program on the console.
*/
void ageDriving() {
	char prompt1[50] = "You are to young to drive!\n";
	char prompt2[50] = "You are can drive!\n";
	char prompt3[50] = "You are too old to drive!\n";
	
	if (userAgeYears < 16) {
		cout << prompt1;
	}
	else if (userAgeYears > 16 and userAgeYears < 60) {
		cout << prompt2;
	}
	else {
		cout << prompt3;
	}
}

// Eye Color Health Data
void eyeColor() {
	const int I = 200;
	char eyeColor[50];
	char prompt1[I] = "What color are your eyes: \nChoose Blue, Green, Brown\n";
	char prompt2[I] = "Good thing your eyes are not blue or green. You have an increased risk of cancer.\n";
	char prompt3[I] = "Studies show you that people with blue or green eyes have an increased risk of cancer\n";
		cout << prompt1;
	cin >> eyeColor;

	if (eyeColor == "Blue" or "blue") {
		cout << prompt2;
	}
	else {
		cout << prompt3;
	}

	
}

int main() {

	// Gather Users Age in Years
	getAge();
	eyeColor();

	// Users Age Variants
	ageDays();
	ageHours();
	ageMinutes();
	ageSeconds();
	ageHeartbeats();

	// Old enough to drive?
	ageDriving();

	// Eye Color 

	return 0;
}

