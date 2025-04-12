#ifndef DATE_H__
#define DATE_H__
#include<iostream>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
	int totalDays;
public:
	Date(int year, int month, int day);
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getMaxday()const;
	bool isLeapYear()const;
	void show()const;
	int distance(const Date& date)const;
};
#endif
