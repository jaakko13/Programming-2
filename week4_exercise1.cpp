#include <iostream>
#include <algorithm>
using namespace std;

void sort(double* scores, int times);
double average(double* scores, int times);

int main() {
	int times, x;
	int i = 0;
	double add = 0;


	cout << "How many test scores would you like to use?";
	cin >> times;

	double* scores = new double[times];

	while (i < times)
	{
		cout << "Enter a score:";
		cin >> x;
		if (x < 0)
		{
			cout << "Negative numbers are not allowed!" << endl;
		}
		if (x >= 0) {
			scores[i] = x;
			i++;
		}

	}
	sort(scores, times);
	average(scores, times);


}

void sort(double* scores, int times) {
	int swap;
	int i = 0;
	while (1) {
		swap = 0;

		for (i = 0; i < times - 1; i++)
		{
			if (scores[i] > scores[i + 1]) {
				int temp = scores[i];
				scores[i] = scores[i + 1];
				scores[i + 1] = temp;
				swap = 1;
			}
		}
		if (swap == 0) {
			break;
		}

	}
	cout << "SCORES" << endl << endl;
	for (i = 0; i < times; i++)
	{
		cout << scores[i] << endl;
	}
}

double average(double* scores, int times) {
	int i = 0;
	double add = 0;
	for (i = 0; i < times; i++)
	{
		add = add + scores[i];
	}

	double avg = add / times;
	cout << endl << "Average:" << avg;
	return avg;
}