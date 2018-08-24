#include <iostream>

int fib(int a);

int main(){

	int index;
	std::cout << "Get Fibonacci Index : "; std::cin >> index;

	for(int i=0;i<=index;i++){
		std::cout << fib(i) << " ";
	}

	std::cout<<std::endl;
	return 0;
}

int fib(int a){
	if (a==0) return 0;
	if (a==1) return 1;
	return fib(a-1)+fib(a-2);
}