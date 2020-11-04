#include <iostream>
#include "car.h"
using namespace std;

int main() {
	int i;

	car porsche(2006, "Porsche");

	cout << "Current speed: " << porsche.getSpeed() << endl;

	for (i = 0; i < 5; i++)
	{
		porsche.accelerate();
		cout << "Current Speed: " << porsche.getSpeed() << endl;
	}

	for (i = 0; i < 5; i++)
	{
		porsche.brake();
		cout << "Current Speed: " << porsche.getSpeed() << endl;
	}
	return 0;
}