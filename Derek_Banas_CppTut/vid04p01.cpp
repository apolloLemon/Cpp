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

/* Hints:
	- Decrement spaces by one each loop
	- Increment hashes by 2 each lopp
	- save spaces to the stump by calculating tree height-1
	- Decrement from tree height until equals zero (*-1)
	- Print spaces and then hashes for each row
	- Print stump spaces and then 1 hash
*/

int main (){

	int nTreeHight, maxSpaces, nSpaces, nHashes;
	std::cout << "How tall is the tree: ";std::cin>>nTreeHight;
	maxSpaces = nTreeHight-1;
	nSpaces = maxSpaces;
	nHashes = 1;

	for(auto i: Range(0,nTreeHight,1)){

		if(i==nTreeHight) continue;
		for(auto j: Range(1,nSpaces,1)) std::cout<<" ";
		for(auto k: Range(1,nHashes,1)) std::cout<<"#";

		nSpaces--; nHashes+=2; std::cout<<std::endl;


		//Combo space and # done before hints
		// Doesn't need extra forloop
		/*int d = i;
		if(d==nTreeHight) d=0;

		int w = 0;
		while(w<nTreeHight+d){
			if(w>=nTreeHight-d-1) std::cout<<"#";
			else std::cout <<" ";
			w++;
		}
		std::cout<<std::endl;*/
	}

	//Added forloop as last step of hints
	for(auto x: Range(1,maxSpaces,1)) std::cout<<" ";
	std::cout<<"#\n";

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