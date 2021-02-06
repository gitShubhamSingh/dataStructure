#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

struct circularQueue{

	int front, rear;
	int size;
	int *arr;

};

circularQueue* createCircularQueue(int size)
{
	circularQueue *cq;
	cq = (circularQueue *)malloc(sizeof(cq));
	cq->front = -1;
	cq->rear = -1;
	cq->size = size;
	cq->arr = (int *)malloc(sizeof(int)*size);
	return cq;
}

int isFull(circularQueue *cq)
{
	if ((cq->front == 0 && cq->rear == cq->size - 1) || cq->rear == (cq->front - 1) % (cq->size - 1)) // to check queue is full or not
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(circularQueue *cq)
{
	if (cq->front == -1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
void printQueue(circularQueue *cq)
{
	if (cq->front == -1)
	{
		cout << "\n\nQueue is Empty";
	}
	else{
		cout << "\nQueue is: ";
		if (cq->rear >= cq->front)
		{			
			for (int i = cq->front; i <= cq->rear; i++)
			{
				cout << cq->arr[i] << "\t	";
				
			}
		}
		else
		{	
			for (int i = cq->front; i < cq->size; i++)
			{
				cout << cq->arr[i] << "\t	";
			}
			for (int i = 0; i <= cq->rear; i++)
			{
				cout << cq->arr[i] << "\t	";
			}
		}
	}
	cout << "\n\nFront = " << cq->front << " | Rear" << cq->rear << "\n";
}

void enqueue(circularQueue *cq, int data)
{
	if (!isFull(cq))
	{
		if (cq->rear == -1) // it means we are entering first value
		{
			cq->front = 0;
			cq->rear = 0;
			cq->arr[cq->rear] = data;
		}
		else if(cq->rear == cq->size -1 && cq->front !=0 ) // it is used when we have empty slots after deleting element
		{
			cq->rear = 0;
			cq->arr[cq->rear] = data;
		}
		else
		{
			cq->rear++;
			cq->arr[cq->rear] = data;
		}
	}
	else
	{
		
	}
}

void dequeue(circularQueue *cq)
{
	if (!isEmpty(cq))
	{
		if (cq->front == cq->rear)
		{
			cq->front = -1;
			cq->rear = -1;
		}
		else if (cq->front == cq->size - 1)
		{
			cq->front = 0;
		}
		else
		{
			cq->front++;
		}
	}
	else
	{
		
	}
}

int main()
{
	int size;
	cout << "\nCircular Queue with Array.\n\nEnter size of the Queue: ";
	cin >> size;
	circularQueue *cq;
	if (size == 1)
	{
		
		cq = createCircularQueue(size+1);
	}
	else if (size > 1)
	{
		
		cq = createCircularQueue(size);
	}
	else{
		cout << "\nYou are not Entered a valid Size, \nwe are exiting program, \nPress any Key for exit";
		_getch();
		exit(0);
	}
	
	while (1)
	{
		cout << "\n\nOption:-\n\n1. Enqueue\n2. Dequeue\n0. Exit\n\nchoice: ";
		cin >> size; //reUse of size variable as choose option
		switch (size)
		{
		case 1:
			if (!isFull(cq))
			{
				cout << "\nEnter Data to be insert : ";
				cin >> size; //reUse of size variable as enterData to be insert
				enqueue(cq, size);
				printQueue(cq);

			}
			else{

				cout << "\Queue is Full";
				printQueue(cq);
			}
			break;
		case 2:

			dequeue(cq);
			printQueue(cq);

			break;
		case 0:
			exit(0);
		}
	}
	_getch();
	return 0;
}
