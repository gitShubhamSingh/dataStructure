#include<iostream>
using namespace std;
struct Node{
	Node *prev;
	int data;
	Node *next;
};
Node *START = NULL;
void addNode(int data)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	if (START == NULL)
	{
		START = temp;
	}
	else
	{
		Node *p;
		p = START;
		while (p->next != NULL)
		{
			p = p->next;
		}
		temp->prev = p;
		p->next = temp;
	}
}
void deleteLastNode()
{
	Node *prev, *cur;
	prev = START;
	cur = START;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == START)
	{
		START = NULL;
	}
	else
	{
		prev->next = NULL;
	}
	free(cur);
}
void print()
{
	Node *p;
	p = START;
	if (START == NULL)
	{
		cout << "\n\t\tList is Empty.";
	}

	else
	{
		while (p != NULL)
		{
			cout << " P:" << p->prev << " D:" << p->data << "(" << p << ")" << " N:" << p->next << "| ";
				p = p->next;
		}
	}
}
int main()
{
	int temp;
	cout << "\n\tDoubleLinkedListThroughStack.";
	while (1)
	{
		cout << "\n\n\t1.InsertionTopNode\t2.DeleteTopNode\t3.Show\t4.Exit\n\t>>";
		cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "\nEnter Data Which You Want to ADD : ";
			cin >> temp;
			addNode(temp);
			print();
			break;
		case 2:
			deleteLastNode();
			print();
			break;
		case 3:
			print();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "\nInvalidSELECTION";
			break;
		}
	}
	return 0;
}