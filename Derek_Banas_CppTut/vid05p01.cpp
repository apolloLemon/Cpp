#include <string>
#include <sstream>
#include <iostream>

int main () {

	std::string usrin, out="";
	std::cout<<"Enter word: ";std::cin>>usrin;

	for(char a: usrin) {
		out += std::to_string((int)a);
	}
	std::cout<<out<<std::endl;

	//resetting to convert back
	usrin = out; out="";
	for(int i=0;i<usrin.length();i+=2){
		out += (char)((int)usrin[i]-'0')*10+((int)usrin[i+1]-'0');
	}
	std::cout<<out<<std::endl;
	return 0;
}