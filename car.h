#include <iostream>
#ifndef CAR_H_INCLUDED
#define CAR_H_iNCLUDED
using namespace std;

class car {
	private:
		int yearModel;
		string make;
		int speed;
	public:
		car(int y, string m) {
			yearModel = y;
			make = m;
			speed = 0;
		};
		void accelerate() {
			speed += 5;
		};
		void brake() {
			speed -= 5;
		};
		int getYearModel() {
			return yearModel;
		}
		string getMake() {
			return make;
		}
		int getSpeed() {
			return speed;
		}
};

#endif