/*
 *
 * # Cashier Program
 * # Description: Project 1 Small Cashier simulated program
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 3-05-19
 */


 // Includes
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

char username[50];       // Global Variables
char item1[50];          // String variables
char item2[50];
char item3[50];

int item1Quant;          // Quantity Variables
int item2Quant;
int item3Quant;

double item1Price;       // Price Variables
double item2Price;
double item3Price;

double tax;
double total;
double money;
double pretax;

/*
int dollars = 1;
int fives = 5;
int tens = 10;
int twenties = 20;
int fifties = 50;
int hundreds = 100;
double quarters = 0.25;
double dimes = 0.1;
double nickle = 0.5;
double pennies = 0.01;
*/

double hundreds, twenties, fives, ones;
double quarters, dimes, nickles, pennies;



// Prompt Variables
char pricePrompt[50] = "Please enter a price for %s\n";
char priceConfirm[50] = "The price of %s is $%f\n\n";
char itemPrompt[50] = "Choose a item:  \n";
char itemConfirm[50] = "The item you chose was %s\n\n";
char quantPrompt[30] = "How many units of %s? \n";
char quantConfirm[50] = "You have %f of %s\n\n";


// Formatting Functions
void spacing()
{
	cout << "\n\n";
}

void pantherExpress()
{
	cout << "------------ Panther Express Cashier Interface ---------------\n";
}

void pantherExpress2()
{
	cout << setfill('-') << setw(50) << "Panther Express Cashier Interface" << setw(25);
	spacing();
}

void interface1()
{
	cout << setfill('-') << setw(50) << '-';
	spacing();
}

void interface2()
{
	cout << "--------------------------------------------------------------\n";
}

void costSum()
{
	cout << "$--------------Cost Summary ----------------------------------$\n";
}

void costSum2()
{
	cout << setfill('-') << setw(25)<< "Cost Summary" << setw(25);
}

void costPreTax()
{
	cout << "$--------------Cost Pretax ----------------------------------$\n";
}
void costPreTax2()
{
	cout << setfill('-') << setw(25) << "Cost PreTax" << setw(25);
}


void costTax()
{
	cout << "$--------------Cost w/ Tax ----------------------------------$\n";
}

void costTax2()
{
	cout << setfill('-') << setw(25) << "Cost w/ Tax" << setw(25);
}


void change()
{
	cout << "$--------------Change ---------------------------------------$\n";
}

void change2()
{
	cout << setfill('-') << setw(25) << "Change" << setw(25);
}



void namePrompt()
{
	char greeting[100] = "Hello Welcome to Panther Express\n";
	cout << greeting << "\n";
	cout << "My name is Panny Panther What is yours ...\n" << "Please enter your name: \n";
	cin >> username;
	cout << "\nAHA, " << username << " we've been waiting for you\n";
}


void itemEntry()
{
	printf(itemPrompt);
	cin >> item1;
	printf(itemConfirm, item1);
	cout << itemPrompt;
	cin >> item2;
	printf(itemConfirm, item2);
	cout << itemPrompt;
	cin >> item3;
	printf(itemConfirm, item3);
}

void priceEntry()
{
	printf(pricePrompt, item1);
	cin >> item1Price;
	printf(priceConfirm, item1, item1Price);
	printf(pricePrompt, item2);
	cin >> item2Price;
	printf(priceConfirm, item2, item2Price);
	printf(pricePrompt, item3);
	cin >> item3Price;
	printf(priceConfirm, item3, item3Price);
}

void quantEntry()
{
	printf(quantPrompt, item1);
	cin >> item1Quant;
	printf(quantConfirm, item1Quant, item1);
	printf(quantPrompt, item2);
	cin >> item2Quant;
	printf(quantConfirm, item2Quant, item2);
	printf(quantPrompt, item3);
	cin >> item3Quant;
	printf(quantConfirm, item3Quant, item3);
}

void item1Input()
{
	printf(itemPrompt);
	cin >> item1;
	printf(itemConfirm, item1);
	printf(pricePrompt, item1);
	cin >> item1Price;
	printf(priceConfirm, item1, item1Price);
	printf(quantPrompt, item1);
	cin >> item1Quant;
	printf(quantConfirm, item1Quant, item1);
}

