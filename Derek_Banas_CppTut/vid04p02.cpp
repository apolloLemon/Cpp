#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
	srand(time(NULL));
	int secretNum = std::rand()%11;
	int guess = 0;

	while(true){
		std::cout <<"Guess the number : ";
		std::cin >> guess;
		if(guess == secretNum) break;
		if(guess<secretNum) std::cout<<"To Small. ";
		if(guess>secretNum) std::cout<<"To Big. ";
	}
	std::cout<<"You guessed it\n";

	return 0;
}