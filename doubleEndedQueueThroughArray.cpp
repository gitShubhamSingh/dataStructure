//Double Ended Queue through array

#include<iostream>
#include<conio.h>
using namespace std;
struct deQueue{
	int front, rear;
	int *arr;
	int size;
};

deQueue *createDEQueue(int size)
{
	deQueue *dq;
	dq = (deQueue *)malloc(sizeof(dq));
	dq->front = -1;
	dq->rear = -1;
	dq->size = size;
	dq->arr = (int *)malloc(sizeof(int)*size);
	return dq;
		
}
////check Queue is full or not form rear
int isFull(deQueue *dq)
{
	if ((dq->rear + 1) == dq->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// check Queue is full or not form front
int isFull2(deQueue *dq)
{
	if ((dq->front + 1) == dq->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//creating Enqueue Front
void enqueRear(deQueue *dq, int data)
{
	if ((dq->front == -1) && (dq->rear == -1)){
		dq->front++;
		dq->rear++;
		dq->arr[dq->rear] = data;
	}
	else
	{
		dq->rear++;
		dq->arr[dq->rear] = data;

	}
}

void enqueFront(deQueue *dq, int data)
{
	if ((dq->front == -1) && (dq->rear == -1)){
		dq->front++;
		dq->rear++;
		dq->arr[dq->front] = data;
	}
	else
	{
		dq->front++;
		dq->arr[dq->front] = data;

	}
}
///check is Empty or Not
int isEmpty(deQueue *st)
{
	if (st->front == st->rear)
	{
		return 1;
	}
	else{
		return 0;
	}
}
//Printing the stack
void printQueueInsertFromRear(deQueue *st)
{
	for (int i = st->front; i <= st->rear; i++)
	{
		cout << st->arr[i] << "\t";
	}
	int front1, rear1;
	front1 = st->front;
	rear1 = st->rear;
	cout << "\nFront : " << front1 << "| Rear : " << rear1;
}

//Printing the stack
void printQueueInsertFromFront(deQueue *st)
{
	for (int i = st->rear; i <= st->front; i++)
	{
		cout << st->arr[i] << "\t";
	}
	int front1, rear1;
	front1 = st->front;
	rear1 = st->rear;
	cout << "\nFront : " << front1 << "| Rear : " << rear1;
}
///Pop element from stack
void dequeFront(deQueue *dq)
{
	if (!isEmpty(dq))
	{
		dq->front++;
		printQueueInsertFromRear(dq);
	}
	else
	{
		cout << "\nQueue is Empty.";
	}
}
//Dequeue from Rear
void dequeRear(deQueue *dq)
{
	if (!isEmpty(dq))
	{
		if (dq->rear > dq->front)
		{
			dq->rear--;
		}
		else{

			dq->rear++;
		}
		printQueueInsertFromFront(dq);
	}
	else
	{
		cout << "\nQueue is Empty.";
	}
}

int main()
{
	int sizeOfQueue,choice;
	cout << "\Double Ended queue with array.\n\nPlease Enter the Size ofthe Queue: ";
	cin >> sizeOfQueue;
	deQueue *dq;
	
	dq = createDEQueue(sizeOfQueue);
	while (1)
	{
		cout << "\n\nOption:-\n\n1.Enqueue(Rear)\n2. Dequeue(Front)\n3. Enqueue(Front)\n4. Dequeue(Rear) \n0. Exit\n\nchoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (!isFull(dq))
			{
				cout << "\nEnter Data to be insert : ";
				cin >> choice;
				enqueRear(dq, choice);
				printQueueInsertFromRear(dq);
			}
			else{
				cout << "\Queue is Full";
			}
			break;
		case 2:
			dequeFront(dq);
			break;

		case 3:
			if (!isFull2(dq))
			{
				cout << "\nEnter Data to be insert : ";
				cin >> choice;
				enqueFront(dq, choice);
				printQueueInsertFromFront(dq);
			}
			else{
				cout << "\Queue is Full";
			}
			break;
		case 4:
			dequeRear(dq);
			break;
		case 0:
			exit(0);
		}
	}
	_getch();
	return 0;
}