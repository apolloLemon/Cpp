#include <string>
#include <sstream>
#include <iostream>

int main () {

	std::string usrin, out="";
	std::cout<<"Enter word: ";std::cin>>usrin;

	for(char a: usrin) {
		out = out + std::to_string((int)a);
	}

	std::cout<<out<<std::endl;
	return 0;
}