#include<stdio.h>
#define size 6
int queue[size];
int front=-1,rear=-1;
void Enqueue();
void Dequeue();
void Display();
int main()
{
	int c;
	do
	{	printf("---------------------------------------\n");
		printf("\"SELECT ANY OF THE BELOW OPTIONS\"\n");
		printf("\n1.Insert an Element in the Queue");
		printf("\n2.Remove an Element from the Queue");
		printf("\n3.View the Queue");
		printf("\n4.Exit the Program");
		printf("\nEnter your choice :---> ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Display();
				break;
			default:
				printf("\nYou have exit the program");
		}
		printf("\n\n");
	}while(c!=4);	
}
void Enqueue()
{
	int item;
	if(rear==size-1)
	{
		printf("Queue Overflow");
	}
	else if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		printf("\nEnter an element :---> ");
		scanf("%d",&item);
		queue[rear]=item;
	}
	else
	{
		rear++;
		printf("\nEnter Another element :---> ");
		scanf("%d",&item);	
		queue[rear]=item;
	}
}
void Dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("\nQueue Underflow");
	}
	else if(front>rear)   
	{
		printf("\nQueue is Empty");
	}
	else
	printf("%d has been removed from the Queue",queue[front]);
	front++;
}
void Display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is Empty");
	}
	else if(front>rear)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("The elements in the Queue are : ");
		for(i=front;i<+rear+1;i++)
		{
			printf("%d ",queue[i]); 
		}
	}
	
}