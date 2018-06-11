#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> Range (int start, int max, int step);

int main (){
	std::vector<int> a = Range(1,10,1);
	for(auto x: a) std::cout<<x<<std::endl; 

	return 0;
}

//FUNCTIONS
std::vector<int> Range (int start, int max, int step){
	std::vector<int> out;
	for(int i=start;i<=max;i+=step)
		out.push_back(i);
	return out;
}
//END FUNCTIONS