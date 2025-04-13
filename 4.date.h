#ifndef DATE_H__
#define DATE_H__
#include<iostream>
class Date {
private:
	int year;
	int month;
	int day;
	int totalDays;
public:
	Date(int year, int month, int day);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	int getMaxDay()const;
	bool isLeapYear() const{
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	
	int operator-(const Date& date) const {
		
		return totalDays - date.totalDays;
	}
	void show()const;
};
#endif
