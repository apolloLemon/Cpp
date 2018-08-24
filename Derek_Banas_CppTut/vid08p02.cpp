#include <iostream>

int fib(int a);

int main(){

	for(int i=0;i<10;i++){
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