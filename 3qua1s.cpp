#include <iostream>
using namespace std;

int pwr (int a, int b) {
	if(b==1) return a;
	return a*pwr(a,b-1);
}

int main () {
	const unsigned int power = 3;
	unsigned int max;
	cout << "Check (x^3)+(y^3)=2(z^3) <=> x=y=z for x,y,z between 1 and ";
	cin >> max; if(max==0)max=100;

	for(unsigned int i=1;i<=max;i++){
		for(unsigned int j=i;j<=max;j++) {
			for (unsigned int k=1;k<=max;k++) {
				if(pwr(i,power)+pwr(j,power)==2*pwr(k,power)) cout<<"i=j=k ::"<< i <<"="<< j <<"="<< k <<endl;
			}
		}
	}
	return 0;
}