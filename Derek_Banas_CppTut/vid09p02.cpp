#include <functional>
#include <algorithm>
#include <iostream>

int main () {

	std::function<int(int)> Fib = 
	[&Fib](int n){return (n<2)? n : Fib(n-1)+Fib(n-2);};

	std::cout<<Fib(3)<<std::endl;

	return 0;
}