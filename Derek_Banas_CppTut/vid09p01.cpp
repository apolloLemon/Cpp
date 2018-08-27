#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max);

int main() {
    
    std::vector<int> vecVals = GenerateRandVec(10,1,50);

    int div;
    std::cout << "List of Values Divisable by : "; std::cin >> div;

    std::vector<int> vecVals2;

    std::copy_if(
        vecVals.begin(),vecVals.end(),
        std::back_inserter(vecVals2),
        [&](int x){return(x%div)==0;}
    );

    std::for_each(vecVals2.begin(),vecVals2.end(),
        [](int x){std::cout<<x<<std::endl;});
}
 

std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    std::vector<int> vecValues;
    
    // Seed the random number generator
    srand(time(NULL));
    
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        // The min added on increases result based on min
        // The remainder of modulus can't be greater
        // then the divisor. We have to adjust down
        // based on the addition from min
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}