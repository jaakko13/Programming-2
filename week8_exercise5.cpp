#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Time
{
public:
	int hour;
	int min;
	int sec;

	Time(int h, int m, int s){
		hour = h;
		min = m;
		sec = s;}

	Time(){
		hour = 0;
		min = 0;
		sec = 0;}

	void setHour(int h){
		hour = h; 
	}
	void setMin(int m){ 
		min = m; 
	}
	void setSec(int s){
		sec = s; 
	}

	int getHour(){
		return hour; 
	}
	int getMin(){
		return min; 
	}
	int getSec(){
		return sec; 
	}

	Time operator=(Time after) {
		hour = after.hour;
		min = after.min;
		sec = after.sec;
		return *this;
	}

};
class MilTime : public Time
{

private:
	int milHrs; 
	int milSec;
public:
	MilTime(int h, int s) {
		milHrs = h;
		milSec = s;
		convert();
	}

	MilTime() : Time() {
		milHrs = 0;
		milSec = 0;
	}

	void convert() { 
		char m;

		int tempMin, tempHour;
		int tempSec = milSec;

		if (milHrs > 1200) {
			
			m = 'p';
		}
		else {
			m = 'a';
		}

		tempMin = milHrs % 60;
		tempHour = milHrs / 1000;

		setHour(tempHour);
		setMin(tempMin);
		setSec(tempSec);
	}

	void setTime(int h, int s) {
		milHrs = h;
		milSec = s;
		convert(); 
	}

	int getHour(){
		return milHrs;
	}
	int getMilSec(){
		return milSec;
	}
	int getStandHr(){
		return hour;
	}
};

class TimeClock : public MilTime {
private:
	MilTime first;
	MilTime second;
public:
	TimeClock(int firsth, int firstsec, int secondh, int secondsec) :
		MilTime(0, 0)
	{
		first.setTime(firsth, firstsec);
		second.setTime(secondh, secondsec);


		this->OtherDiff(); 

	}

	TimeClock() : MilTime(0, 0) {
		first.setTime(0, 0);
		second.setTime(0, 0);
	}

	void Difference() { 

		int difSec = first.getSec();
		int changeHour = first.getHour();
		int changeMin = first.getMin() / 100;

		changeMin = first.getHour() - (changeMin * 100);
		
		if (second.MilTime::getSec() > first.MilTime::getSec()) { 
			difSec = 60 + first.MilTime::getSec() - second.MilTime::getSec();

			changeMin -= 1; 

			if (changeMin > 59) { 
				changeMin -= 40;
			}

			if (changeMin < 0) {
				changeMin += 60;
				changeHour = first.getHour() - 100;
			}
			changeHour += changeMin;
		}
		
		int difHour = changeHour - second.getHour();

		difHour = changeHour * 100 + changeMin;

		this->setTime(difHour, difSec); 

	}
	

	void OtherDiff() {

		Time first = Convert(this->first);
		Time second = Convert(this->second);

		int dsec = second.getSec() - first.getSec();


		if (dsec < 0)
		{
			first.setMin(first.getMin() + 1);
			dsec += 60;
		}

		if (first.getMin() < 0)
		{
			first.setHour(first.getHour() - 1);
			first.setMin(first.getMin() + 60);
		}


		int dmin = second.getMin() - first.getMin();


		if (dmin < 0)
		{
			first.setHour(first.getHour() + 1);
			dmin += 60;
		}



		int dhour = second.getHour() - first.getHour();


		this->setTime((dhour * 100) + dmin, dsec);

		this->setHour(dhour);
		this->setMin(dmin);
		this->setSec(dsec);
	}

	Time Convert(MilTime time) 
	{
		int mHour = time.getHour(); 
		int tempMin, tempHour; 
		int tempSec = time.getMilSec();

		tempHour = mHour / 100;

		tempMin = mHour - (tempHour * 100);

		Time temp(tempHour, tempMin, tempSec);

		return temp;
	}

	void PrintDifference() {
		cout << endl;
		cout << "Time passed: " << endl;
		cout << this->Time::getHour() << " hours." << endl << this->getMin() << " minutes." << endl << this->getSec() << " seconds.";
	}
};

int main() {

	int hour[2] = { 0, 0 };
	int sec[2] = { 0, 0 };


	for (int i = 0; i < 2; i++) {
		string word;

		switch (i) {
		case 0:
			word = "st";
			break;
		case 1:
			word = "nd";
			break;
		default:
			break;
		}

		do {
			cout << endl << "Enter " << i + 1 << word << " hour:";
			cin >> hour[i];
		} while (hour[i] < 0 || hour[i] > 2400);

		do {
			cout << endl << "Enter " << i + 1 << word << " second:";
			cin >> sec[i];
		} while (sec[i] < 0 || sec[i] > 59);
	}

	TimeClock a(hour[0], sec[0], hour[1], sec[1]);

	a.PrintDifference();
}