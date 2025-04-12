
#define  DATE_H__
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
	int totaldays;
public:
	Date(int year, int month, int day);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	int getMaxday()const;
	bool isLeapYear()const;
	void show();
	int distance(const Date& date)const;
};


