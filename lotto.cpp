#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


//Create struct with data integer and the previous and next pointers.
struct node {
	int data;
	struct node* next;
	struct node* prev;
};


//function to add nodes to the beginning.
void insertFirst(node** head, int value)
{
	node* last = (*head)->prev;
	node* new_node = new node;

	new_node->data = value;    
	new_node->next = *head;
	new_node->prev = last;
	last->next = (*head)->prev = new_node;

	*head = new_node;
}

//Function to add nodes after a certain place. Need to pass in head, value you want to enter and after what number you want to add it.
void insertAfter(node** head, int value1, int value2)
{
	node* new_node = new node;
	new_node->data = value1;  

	node* temp = *head;
	while (temp->data != value2)
		temp = temp->next;
	node* next = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = next;
	next->prev = new_node;
}

//Function to add a node to the end
void insertLast(node** head, int value)
{
	if (*head == NULL)
	{
		node* new_node = new node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*head = new_node;
		return;
	}

	node* end = (*head)->prev;
	node* new_node = new node;
	new_node->data = value;
	new_node->next = *head;
	(*head)->prev = new_node;
	new_node->prev = end;
	end->next = new_node;
}

//Function used to delete nodes. Used when a number is picked and so that node is then deleted so it cant be picked again.
void deleteNode(node** head, int key)
{
	if (*head == NULL)
		return;

	node* curr = *head, * prev_1 = NULL;
	while (curr->data != key) {
		if (curr->next == *head) {
			cout << "List doesnt have value " << key;
			return;
		}
		prev_1 = curr;
		curr = curr->next;
	}

	if (curr->next == *head && prev_1 == NULL) {
		(*head) = NULL;
		free(curr);
		return;
	}

	if (curr == *head) {
		prev_1 = (*head)->prev;

		*head = (*head)->next;

		prev_1->next = *head;
		(*head)->prev = prev_1;
		free(curr);
	}

	else if (curr->next == *head) {
		prev_1->next = *head;
		(*head)->prev = prev_1;
		free(curr);
	}
	else {
		node* temp = curr->next;
		prev_1->next = temp;
		temp->prev = prev_1;
		free(curr);
	}
}

