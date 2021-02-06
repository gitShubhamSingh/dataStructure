///* This is the priority Queue with Normal insertion and priority deletion with Linked List
//
//	generally this approach not followed, because of overhead of front pointer because array will
//	
//	not be sorted 
//	
//	Ascending Priority Queue = lowest value will delete first */


#include<conio.h>
#include<iostream>
using namespace std;

//definition of Node
struct node{
	node *rear;
	int data;
};

node *root = NULL;

//Insert a new Node
void enqueue()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	cout << "\nInsert Data in Node : ";
	cin >> temp->data;
	
	temp->rear = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		node *p;
		p = root;
		while (p->rear != NULL)
		{
			p = p->rear;
		}
		p->rear = temp;
	}
}


void dequeue()
{
	int smalllNode,count=1;
	if (root == NULL)
	{
		cout << "Queue is empty\n";
	}
	else{
		
		node *current,*prev,*p;
		current = root;
		//prev = root;
		p = root;
		smalllNode = current->data;
		if (current->rear == NULL)
		{
			root = NULL;
		
		}
		else
		{
			node *current, *smallNodeAddress = root;
			current = root;
			//prev = root;
			if (current->rear == NULL)//if only one element is present
			{
				root = NULL;

			}
			else
			{
				prev = current;
				while (current != NULL)// through this we will find small node
				{
					if (current->data < smalllNode)
					{
						smalllNode = current->data;
						smallNodeAddress = current;
					}

					current = current->rear;
					//cout << "\ncurrent: " << current;

				}
				//cout << "\nSmall: " << smalllNode << "\tSmallNodeAddress: " << smallNodeAddress << "\n\n";

				current = root;
				//cout << "\nCurrentRootwala:" << current;
				prev = root;
				//cout << "\nPreviousRootwala:" << prev;
				while (current->rear != smallNodeAddress && current->rear != NULL)
				{
					current = current->rear;
				}
				//cout << "\nprevious: " << current;
				if (current->rear == NULL)
				{

					root = current;
				}
				else{
					current->rear = current->rear->rear;

				}
			}
		}
	}
}

void printQueue(node *p)
{
	if (p == NULL)
	{
		cout << "\nQueue is Empty";
	}
	else
	{
		while (p != NULL)
		{
			cout << "\tInfo :" << p->data << "| Next : " << p->rear;
			p = p->rear;
		}
	}
}

int main()
{
	int choice;
	cout << "\nPriority Queue with Normal Insertion Priority Deletion with Linked List in Ascending\n\nAscending = Lowest Number Value will Delete First\n";
	while (1)
	{
		cout << "\n\n\n1.Enque\n2.Dequeue\n0.Exit\n\nchoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			enqueue();
			printQueue(root);
			break;
		case 2:
			dequeue();
			printQueue(root);
			break;
		case 0:
			exit(0);
		}
	}
	


	_getch();
}
