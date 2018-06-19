#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> Range (int start, int max, int step);

/* Goal:
How tall is the tree: 5
    #
   ###
  #####
 #######
#########
    #
*/

int main (){

	int nTreeHight;
	std::cout << "How tall is the tree: ";std::cin>>nTreeHight;

	for(auto i: Range(0,nTreeHight,1)){

		//Trying to use continue and Break
		/*int iSpace = nTreeHight-1 , iHash = (nTreeHight-1)*2+1; //Max number of spaces of hashtags
		//Spaces loop
		while(iSpace){
			std::cout<<" ";
			iSpace--;
		}
		std::cout<<"#";*/


		//Combo space and # done before hints
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

//FUNCTIONS
std::vector<int> Range (int start, int max, int step){
	std::vector<int> out;
	for(int i=start;i<=max;i+=step)
		out.push_back(i);
	return out;
}
//END FUNCTIONS