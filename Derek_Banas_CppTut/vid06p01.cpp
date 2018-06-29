#include <iostream>
#include <vector>

std::string VectorToString(std::vector<std::string> Customers, char separator);

int main () {
	std::vector<std::string> vCusts(3);
	vCusts[0] = "Bob";
	vCusts[1] = "Sue";
	vCusts[2] = "Tom";

	std::string sCusts = VectorToString(vCusts, ' ');
	std::cout << sCusts << "\n";
}

std::string VectorToString(std::vector<std::string> Customers, char separator){
	std::string  out = "";
	for(auto x: Customers)
		out += x + separator;

	return out;
}