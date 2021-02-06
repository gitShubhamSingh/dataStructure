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

// Delete the Node
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
			
				prev = current;
				while (current != NULL)// through this we will find largest node
				{
					if (current->data > smalllNode)
					{
						smalllNode = current->data;
						smallNodeAddress = current;
					}

					current = current->rear;
					//cout << "\ncurrent: " << current;

				}
				cout << "\nLarge: " << smalllNode << "\tLargeNodeAddress: " << smallNodeAddress << "\n\n";

				current = root;
				//cout << "\nCurrentRootwala:" << current;
				prev = root;
				//cout << "\nPreviousRootwala:" << prev;
				
				if (current == smallNodeAddress)//when first node is largest
				{
					root = current->rear;
				}
				else
				{
					while (current->rear != smallNodeAddress && current->rear != NULL)
					{
						current = current->rear;
					}
					if (current->rear == NULL)
					{

						root = current;
					}
					else{
						current->rear = current->rear->rear;

					}
				}
				//cout << "\nCurrent: " << current;
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
	cout << "\nPriority Queue with Normal Insertion Priority Deletion with Linked List in Descending\n\ndescending = Highest Number Value will Delete First\n";
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