void item2Input()
{
	printf(itemPrompt);
	cin >> item2;
	printf(itemConfirm, item2);
	printf(pricePrompt, item2);
	cin >> item2Price;
	printf(priceConfirm, item2, item2Price);
	printf(quantPrompt, item2);
	cin >> item2Quant;
	printf(quantConfirm, item2Quant, item2);
}

void item3Input()
{
	printf(itemPrompt);
	cin >> item3;
	printf(itemConfirm, item3);
	printf(pricePrompt, item3);
	cin >> item3Price;
	printf(priceConfirm, item3, item3Price);
	printf(quantPrompt, item3);
	cin >> item3Quant;
	printf(quantConfirm, item3Quant, item3);
}

void taxRate()
{
	printf("What is the tax rate:  \n");
	cin >> tax;
	cout << "The tax rate is " << tax;
	spacing();
}



void charge()
{
	cout << "How much money do you have? \n";
	cin >> money;
	cout << "You gave me " << money << "\n\n";
}



void printout_1()
{
	char prompt1[50] = "Unit name: %s\n";
	char prompt2[50] = "Unit price for: %f\n";
	char prompt3[50] = "Unit quantity for: %f\n";

	pantherExpress();
	printf(prompt1, item1);
	printf(prompt2, item1Price);
	printf(prompt3, item1Quant);
	spacing();

	printf(prompt1, item2);
	printf(prompt2, item2Price);
	printf(prompt3, item2Quant);
	spacing();

	printf(prompt1, item3);
	printf(prompt2, item3Price);
	printf(prompt3, item3Quant);
	spacing();

	printf("The tax rate is %f", tax);
	spacing();

	interface2();
}


void changePrompt()
{
	double changeAmt = total - money;
	cout << "Your change is: " <<  changeAmt << "\n\n";
	cout << "Denominations ....\n";
	cout << "$100 bills: " << hundreds << endl;
	cout << "$20 bills: " << twenties << endl;
	cout << "$5 bills: " << fives << endl;
	cout << "$1 bills: " << ones << endl;
	cout << "Quarters: " << quarters << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Nickles: " << nickles << endl;
	cout << "Pennies: " << pennies << endl;
}

void moneyReturn()
{
	while (money > 0)
	{
		if (money >= 100)
		{
			money -= 100;
			hundreds += 1;
		}

		else if (money >= 20)

		{
			money -= 20;
			twenties += 1;
		}

		else if (money >= 5)
		{
			money -= 5;
			fives += 1;
		}

		else if (money >= 1)
		{
			money -= 1;
			ones += 1;
		}


		else if (money >= 0.25)
		{
			money -= 0.25;
			quarters += 1;
		}

		else if (money >= 0.10)
		{
			money -= 0.1;
			dimes += 1;
		}

		else if (money >= 0.05)
		{
			money -= 0.05;
			nickles += 1;
		}

		else if (money >= 0.01)
		{
			money -= 0.05;
			pennies += 0.01;
		}
	}
}

void preTax()
{
	char prompt[50] = "Pretax amount: %f";
	pretax = ((item1Price*item1Quant) + (item2Price*item2Quant) + (item3Price + item3Quant));
	costPreTax2();
	spacing();
	printf(prompt, pretax);
	spacing();
	interface2();
}

void totalwTax()
{
	char prompt[50] = "The total is: %f";
	total = ((pretax * tax)+pretax);
	costTax2();
	spacing();
	printf(prompt, total);
	spacing();
	interface2();
}


int main()
{

	pantherExpress2();
	namePrompt();
	interface2();
	
	item1Input();
	item2Input();
	item3Input();

	taxRate();
	charge();
	preTax();
	

	pantherExpress();
	printout_1();
	// Cost Summary Printout

	// Cost Pretax 
	preTax();

	// Cost w/Tax Printout
	totalwTax();

	// Change Printout
	 moneyReturn();
     changePrompt();
	


	return (0);
}

