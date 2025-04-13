#include"date.h"
#include<iostream>
#include<cstdlib>
using namespace std;
const int DAY[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
Date::Date(int year, int month, int day):year(year),month(month),day(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "invilid";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = years * 365 + year / 4 - years / 100 + years / 400 + DAY[month-1] + day;
	if (isLeapYear() && month > 2)
		totalDays++;
}
int Date::getYear()const { return year; }
int Date::getMonth()const { return month; }
int Date::getDay()const { return day; }
int Date::getMaxDay()const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAY[month] - DAY[month - 1];
}

void Date::show()const {
	cout << getYear() << "-" << getMonth() << "-" << getDay() ;
}