#include <iostream>

using namespace std;

int main () {
	float distance, consumption, fuelprice;
	cout << "Enter distance, consumption(l/100km), fuelprice(currency/l) separated by spaces:\n";
	cin >> distance >> consumption >> fuelprice;

	consumption = consumption/100;


	cout << "Price of Trip: "<<distance*consumption*fuelprice << endl;

	return 0;
}