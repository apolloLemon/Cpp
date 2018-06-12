#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> Range (int start, int max, int step);

int main (){
	double invest, rate; 
	std::cout << "How much to invest : "; std::cin >> invest;
	std::cout << "Intrest Rate : "; std::cin >> rate;
	rate *= .01;

	for(auto x: Range(1,10,1)) //made to look like python for loop
		invest+=(invest*rate);

	std::cout << "Value after 10 years : "<<invest<<std::endl;

	return 0;
}

//FUNCTIONS
std::vector<int> Range (int start, int max, int step){
	std::vector<int> out;
	for(int i=start;i<= max;i+=step)
		out.push_back(i);
	return out;
}
//END FUNCTIONS