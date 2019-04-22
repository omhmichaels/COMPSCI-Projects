#pragma once

class getInput {

public:
	string input;
	int data;

	string basePrompt = "Please enter Country Name or applicable command: \n";
	string printDataPrompt = "The country %s current average is %i mins of TV\n";
	string updatedPrompt = "The watch time values for the country %s have been updated to %i mins\n";
	string deletedPrompt = "The watch time value %i mins for the country %s have been deleted\n";
	string continuePrompt = " Would you like to continue? y/n  \n";
	string countryPrompt = "Please enter the country: \n";
	string minutesPrompt = "Please enter the minutes: \n";

	string getString() {
		cin >> input;
		return input;
	}


	int getInt() {
		cin >> data;
		return data;
	}
};




