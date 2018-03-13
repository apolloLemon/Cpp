#include <fstream>
#include <iostream>
using namespace std;

#include <array>
const unsigned int BUFF = 12000;
using strings = array<string, BUFF>;

struct array_dic {
	strings D;
	int size;
};

bool in_array_dic (string e, array_dic D);

array_dic load_array_dic (string dictionary);

bool leq_string (string a, string b, int ltr);


int main () {
	array_dic motus_dic;
	motus_dic = load_array_dic("motus_huit.dic");

	cout << motus_dic.size;
	cout << motus_dic.D[84];

	cout<<endl;
	return 0;
}

array_dic load_array_dic (string dictionary){
	array_dic out;
	char word[9];
	ifstream read; read.open(dictionary);
	out.size = 0;
	while(read){
		read.getline(word, 9);
		out.D[out.size++]=word;
	}


	return out;
}

bool leq_string (string a, string b, int ltr){
	if(ltr == min(a.length(),b.length())) return 1;
	if(a[ltr]<b[ltr]) return 1;
	if(a[ltr]>b[ltr]) return 0;
	return leq_string (a,b,ltr+1);
}

bool inArray_rec (string e, strings D, int i, int j) {
	if(e==D[i]) return 1;
	if(i==j-1) return 0;

	int p = (i+j)/2;
	if(leq_string(D[p],e,0)) return inArray_rec(e,D,p,j);
	else return inArray_rec(e,D,i,p);
}

bool in_array_dic (string e, array_dic Dic) {
	return inArray_rec(e,Dic.D,0,Dic.size);
}