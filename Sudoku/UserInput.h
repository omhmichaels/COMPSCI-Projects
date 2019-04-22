#pragma once
#include <string>

class getInput {

public:
	string input;
	int data;

	string getString() {
		cin >> input;
		return input;
	}


	int getInt() {
		cin >> data;
		return data;
	}
};

