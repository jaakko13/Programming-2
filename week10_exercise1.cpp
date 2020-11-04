#include <iostream>
#include <string>
using namespace std;

class Date {
protected:
	
public:
	static int day;
	static int month;
	static int year;

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
int Date::day;
int Date::month;
int Date::year;

int main() {
	int day;
	int month;
	int year;

	Date today(0, 0, 0);

	try
	{
		cout << "Enter the day:";
		cin >> day;
		
		if (day > 31 || day < 1)
		{
			throw 0;
		}
		today.setDay(day);
	}
	catch (int x)
	{
		cout << "That is not a valid day. Error:" << x << endl;
	}

	try
	{
		cout << "Enter the month:";
		cin >> month;

		if (month < 1 || month > 12)
		{
			throw 02;
		}
		today.setMonth(month);

	}

	catch (int x)
	{
		cout << "This is not a valid month. Error:" << x << endl;
	}


	cout << "Enter the year:";
	cin >> year;
	today.setYear(year);
	
	today.print1();
	
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