#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	string carMake, carModel;
	double annualInterestRate, monthlyInterestRate, price, downPayment, tradein;
	double principal, monthlyPayment, salesTaxRate, salesTax;
	double numYears, numMonths;
	double monthlyPrincipal, monthlyInterest, loanBalance;
	// double and int operations can be inaccurate
	// get inputs
	cout << "Vehicle Loan Payment Calculator\n";
	cout << "-------------------------------\n";
	cout << "Please provide the following information.\n\n";
	cout << "Vehicle make: ";
	cin >> carMake;
	cout << "Vehicle model: ";
	cin >> carModel;
	cout << "Price of the vehicle ($): ";
	cin >> price;
	cout << "Sales tax rate (%): ";
	cin >> salesTaxRate;
	cout << "Down payment amount ($): ";
	cin >> downPayment;
	cout << "Trade-in value ($): ";
	cin >> tradein;
	cout << "Annual interest rate (%): ";
	cin >> annualInterestRate;
	cout << "Number of years of the loan: ";
	cin >> numYears;

	// calculate monthly payment
	salesTax = price * (salesTaxRate / 100);             // Order of Operations PEMDAS
	principal = price + salesTax - downPayment + tradein;
	monthlyInterestRate = annualInterestRate / 12 / 100;
	numMonths = numYears * 12;
	monthlyPayment = (principal * monthlyInterestRate) /( 1 - pow(1 + monthlyInterestRate, -numMonths));
	// Order of Operations PEMDAS
	// format numbers to two decimal points
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);

	// display results
	cout << endl << endl;
	cout << "Summary of Loan\n";
	cout << "---------------\n";
	cout << "Vehicle:             \t" << carMake << " " << carModel << endl;
	cout << "Price:               \t$" << price << endl;
	cout << "Sales Tax:           \t$" << salesTax << " @" << salesTaxRate << "%" << endl;
	cout << "Down payment:        \t$" << downPayment << endl;
	cout << "Trade-in value:      \t$" << tradein << endl;
	cout << "Loan principal:      \t$" << principal << endl;
	cout << "Annual Interest Rate:\t" << annualInterestRate << "%" << endl;;
	cout << "Term (years):        \t" << numYears << endl;
	cout << "Monthly Payment:     \t$" << monthlyPayment << endl;
	cout << endl << endl;

	cout << "Payoff Summary for the first twelve months\n";
	cout << "------------------------------------------\n\n";
	cout << setw(5) <<  "Month";
	cout << setw(18) << "Payment Amt ($)";
	cout << setw(18) << "Principal ($)";
	cout << setw(15) << "Interest ($)";
	cout << setw(18) << "Loan Balance ($)" << endl;
	cout << setw(5) << "-----";
	cout << setw(18) << "---------------";
	cout << setw(18) << "-------------";
	cout << setw(15) << "------------";
	cout << setw(18) << "----------------" << endl;
	
	// calcaulte monthly principal and interest contributions and balance
	loanBalance = principal;
	for (int i = 1; i <= numMonths; ++i){ 
		monthlyInterest = loanBalance * monthlyInterestRate;
		monthlyPrincipal = monthlyPayment - monthlyInterest;
		loanBalance = loanBalance - monthlyPrincipal;
		cout << setw(5) << i;
		cout << setw(18) << monthlyPayment;
		cout << setw(18) << monthlyPrincipal;
		cout << setw(15) << monthlyInterest;
		cout << setw(18) << loanBalance << endl;
	}

	cout << endl << endl;
	return 0;
}