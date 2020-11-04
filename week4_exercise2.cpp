#include <iostream>
using namespace std;
double median(double* movie, int people);
double average(double* movie, int people);
double mode(double* movie, int people);

int main() {
	int people, x, swap;
	int i = 0;


	cout << "How many students were surveyed?";
	cin >> people;

	double* movie = new double[people];

	while (i < people)
	{
		cout << "Enter the number of movies viewed:";
		cin >> x;
		if (x < 0)
		{
			cout << "Negative numbers are not allowed!" << endl;
		}
		if (x >= 0) {
			movie[i] = x;
			i++;
		}

	}

	while (1) {
		swap = 0;

		for (i = 0; i < people - 1; i++)
		{
			if (movie[i] > movie[i + 1]) {
				int temp = movie[i];
				movie[i] = movie[i + 1];
				movie[i + 1] = temp;
				swap = 1;
			}
		}
		if (swap == 0) {
			break;
		}

	}
	average(movie, people);
	median(movie, people);
	mode(movie, people);
}

double average(double *movie, int people) {
	int i = 0;
	double add = 0;

	for (i = 0; i < people; i++)
	{
		add = add + movie[i];
	}
	double avg = add / people;
	cout << "Average:" << avg << endl;
	return avg;
}

double median(double* movie, int people) {
	double med;
	if (people % 2 == 0)
	{
		int mid1 = people / 2, mid2 = (people / 2) - 1;
		med = ((*(movie + mid1) + *(movie + mid2)) / 2);
	}
	else
	{
		med = *(movie + (people / 2));
	}
	cout << "Median:" << med << endl;
	return med;
}

double mode(double* movie, int people) {
	int* frequency = nullptr;
	int mode = -1; 
	int highest = 0; 
	int value = 0; 
	int counter = 0; 
	int x = people;
	
	frequency = new int[people];
	for (counter = 0; counter < people; counter++)
		frequency[counter] = 0;
	for (int counter1 = 0; counter1 < people; counter1++)
	{
		
		for (int counter2 = 0; counter2 < people; counter2++)
		{
			if (*(movie + counter2) == *(movie + counter1))
				(*(frequency + counter1))++;
		}
	}
	
	highest = *frequency;
	value = 0;
	
	for (counter = 1; counter < people; counter++)
	{
		if (*(frequency + counter) > highest)
		{
			highest = *(frequency + counter);
			value = counter;
		}
	}
	frequency = nullptr;
	if (highest > 1)
	{
		mode = *(movie + value);
	}
	cout << "Mode:" << mode << endl;
	return mode;
	

}