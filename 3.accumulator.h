#ifndef ACCUMULATOR_H__
#define ACCUMULATOR_H__
#include<iostream>
#include"date.h"
using namespace std;
class Accumulator {
private:
	Date lastdate;
	double value;
	double sum;
public:
	Accumulator(const Date& date, double value) :lastdate(date), value(value), sum(0) {};
	double getSum(const Date& date)const {
		return sum + value * date.distance(lastdate);
	}

	void change(const Date& date, double value) {
		sum = getSum(date);
		lastdate = date;
		this->value = value;
	}
	void reset(const Date& date, double value) {
		lastdate = date;
		this->value = value;
		sum = 0;
	}
};
#endif

