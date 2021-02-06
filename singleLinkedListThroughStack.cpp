#include<iostream>
using namespace std;
struct node
{
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
		cout << "\nLinked List is Empty.";
	}
	else
	{
		while (p != NULL)
		{
			cout << "\tInfo:" << p->data << " Next:" << p->next << " |";
			p = p->next;
		}
	}
}
void insertNodeInLast()
{
	int data;
	node *temp;
	temp = (node *)malloc(sizeof(node));
	cout << "\nInsert Data in Node: ";
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
void deleteLastNode()
{
	node *cur, *prev; if (root == NULL)
	{
		cout << "\n Linked List is Empty";
	}
	else
	{
		cur = root;
		prev = root;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur == root)
		{
			root = NULL;
		}
		else
		{
			prev->next = NULL;
		}
		free(cur);
	}
}
int main()
{
	int temp;
	node *root;
	cout << "\nSimple Linked List Impletation Through Stack";
	while (1)
	{

		cout << "\n------------------------------------\n1.InsertionTopNode\t2.DeletionTopLastNode\t3.Exit\n---------------------------------- -\noption: ";
			cin >> temp;
		switch (temp)
		{
		case 1:
			insertNodeInLast();
			show();
			break;
		case 2:
			deleteLastNode();
			show();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "\nInvalid Selection.";
		}
	}
	return 0;
}