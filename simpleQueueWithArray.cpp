// Implement simpleQueue with array
#include<conio.h>
#include<iostream>
using namespace std;

//definition of stack
struct stack{
	int front,rear;
	int size;
	int *array;
};

//creating stack
stack *createStack(int size){
	stack *st;
	st = (stack *)malloc(sizeof(size));
	st->front = -1;
	st->rear = -1;
	st->size = size;
	st->array = (int *)malloc(sizeof(int)*size);
	return st;
}

//check is Empty or Not
int isEmpty(stack *st)
{
	if (st->front == st->rear)
	{
		return 1;
	}
	else{
		return 0;
	}
}

//position


//print stack
void printStack(stack *st)
{
	for (int i = st->front; i <= st->rear; i++)
	{
		cout << st->array[i] << "\t";
	}
	int front1, rear1;
	front1 = st->front;
	rear1 = st->rear;
	cout << "\nFront : " << front1 << "| Rear : " << rear1;
}

//check stack is full or not
int isFull(stack *st)
{
	if ((st->rear + 1) == st->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Pushing into stack
void enque(stack *st,int data)
{
	if (!isFull(st))
	{
		if ((st->front == -1) && (st->rear == -1)){
			st->front++;
			st->rear++;
			st->array[st->rear] = data;
		}
		else
		{
			st->rear++;
			st->array[st->rear] = data;

		}
		printStack(st);
	}
	else
	{
		cout << "\nQueue is Full.";
	}
		
}

//Pop element from stack
void dequeue(stack *st)
{
	if (!isEmpty(st))
	{
		st->front++;
		printStack(st);
	}
	else
	{
		cout << "\nQueue is Empty.";
	}
}

//position of top


int main()
{
	int sizeOfStack,choice;
	cout << "\nSimpleQueue with array.\n\nPlease Enter the Size ofthe Queue: ";
	cin >> sizeOfStack;
	stack *stack;
	stack = createStack(sizeOfStack);
	while (1)
	{
		cout << "\n\nOption:-\n\n1. Enqueue\n2. Dequeue\n0. Exit\n\nchoice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				if (!isFull(stack))
				{
					cout << "\nEnter Data to be insert : ";
					cin >> choice;
					enque(stack, choice);
				
				}
				else{
					cout << "\Queue is Full";
				}
				break;
			case 2:
				dequeue(stack);
				
				break;
			case 0:
				exit(0);
		}
	}
	_getch();
	}