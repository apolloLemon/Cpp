#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>

int main () {
	std::string usrin;
	std::cout << "Enter calculation: ";getline(std::cin, usrin);

	std::string tmpString;
	std::vector<std::string> words;
	std::stringstream ss(usrin);
	char delimiter = ' ';
	while(getline(ss,tmpString,delimiter)){
		words.push_back(tmpString);
	}

	float a, b;
	a = std::stof(words[0]); 
	b = std::stof(words[2]);
	std::string operation = words[1];

	if (operation == "+")
		std::cout<<a<<" + "<<b<<" = "<<a+b<<std::endl;
	else if (operation == "-")
		std::cout<<a<<" - "<<b<<" = "<<a-b<<std::endl;
	else if (operation == "*")
		std::cout<<a<<" * "<<b<<" = "<<a*b<<std::endl;
	else if (operation == "/")
		std::cout<<a<<" / "<<b<<" = "<<a/b<<std::endl;
	else
		std::cout<<"Please use + - * /\n";

	return 0;
}