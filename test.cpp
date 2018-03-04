#include <iostream>
#include <array>

using namespace std;
using tablo = array<int,5>;

int returnsomething (int* a) {
	int num;
	cout << "gimme";
	cin >> num;
	a[2] = num;
	return num;
}

int main () {
	int Nums[5]={0};
	int N = returnsomething(Nums);
	cout << N << Nums[2];
	return 0;
}