#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	
public:
	static int day;
	static int month;
	static int year;
	static string wordmonth[];

	Date(int d, int m, int y) {
		this->day = d;
		month = m;
		year = y;
	}
	Date(int d) {
		this->day = d;
	}
	Date() {

	}
	void setDay(int d) {
		this->day = d;
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

	Date operator ++ () {
		day++;
		return *this;
	}
	Date operator ++ (int) {
		if (Date::day == 31 && Date::month == 12){
		year++;
		month = 1;
		day = 1;
		return day;
		}
		else if (Date::day == 31)
		{
			month++;
			day = 1;
			return day;
		}
		
		else if (0 < Date::day < 31)
		{
			Date day = *this;
			++* this;
			return day;
		}
		
	}
	Date operator -- () {
		day--;
		return day;
	}
	Date operator -- (int) {
		if (Date::day == 1 && Date::month == 1)
		{
			year--;
			month = 12;
			day = 31;
			return day;
		}
		else if (Date::day == 1)
		{
			month--;
			day = 31;
			return day;
		}
		else if (1 < Date::day < 32)
		{
			--day;
			return day;
		}
		
	}

	Date operator - (Date v) {
		Date temp;
		temp.day = day - v.day;
		temp.month = month;
		temp.year = year;
		return temp;
	};	
	

	friend ostream& operator << (ostream& output, Date& obj);
	friend istream& operator >> (istream& input, Date& obj);
};
int Date::day;
int Date::month;
int Date::year;

ostream& operator << (ostream& output, Date& obj) {
	output << Date::wordmonth[Date::month - 1] << " " << Date::day << ", " << Date::year;
	return output;
}

istream& operator >> (istream& input, Date& obj) {
	input >> Date::day >> Date::month >> Date::year;
	return input;
}

string Date::wordmonth[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


int main() {
	
	
	Date today(7, 2, 2020);
	today.print1();
	today++;
	today.print1();

	Date birth(31, 5, 2000);
	birth.print2();
	birth++;
	birth.print2();
	

	Date newyear(31, 12, 2000);
	newyear.print2();
	newyear++;
	newyear.print2();

	Date independence(6, 12, 1917);
	independence.print3();
	independence--;
	independence.print3();

	Date first(1, 5, 2098);
	first.print3();
	first--;
	first.print3();

	Date firstjan(1, 1, 2000);
	firstjan.print3();
	firstjan--;
	firstjan.print3();

	Date whatever(19, 6, 1920);

	whatever.print3();
	

	int x = 0;
	Date user;
	
	while (x == 0)
	{
		cout << "Enter a date(all numbers):" << endl;
		cin >> user;
		if (0 < user.day && user.day < 32 && 0 < user.month && user.month < 13)
		{
			user.print3();
			x = 1;
		}
		else if (user.day > 31 || user.day < 1 || user.month < 1 || user.month > 12)
		{
			cout << "That is not a valid date." << endl;
		}
	}
	
	
	
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
