#include"date.h"
#include<iostream>
#include<cstdlib>
using namespace std;
namespace { const int DAY[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 }; }
Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxday()) {
		cout << "invalid date";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAY[month - 1] + day;
	if (isLeapYear() && month > 2) {
		totalDays++;
	}
}
int Date::getMaxday()const {
	if (isLeapYear() && month == 2) {
		return 29;
	}
	else {
		return DAY[month] - DAY[month - 1];
	}
}
bool Date::isLeapYear()const {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
void Date::show()const {
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}
int Date::distance(const Date& date)const {
	return totalDays - date.totalDays;
}