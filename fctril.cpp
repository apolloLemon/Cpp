#include <iostream> 
long f(long x){if(x==1)return 1;return x*f(x-1);} 
int main(){long x;std::cin>>x;std::cout<<x<<"! = "<<f(x)<<std::endl;return 0;}