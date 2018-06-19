#include <iostream>

int main (){

	int nTreeHight;
	std::cout << "How tall is the tree: ";std::cin>>nTreeHight;

	for(int i=0;i<=nTreeHight;i++){
		
		int d = i;
		if(d==nTreeHight) d=0;

		int w = 0;
		while(w<nTreeHight+d){
			if(w>=nTreeHight-d-1) std::cout<<"#";
			else std::cout <<" ";
			w++;
		}
		std::cout<<std::endl;
	}

	return 0;
}