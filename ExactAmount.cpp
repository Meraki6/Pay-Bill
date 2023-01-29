#include <iostream>

using namespace std;

int main() {
	int		n10Dollar, n20Dollar, n50Dollar, n100Dollar, n500Dollar, bill;
	int		c10, c20, c50, c100, c500;

	// Original number of coins in pocket
	cout << "Original number of bills in wallet:" << endl;
	cout << "Number of 10-Dollar bills: "; cin >> n10Dollar;
	cout << "Number of 20-Dollar bills: "; cin >> n20Dollar;
	cout << "Number of 50-Dollar bills: "; cin >> n50Dollar;
	cout << "Number of 100-Dollar bills: "; cin >> n100Dollar;
	cout << "Number of 500-Dollar bills: "; cin >> n500Dollar;
	cout << endl;

	// Bill to pay.
	// Assume bill amount is a whole integer multiples of 10
	cout << "Bill Amount : "; cin >> bill;
	cout << endl;

	// Fill in the code to calculate payment in terms of number of x-Dollar bills.
	// If not enough money, number of x-Dollar bills in payment should all be 0s.
	// Bill should be settled in exact amount; otherwise, number of x-Dollar bills 
	// in payment should all be 0s. 

	c10 = 0; c20 = 0; c50 = 0; c100 = 0; c500 = 0;

	// TODO
	/*
	First judge whether coin needed can be covered by coins in pocket by evaluating bill / x <= nxDollar where x = 500, 100, 50, 20, 10 by decreasing order
	Decreasing order is used to use coins with large denomination first
		If TRUE, just use coin needed in pocket which equals to bill / x
		If FALSE, two cases may happen:
			bill / x is evaluated as 0 thus we do not need this x coin
			bill / x is greater than 0 which means that we need it but coins in pocket are not enough to cover all needs
				In this case, there are also two cases possible to happen:
					i. bill is larger than money in pocket thus we cannot afford it finally
					ii. bill is only larger than coin in pocket but smaller than total money thus we can afford it
				Here we all set them as coin in pocket, final juedgement can specify these two cases
	*/
	c500 = (bill / 500 <= n500Dollar) ? (bill / 500) : (bill / 500 > 0 ? n500Dollar : 0);
	bill -= c500 * 500; // continue reducing bill we need to pay by coins we decide to pay out
	c100 = (bill / 100 <= n100Dollar) ? (bill / 100) : (bill / 100 > 0 ? n100Dollar : 0);
	bill -= c100 * 100;
	c50 = (bill / 50 <= n50Dollar) ? (bill / 50) : (bill / 50 > 0 ? n50Dollar : 0);
	bill -= c50 * 50;
	c20 = (bill / 20 <= n20Dollar) ? (bill / 20) : (bill / 20 > 0 ? n20Dollar : 0);
	bill -= c20 * 20;
	c10 = (bill / 10 <= n10Dollar) ? (bill / 10) : (bill / 10 > 0 ? n10Dollar : 0);
	bill -= c10 * 10;

	/*
	final judegement to specify before two cases
		case i we cannot afford to pay: remained bill > 0 thus all coins are set to 0
		case ii we can afford it: bill = 0 thus no action to do
	Here also specify another case that bill is not settled in exact amount, bill > 0 in this case thus all are set to be 0
	*/
	if (bill != 0) c500 = c100 = c50 = c20 = c10 = 0;


	cout << "Payment:" << endl;
	cout << "Number of 10-Dollar bills: " << c10 << endl;
	cout << "Number of 20-Dollar bills: " << c20 << endl;
	cout << "Number of 50-Dollar bills: " << c50 << endl;
	cout << "Number of 100-Dollar bills: " << c100 << endl;
	cout << "Number of 500-Dollar bills: " << c500 << endl;
	return 0;
}