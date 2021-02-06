#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *root = NULL;
void show()
{
	node *p;
	p = root;
	if (root == NULL)
	{
		cout << "\nSimple Linked List through Queue is EMPTY ";
	}
	else
	{
		while (p != NULL)
		{
			cout << "\tInfo: " << p->data << "|Next: " << p->next;
			p = p->next;
		}
	}
}
void insertNodeFromRear()
{
	int data;
	node *temp;
	temp = (node *)malloc(sizeof(node));
	cout << "Insert Data in Node : ";
	cin >> temp->data;
	temp->next = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		node *p;
		p = root;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}
void deleteFromFront()
{
	if (root == NULL)
	{
		cout << "\nList is Empty\n";
	}
	else
	{
		node *temp;
		temp = root;
		root = root->next;
		free(temp);
	}
}
int main()
{
	int choice;
	while (1)
	{
		cout << "\n\n\t\t\tSimple Linked List Implementation Through QUEUE\n\t\t-----------------------------------------------------------------\n";
		cout << "\n1.InsertFromRear\t2.DeleteFromFront\t3.Show\t4.Exit\n\nSELECT :- ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			insertNodeFromRear();
			show();
			break;
		case 2:
			deleteFromFront();
			show();
			break;
		case 3:
			show();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!---------INVALID SELECTION SELECT VALID OPTION------ - !!!!!!!!!!!!!!!!\n";
		}
	}
	return 0;
}