#include <iostream>
using namespace std;

class circle {
private:
	double radius;
	double pi = 3.14159;
public:
	circle() {
		radius = 0;
	}
	circle(double r) {
		radius = r;
	}
	void setRadius(double r) {
		radius = r;
	}
	double getRadius() {
		return radius;
	}
	double getArea() {
		return pi * radius * radius;
	}
	double getDiameter() {
		return radius * 2;
	}
	double getCircumference() {
		return 2 * pi * radius;
	}


};

int main() {
	double rad;
	cout << "What would you like the radius to be?";
	cin >> rad;

	circle user(rad);
	cout << "The area of the circle is " << user.getArea() << endl;
	cout << "The diameter of the circle is " << user.getDiameter() << endl;
	cout << "The circumference of the circle is " << user.getCircumference() << endl;


}

