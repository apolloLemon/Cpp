#include <iostream>
#include <vector>

// This one is interesting as last semestre we looked at 
// Algorithms to find paterns in text during the 
// Formal Languages Course

std::vector<int> FindSubstringMatches(
	std::string phrase,
	std::string pattern);

int main(){
	std::string phrase = "aaaa a aa";
	std::vector<int> matches = FindSubstringMatches(phrase, "aa");

	for(int i=0; i < matches.size(); i++){
		std::cout << matches[i] << std::endl;
	}

	return 0;
}

std::vector<int> FindSubstringMatches(std::string phrase, std::string pattern){
	
	int patternLength = pattern.size();
	int matchingChars = 0;

	std::vector<int> out;

	for(int i=0;i<phrase.size();i++){
		if(phrase[i]==pattern[matchingChars]) {
			matchingChars++;
		}

		if(matchingChars == patternLength) {
			out.push_back(i-matchingChars+1);
			matchingChars=0;
		}
	}

	return out;
}