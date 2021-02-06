/* This is the priority Queue with Normal insertion and priority deletion with stack

generally this approach not followed, because of overhead of front pointer because array will

not be sorted

Descending Priority Queue = Highest value will delete first */


#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct Queue{

	int front, rear;
	int size;
	int *array;
};

//creating stack
Queue *createStack(int size){
	Queue *st;
	st = (Queue *)malloc(sizeof(size));
	st->front = -1;
	st->rear = -1;
	st->size = size;
	st->array = (int *)malloc(sizeof(int)*size);
	return st;
}

//print stack
void printStack(Queue *st)
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


//check Queue is full or not
int isFull(Queue *st)
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

//check is Empty or Not
int isEmpty(Queue *st)
{
	if (st->front == st->rear)
	{
		return 0;
	}
	else{
		return 0;
	}
}

//Pushing into Queue
void enque(Queue *st, int data)
{
	if (!isFull(st))
	{
		if ((st->front == -1) && (st->rear == -1)) // When First element will insert
		{
			st->front++;
			st->rear++;
			st->array[st->rear] = data;
		}
		else //when after first element Insert
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

//delete element from Queue
void dequeue(Queue *st)
{
	int pos = 0, max = st->array[0];
	if (!isEmpty(st))
	{
		if (st->front == -1 || st->rear == -1)
		{
			cout << "\nPriority Queue is empty\n";
		}
		else
		{
			for (int i = st->front; i <= st->rear; i++) // to find the smallest Number in the array
			{
				if (st->array[i] > max)
				{
					pos = i;
					max = st->array[pos];
				}
			}
			cout << "\n Index: " << pos << " | Value: " << st->array[pos] << " is Deleted\n\n";
			for (int i = pos; i <= st->rear; i++)// copy rest of the data after deletion.
			{
				st->array[i] = st->array[i + 1];
			}
			st->rear--;
		}

		for (int i = 0; i <= st->rear; i++) // Printing the queue
		{
			cout << st->array[i] << "\t";
		}
	}
	else
	{
		cout << "\nQueue is Empty.";
	}
}

int main()
{
	cout << "\nPriority Queue with Normal Insertion and Priority deletion with Stack in Descending.\n\nDescending = Highest number Value will delete First";
	int sizeOfQueue, choice;
	cout << "\n\nPlease Enter the Size ofthe Queue: ";
	cin >> sizeOfQueue;
	Queue *queue;
	queue = createStack(sizeOfQueue);
	while (1)
	{
		cout << "\n\nOption:-\n\n1. Enqueue\n2. Dequeue\n0. Exit\n\nchoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (!isFull(queue))
			{
				cout << "\nEnter Data to be insert : ";
				cin >> choice;
				enque(queue, choice);

			}
			else{
				cout << "\Queue is Full";
			}
			break;
		case 2:
			dequeue(queue);

			break;
		case 0:
			exit(0);
		}
	}
	_getch();
	return 0;
}