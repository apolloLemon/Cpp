#include <iostream>
#include <ctime>

using namespace std;

int main () {
	time_t t = time(0);
    struct tm * now = localtime( & t );
    int y = now->tm_year+1900;
    int m = now->tm_mon+1;
    int d = now->tm_mday;
    int age = y-1999;
    if (d==30 && m==11) {
    	cout << "\n--===:: Happy Birthday Valentin!! ::===--\n              You're now "<<age<<endl<<endl;
    } else cout << "Fuck off\n";
	return 0;
}