#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

#include <array>
const unsigned int BUFF = 14600;
using strings = array<string, BUFF>;

struct array_dic {
	strings D;
	int size;
};

bool in_array_dic (string e, array_dic D);
array_dic load_array_dic (string dictionary, int wordsize);
bool leq_string (string a, string b, int ltr);
string get_word_of_size (int size, array_dic dic);
bool are_all_char (string a, int b);
string correct_letters(string a, string b, int c);
bool equal_strings(string a, string b, int c);
string misplaced_letters (string a, string b);

int main() {
	srand(time(NULL));
	time_t start = time(0);

	const int max_attemps = 12;
	const int wordvalue = max_attemps*max_attemps;
	const int wordsize = 8;

	array_dic motus_dic;
	motus_dic = load_array_dic("en_n.motus",wordsize);

	string a,b,c;
	a = motus_dic.D[rand()%motus_dic.size];
	//a = get_word_of_size(wordsize, motus_dic); cout << flush;

	int attempt=0;
	while(!equal_strings(a,b,wordsize) && attempt<12){
		b = get_word_of_size(wordsize, motus_dic);
		cout << "correct:   "<<correct_letters(a,b,wordsize)<<endl;
		cout << "misplaced: "<<misplaced_letters(a,b)<<endl;
		attempt++;
	}
	int seconds_since_start = difftime( time(0), start);
	cout << "The word was \""<<a<<"\", you win "<<(wordvalue-attempt*attempt)*1000/seconds_since_start+1000<<" points!\n("<<attempt<<" attempts, "<<seconds_since_start<<"s)\n";
	return 0;
}

string get_word_of_size (int size, array_dic dic) {
	cout << "get_word\n";
	string out = "0";
	while(out.length()!=size || !are_all_char(out, out.length()) || !in_array_dic(out, dic)){
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
		for(int i=0;i<min(bi_inb,bi_ina);i++) out += c;
	}
	return out;
}

//Dictionary Code
array_dic load_array_dic (string dictionary, int wordsize){
	cout << "loading dictionary";
	array_dic out;
	char word[9];
	ifstream read; read.open(dictionary);
	out.size = 0;
	while(read){
		read.getline(word, wordsize+1);
		out.D[out.size++]=word;
	}

	cout << " completed\n";
	return out;
}

bool leq_string (string a, string b, int ltr){
	if(ltr == min(a.length(),b.length())) return 1;
	if(a[ltr]<b[ltr]) return 1;
	if(a[ltr]>b[ltr]) return 0;
	return leq_string (a,b,ltr+1);
}

bool inArray_rec (string e, strings D, int i, int j) {
	cout << "looking in between "<<i<<" and "<<j<<" ... \n";
	if(e==D[i]) return 1;
	if(i==j-1) return 0;

	int p = (i+j)/2;
	if(leq_string(D[p],e,0)) return inArray_rec(e,D,p,j);
	else return inArray_rec(e,D,i,p);
}

bool in_array_dic (string e, array_dic Dic) {
	cout << "looking for word in dic\n";
	return inArray_rec(e,Dic.D,0,Dic.size);
}