int main() {
	//make rand() actually random
	srand(time(NULL));

	//initialize head and end nodes. 
	struct node* head = NULL;
	struct node* end = NULL;

	//Insert the begining and end nodes
	insertLast(&head, 40);
	insertFirst(&head, 1);

	//Containes all of the inbetween nodes from 1-40
	insertAfter(&head, 2, 1);
	insertAfter(&head, 3, 2);
	insertAfter(&head, 4, 3);
	insertAfter(&head, 5, 4);
	insertAfter(&head, 6, 5);
	insertAfter(&head, 7, 6);
	insertAfter(&head, 8, 7);
	insertAfter(&head, 9, 8);
	insertAfter(&head, 10, 9);
	insertAfter(&head, 11, 10);
	insertAfter(&head, 12, 11);
	insertAfter(&head, 13, 12);
	insertAfter(&head, 14, 13);
	insertAfter(&head, 15, 14);
	insertAfter(&head, 16, 15);
	insertAfter(&head, 17, 16);
	insertAfter(&head, 18, 17);
	insertAfter(&head, 19, 18);
	insertAfter(&head, 20, 19);
	insertAfter(&head, 21, 20);
	insertAfter(&head, 22, 21);
	insertAfter(&head, 23, 22);
	insertAfter(&head, 24, 23);
	insertAfter(&head, 25, 24);
	insertAfter(&head, 26, 25);
	insertAfter(&head, 27, 26);
	insertAfter(&head, 28, 27);
	insertAfter(&head, 29, 28);
	insertAfter(&head, 30, 29);
	insertAfter(&head, 31, 30);
	insertAfter(&head, 32, 31);
	insertAfter(&head, 33, 32);
	insertAfter(&head, 34, 33);
	insertAfter(&head, 35, 34);
	insertAfter(&head, 36, 35);
	insertAfter(&head, 37, 36);
	insertAfter(&head, 38, 37);
	insertAfter(&head, 39, 38);

	//welcomes the player and initializes the users variables
	cout << "Hello and welcome to the lottery game. You will be asked to enter 6 different numbers between 1 and 40. Good luck!" << endl;
	int first, second, third, fourth, fifth, sixth;
	int y = 0;
	
	//While loop used to make sure entered numbers are between 1-40 and also that the numbers are not repeated
	//If an invalid number is put in it restarts and asks for all the numbers again
	while (y < 1)
	{
		cout << "Enter your first number:";
		cin >> first;

		if (first > 40 || first < 1)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}
		

		cout << "Enter your second number:";
		cin >> second;

		if (second > 40 || second < 1 || second == first)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}
		

		cout << "Enter your third number:";
		cin >> third;

		if (third > 40 || third < 1 || third == second || third == first)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}

		cout << "Enter your fourth number:";
		cin >> fourth;

		if (fourth > 40 || fourth < 1 || fourth == third || fourth == second || fourth == first)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}

		cout << "Enter your fifth number:";
		cin >> fifth;

		if (fifth > 40 || fifth < 1 || fifth == fourth || fifth == third || fifth == second || fifth == first)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}

		cout << "Enter your sixth number:";
		cin >> sixth;

		if (sixth > 40 || sixth < 1 || sixth == fifth || sixth == fourth || sixth == third || sixth == second || sixth == first)
		{
			cout << "That is not a valid number. Try again." << endl;
			continue;
		}
		y = 2;
	}


	//initialize lotto vector where transversed numbers are put in so they can be checked later to see how many the user got right
	//display the users numbers and the lotto numbers.
	vector<int> lotto;
	cout << "Your numbers are: " << first << " " << second << " " << third << " " << fourth << " " << fifth << " " << sixth << endl;
	cout << "The lotto numbers are: ";



	int i = 0;
	int x = 0;

	//random number generated to decide if the nodes should be transversed forwards or backwards
	int decide = rand() % 100 + 1;
	if (decide % 2 == 0)
	{
		for (i = 0; i < 6; i++)
		{

			int random = rand() % 40 + 1;
			//head selected so it starts at begining. 
			node* temp = head;



			while (x < random)
			{
				//transverses forward by going to next each time. 
				temp = temp->next;
				x++;
			}

			//displayes the selected node, pushback into the vecotr and then deletes the node so it cant be selected again
			cout << temp->data << " ";
			lotto.push_back(temp->data);
			deleteNode(&head, temp->data);
		}
	}
	else
	{
		for (i = 0; i < 6; i++)
		{

			int random = rand() % 40 + 1;
			//goes to previous from head to start at the end
			node* temp = head->prev;



			while (x < random)
			{
				//goes to the previous one each time to go backwards through the nodes
				temp = temp->prev;
				x++;
			}

			//displayes the selected node, pushback into the vecotr and then deletes the node so it cant be selected again
			cout << temp->data << " ";
			lotto.push_back(temp->data);
			deleteNode(&head, temp->data);
	}
	
	}


	cout << endl;

	//counter initialized and then bunch of if statements which check if all the user variables first through sixth are 
	//in the lotto vector. If they are 1 is added to the counter
	int counter = 0;
	
	if (find(lotto.begin(), lotto.end(), first) != lotto.end())
	{
		counter++;
	}
	if (find(lotto.begin(), lotto.end(), second) != lotto.end())
	{
		counter++;
	}
	if (find(lotto.begin(), lotto.end(), third) != lotto.end())
	{
		counter++;
	}
	if (find(lotto.begin(), lotto.end(), fourth) != lotto.end())
	{
		counter++;
	}
	if (find(lotto.begin(), lotto.end(), fifth) != lotto.end())
	{
		counter++;
	}
	if (find(lotto.begin(), lotto.end(), sixth) != lotto.end())
	{
		counter++;
	}
	

	
	//Using the counter to see how many the user got correct. Once again a bunch of if statements which print out
	//certain phrase depending on how many the user got right. 

	if (counter == 0)
	{
		cout << "You matched 0 numbers. Better luck next time!";
	}
	else if (counter == 1)
	{
		cout << "You matched 1 number. You get your money back.";
	}
	else if (counter == 2)
	{
		cout << "You matched 2 numbers. You won 15 dollars.";
	}
	else if (counter == 3)
	{
		cout << "You matched 3 numbers. You won 250 dollars.";
	}
	else if (counter == 4)
	{
		cout << "You matched 4 numbers. You won 20,000 dollars.";
	}
	else if (counter == 5)
	{
		cout << "You matched 5 numbers. You missed the jackpot by one. You won 100,000 dollars.";
	}
	else if (counter == 6)
	{
		cout << "Congratulations! You matched all 6 numbers. You won 100 million dollars!";
	}


	return 0;
}


