#include <functional>
#include <algorithm>
#include <iostream>

std::vector<int> GenerateFibList(int x);

int main () {

	//std::function<int(int)> Fib = [&Fib](int n){return (n<2)? n : Fib(n-1)+Fib(n-2);};
	//std::cout<<Fib(3)<<std::endl;

	std::vector<int> listofFibs = GenerateFibList(10);
	for(auto val: listofFibs)
		std::cout << val << std::endl;

	return 0;
}

//std::function<int(int)> Fib = [&Fib](int n){return (n<2)? n : Fib(n-1)+Fib(n-2);};

std::vector<int> GenerateFibList(int x){
	
	std::function<int(int)> Fib = 
	[&Fib](int n){return (n<2)? n : Fib(n-1)+Fib(n-2);};

	std::vector<int> out;
	
	for(int i=0;i<=x;i++){
		out.push_back(Fib(i));
	}

	return out;
}