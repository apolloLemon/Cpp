#include <iostream>

int main () {

	std::string sAge;
	int nAge;

	std::cout << "Enter age : "; std::cin >> sAge; 
	nAge = std::stoi(sAge);

	if(nAge == 5) std::cout << "Go to Kindergarten\n";
	else if(nAge >= 6 && nAge <= 17) 
		std::cout << "Go to grade "<<nAge-5<<std::endl;
	else if(nAge > 17) std::cout << "Go to college\n";
	else std::cout << "Too young for school\n";

	return 0;
}