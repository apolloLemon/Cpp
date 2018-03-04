#include <iostream>
using namespace std;

string get_word_of_size (int size);
bool are_all_char (string a, int b);
string correct_letters(string a, string b, int c);
bool equal_strings(string a, string b, int c);
string misplaced_letters (string a, string b);

int main() {
	const int wordsize = 8;
	string a,b;
	a = get_word_of_size(wordsize); system("clear");
	while(!equal_strings(a,b,wordsize)){
		b = get_word_of_size(wordsize);
		cout << "correct:   "<<correct_letters(a,b,wordsize)<<endl;
		cout << "misplaced: "<<misplaced_letters(a,b)<<endl;
	}

	return 0;
}

string get_word_of_size (int size) {
	string out = "0";
	while(out.length()!=size || !are_all_char(out, out.length())){
		cout << "Enter a word "<<size<<" characters long:\n";
		cin >> out;
	}
	return out;
}

bool are_all_char (string a, int b) {
	if(b<=0) return 1;
	return (toupper(a[b-1])>='A' && toupper(a[b-1])<='Z')*are_all_char(a,b-1);
}

string correct_letters (string a, string b, int c) {
	if(c<=0) return "";
	char current;
	if(toupper(a[c-1])==toupper(b[c-1])) current = a[c-1];
	else current='-';
	return correct_letters(a,b,c-1)+current;
}

bool equal_strings (string a, string b, int c) {
	if(c<=0) return 1;
	return (toupper(a[c-1])==toupper(b[c-1]))*equal_strings(a,b,c-1);
}


string sub_string (string a, int i, int size) {
	if(size == 0) return "";
	return a[i]+sub_string(a,i+1,size-1);
}

int occurance_lettre (string a, char b) {
	if(a.length()==0) return 0;
	return (toupper(a[0])==toupper(b))+occurance_lettre(sub_string(a,1,a.length()-1),b);
}

string misplaced_letters (string a, string b) {
	string out ="";
	int wi=0;
	while(wi<a.length()){
		if(a[wi]==b[wi]) {
			a.erase(wi,1);
			b.erase(wi,1);
			wi--;
		}
		wi++;
	}

	for(int i=0; i<a.length();i++){
		char c = tolower(b[i]);
		if(occurance_lettre(out,b[i])) continue;

		int bi_ina = occurance_lettre(a,c);
		int bi_inb = occurance_lettre(b,c);
		for(int i=0;i<min(bi_inb,bi_ina);i++){
			out += c;
			if(i+1<min(bi_ina,bi_inb)) out += ",";
		}
	}
	return out;
}