#include <iostream>
#include <ctime>
using namespace std;
const unsigned int D = 30;
const unsigned int M = 11;
const unsigned int Y = 1999;
const string name = "Valentin";

bool bisex (int y) {
	if(y%400==0)return 1;
	else if (y%4==0 && y%100!=0) return 1;
	return 0;
}

int monthlen (unsigned int m, int y) {
	if (m==2) return 28+bisex(y);
	else if (m<8 && m%2!=0) return 31;
	else if (m>=8 && m%2==0) return 31;
	return 30;
}

int dayzfromzero (int d, int m, int y) {
	int dayz = d;
	for(int i=0;i<=y;i++) dayz+=365+bisex(i);
	for(int i=1;i<=m;i++) dayz+=monthlen(i,y);
	return dayz;
}

int daysleft (int d, int m, int y) {
	int x=y;
	if (m==12) x++;
	return dayzfromzero(D,M,x)-dayzfromzero(d,m,y);
}

int main () {
	time_t t = time(0);
    struct tm * now = localtime( & t );
    int y = now->tm_year+1900;
    int m = now->tm_mon+1;
    int d = now->tm_mday;
    int age = y-Y;
    if (d==D && m==M) {
    	cout<<"\n--===:: Happy "<<age<<"th Birthday "<<name<<"!! ::===--\n\n";
    } else {
    	if(m==12) {
	    	cout<<"\n I hope you had a happy birthday :)";
	    	if (d>15) cout<<" It's xMas soon!";
    		cout<<endl;
    	}
    	int a = daysleft(d,m,y);
    	string day = (a==1)?" day":" days";
    	cout << " Only "<<a<<day<<" to wait!\n\n";
    }
	return 0;
}