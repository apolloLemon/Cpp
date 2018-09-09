#include <iostream>

int main (){

	int YearWeek;
	std::cout << "What week of the year is it? : ";std::cin >> YearWeek;

	int YearQuater = YearWeek/13;
	int nYearQuaterUnit = YearWeek%13;

	char cYearQuaterUnit;

	if(nYearQuaterUnit < 10) cYearQuaterUnit = (char)('0'+nYearQuaterUnit);
	else cYearQuaterUnit = (char)('a'-10+nYearQuaterUnit);

	std::cout << "In Year Quaters, it's week : "<<YearQuater<<cYearQuaterUnit<<std::endl;
}