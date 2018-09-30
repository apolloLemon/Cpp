#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>


void FileSave ();
void FileLoad ();

int ParsePassedMoments ();
int ParsePassedDays ();

int ParseDay ();
int ParseYear ();

int main () {
	std::time_t t = time(NULL);

	std::cout<< std::gmtime(&t)->tm_day <<std::endl;
	/*int testday = 270;

	std::string sDay = std::put_time(std::gmtime(&t), "%j");
	int currentday = (int)sDay;
	std::cout << "Time days since day 270 : "<<currentday-testday<<std::endl;
	std::cout << "Time : " <<std::put_time(std::gmtime(&t), "%j %Y")<<std::endl;
	*/
}

/*void FileLoad () {
	ifstream Data("data.txt");

	int day, year;
	Data >> day >> year
	while();
}*/