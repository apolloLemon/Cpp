#include <iostream>

using namespace std;

long factorial (long x) {
	if (x==1) return 1;
	return x*factorial(x-1);
}

int main () {
	long x;
	cout << "What number do you want the factorial of? (Max 20)" << endl;
	cin >> x;

	cout << x << "! = " << factorial(x);

	cout << endl;
	return 0;
}