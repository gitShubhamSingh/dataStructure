 //Implement stack with array
#include<conio.h>
#include<iostream>
using namespace std;

//definition of stack
struct stack{
	int top;
	int size;
	int *array;
};

//creating stack
stack *createStack(int size){
	stack *st;
	st = (stack *)malloc(sizeof(size));
	st->top = -1;
	st->size = size;
	st->array = (int *)malloc(sizeof(int)*size);
	return st;
}

//check is Empty or Not
int isEmpty(stack *st)
{
	if (st->top == -1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
//print stack
void printStack(stack *st,int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << st->array[i] << "\t";
	}
}

//check stack is full or not
int isFull(stack *st)
{
	if ((st->size - 1) == st->top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Pushing into stack
void push(stack *st,int data)
{
	if (!isFull(st))
	{
		st->top++;
		st->array[st->top] = data;
		printStack(st, st->top);
	}
	else
	{
		cout << "\nStack is Full.";
	}
		
}

//Pop element from stack
void pop(stack *st)
{
	if (!isEmpty(st))
	{
		st->top--;
		printStack(st, st->top);
	}
	else
	{
		cout << "\nStack is Empty.";
	}

}

//position of top
int top(stack *st)
{
	return st->top;
}

int main()
{
	int sizeOfStack,choice;
	cout << "\n\nStack with Array:\n\nPlease Enter the Size ofthe stack: ";
	cin >> sizeOfStack;
	stack *stack;
	stack = createStack(sizeOfStack);
	while (1)
	{
		cout << "\n\nOption:-\n1.Push\n2. Pop\n3. Peek\n0. Exit\nchoice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				if (!isFull(stack))
				{
					cout << "\nEnter Data to be insert : ";
					cin >> choice;
					push(stack, choice);
				}
				else{
					cout << "\nStack is Full";
				}
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				cout<<"top position  : "<<top(stack);
				break;
			case 0:
				exit(0);
		}
	}
	_getch();
}