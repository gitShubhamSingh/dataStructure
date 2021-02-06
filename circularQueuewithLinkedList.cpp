/* Implement Simple Queue with Linked List*/

#include<conio.h>
#include<iostream>
using namespace std;

//definition of Node
struct node{
	node *next;
	int data;
};

node *root = NULL;

//Enqueue data in the circular linked list
void enqueue()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	cout << "\nInsert Data in Node : ";
	cin >> temp->data;
	if (root == NULL)//if no node is present
	{
		temp->next = temp;
		root = temp;
	}
	else//if node is present
	{
		node *p;
		p = root;
		while (p->next != root)//treverse through last node
		{
			p = p->next;
		}
		p->next = temp;//applying circular insertion
		temp->next = root;
	}
}

//Dequeue data from circular linked list
void dequeue(){
	if (root == NULL)//if no node is present
	{
		cout << "Queue is empty\n";
	}
	else{//if node is present

		node *current,*prev;
		current = root;
		prev = root;
		if (current->next == root)//if one node is present
		{
			root = NULL;
		
		}
		else//if more then one node is present
		{
			do
			{
				prev = current;
				current = current->next;
			} while (current->next != root);
		}
		prev->next = root;//applying circular aproach
		free(current);//deleting the node from memory
	}
}

//printing queue
void printQueue(node *p)
{
	if (p == NULL)
	{
		cout << "\nQueue is Empty";
	}
	else
	{
		if (p->next == root)
		{
			cout <<"\tcur: "<<p<< "|Info :" << p->data << "| Next : " << p->next;
		}
		else
		{
			do
			{
				cout << "\tcur: " << p << "|Info :" << p->data << "| Next : " << p->next;
				p = p->next;
			} while (p->next != root);
			cout << "\tcur: " << p << "|Info :" << p->data << "| Next : " << p->next;
		}
		
	}
}

int main()
{
	int choice;
	cout << "\n\nCircular Queue with Linked List";
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
