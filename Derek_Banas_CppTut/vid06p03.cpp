#include <iostream>
#include <vector>

std::vector<int> FindSubstringMatches(
	std::string phrase,
	std::string word);

std::string ReplaceAllSubstrings(
	std::string phrase,
	std::string rmWord,
	std::string adWord
	);

int main(){
	
	std::cout << ReplaceAllSubstrings("to know or not to know", "know", "be") << std::endl;

	return 0;
}

/*std::vector<int> FindSubstringMatches(std::string theString, std::string word) {
	std::vector<int> matchingIndexes;
	int index = theString.find(word, 0);
	while(index != std::string::npos){
		matchingIndexes.push_back(index);
		index = theString.find(word,index+1);
	}
	return matchingIndexes;
}*/
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

std::string ReplaceAllSubstrings(std::string phrase,std::string rmWord, std::string adWord) {
	std::vector<int> matches = FindSubstringMatches(phrase, rmWord);
	for(int i= matches.size()-1;i>=0;i--) {
		phrase = phrase.replace(matches[i],rmWord.size(),adWord);
	}
	return phrase;
}