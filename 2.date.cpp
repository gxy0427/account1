#include"date.h"
#include<iostream>
#include<cstdlib>
using namespace std;
const int DAYS[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxday()) {
		cout << "invalid date";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totaldays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS[month - 1] + day;
	if (isLeapYear() && month > 2) {
		totaldays++;
	}
}
int Date::getYear()const {
	return year;
}
int Date::getMonth()const {
	return month;
}
int Date::getDay()const {
	return day;
}
int Date::getMaxday()const {
	if (isLeapYear() && month == 2) {
		return 29;
	}
	else {
		return DAYS[month] - DAYS[month - 1];
	}
}
bool Date::isLeapYear()const {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int Date::distance(const Date& date)const {
	return totaldays - date.totaldays;
}
void Date::show() {
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}