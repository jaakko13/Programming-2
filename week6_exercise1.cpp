#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	static string wordmonth[];

	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void setDay(int d) {
		day = d;
	}
	void setMonth(int m) {
		month = m;
	}
	void setYear(int y) {
		year = y;
	}

	int getDay() {
		return day;
	}
	int getMonth() {
		return month;
	}
	int getYear() {
		return year;
	}
	void print1();
	void print2();
	void print3();

};

string Date::wordmonth[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


int main() {
	Date today(7, 2, 2020);
	today.print1();

	today.setDay(31);
	today.setMonth(5);
	today.setYear(2000);
	today.print2();


	today.setDay(6);
	today.setMonth(12);
	today.setYear(1917);
	today.print3();
}

void Date::print1() {
	cout << day << "/" << month << "/" << year << endl;
}

void Date::print2() {
	cout << wordmonth[month - 1] << " " << day << ", " << year << endl;
}

void Date::print3() {
	cout << day << " " << wordmonth[month - 1] << " " << year << endl;
}


