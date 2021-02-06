 //Implement stack with Linked List

#include<conio.h>
#include<iostream>
using namespace std;

//definition of Node
struct node{
	node *next;
	int data;
};

node *root = NULL;

void push()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	cout << "\nInsert Data in Node : ";
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

void pop(){
	if (root == NULL)
	{
		cout << "Stack is empty\n";
	}
	else{

		node *current,*prev;
		current = root;
		prev = root;
		if (current->next == NULL)
		{
			root = NULL;
		
		}
		else
		{
			while (current->next != NULL)
			{
				prev = current;
				current = current->next;
			}
			prev->next = NULL;
		}
		cout << "\n Popped:\n ";
		free(current);
	}
}
void peek()
{
	int count=0;
	node *p;
	p = root;
	if (p == NULL){
		cout << "\nTop : -1";
	}
	else
	{
		while (p->next != NULL)
		{
			count++;
			p = p->next;
		}
		cout << "\nTop : " << count;
	}
	

}
void printStack(node *p)
{
	if (p == NULL)
	{
		cout << "\nStack is Empty";
	}
	else
	{
		while (p != NULL)
		{
			cout << "\tInfo :" << p->data << "| Next : " << p->next;
			p = p->next;
		}
	}
}

int main()
{
	int choice;
	cout << "\n\nStack with Linked List";
	while (1)
	{
		cout << "\n\n\n1.Push\n2.Pop\n0.Exit\n\nchoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			push();
			printStack(root);
			peek();
			break;
		case 2:
			pop();
			printStack(root);
			peek();
			break;
	
		case 0:
			exit(0);
		}
	}
	


	_getch();
}
