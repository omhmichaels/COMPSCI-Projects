#pragma once
#include "UserInput.h"
#include <string>

getInput userInput;

class GatherInput {
	string basePrompt = "Please enter Country Name or applicable command: \n";
	string printDataPrompt = "The country %s current average is %i mins of TV\n";
	string updatedPrompt = "The watch time values for the country %s have been updated to %i mins\n";
	string deletedPrompt = "The watch time value %i mins for the country %s have been deleted\n";
	string continuePrompt = " Would you like to continue? y/n  \n";
	string countryPrompt = "Please enter the country: \n";
	string minutesPrompt = "Please enter the minutes: \n";
public:
	int getMins() {
		cout << userInput.minutesPrompt;
		int mins = userInput.getInt();
		return mins;
	}

	string getCountry() {
		cout << userInput.countryPrompt;
		string country = userInput.getString();
		return country;
	}
	/*
	void postUpdate() {
		printf(userInput.updatedPrompt, userInput.input data);
	}

	void postDelete() {
		printf(userInput.deletedPrompt, userInput.data, userInput.input);
	}*/
	/*
	void printData() {
		printf(userInput.basePrompt);
		cout << userInput.printDataPrompt, userInput.input, userInput.data;
	}
	*/
	void promptContinue() {
		cout << userInput.continuePrompt;
	}
	void promptBase() {
		cout << userInput.basePrompt;
	}
};


class Commands {

public:


	bool commandFlag;

	void addData(string input, int data) {
		ctryNames.push_back(input);
		ctryMins.push_back(data);
		cout << "You added data for " << input << " with the value " << data << endl;
		NUM_CTRY++;
		commandFlag = true;
	}


	/*
	/*
	void deleteData(string input) {
		for (int i = 0; i < NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryNames.erase(remove(ctryNames.begin(), ctryNames.end(), input), ctryNames.end());
				ctryMins.erase(remove(ctryNames.begin(), ctryNames.end(), input), ctryNames.end());
				cout << "You deleted data for " << input;
				NUM_CTRY--;
			}
		}
		commandFlag = true;
	}

	*/

	void deleteData(string input) {
		for (int i = 0; i < NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryNames.erase(ctryNames.begin() + i);
				ctryMins.erase(ctryNames.begin() + i);
				cout << "You deleted data for " << input;
				NUM_CTRY--;
			}
		}
		commandFlag = true;
	}
	void modData(string input, int data) {

		for (int i = 0; i < NUM_CTRY; ++i) {
			if (ctryNames.at(i) == input) {
				ctryMins.at(i) = data;
				cout << "You modified the data for " << input << " with the value " << data << endl;
			}
		}
		commandFlag = true;
	}

};


bool commandCheck(string input) {
	Commands cmd;
	bool commandFlag;
	cout << input << endl;
	if (input == "PRINT") {

		printCommand();
		commandFlag = true;
	}
	else if (input == "MAX") {
		maxCommand();
		commandFlag = true;
	}
	else if (input == "ADD") {
		interface.getCountry();
		interface.getMins();
		cmd.addData(userInput.input, userInput.data);
		printCommand();
		commandFlag = true;
	}
	else if (input == "DEL") {
		userInput.getString();
		cmd.deleteData(userInput.input);
		commandFlag = true;
	}
	else if (input == "MOD") {
		interface.getCountry();
		interface.getMins();
		cmd.modData(userInput.input, userInput.data);
		printCommand();
		commandFlag = true;
	}
	if (commandFlag == true) {
		return true;
	}
	else if (commandFlag == false) {
		return false;
	}
}

