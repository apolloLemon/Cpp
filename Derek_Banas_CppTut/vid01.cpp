#include <cstdlib>
#include <iostream>
#include <string>

int main () { 
	std::string sMiles;
	double nMiles;

	std::cout << "Enter Miles : "; std::cin >> sMiles;
	nMiles = std::stod(sMiles);
	printf("%.3f miles equals %.3f killometers\n", nMiles, nMiles*1.60934);

	return 0;
}