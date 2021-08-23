#include<stdio.h>
#define size 5
int stack[size];
int top=-1;
void push();
void pop();
void view();
int main()
{	
	int ch;
	
	do{
	printf("1. Push an element in the Stack\n");
	printf("2. Pop an element from the Stack\n");
	printf("3. View the Stack\n");
	printf("4. Exit the Program\n");
	printf("\nPlease enter your choice\n");
	scanf("%d",&ch);
		switch(ch)
		{	
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: view();
			break;
			case 4:
			default:printf("You have exit the program");
		}
		printf("\n\n");
	}while(ch!=4);
}	
	void push()
		{
		int element;
		if(top==size-1)
		{
		    printf("Stack is full");
		}
		else
			{
		   printf("Enter the element that you to insert in stack\n");
			scanf("%d",&element);
			top=top+1;
			stack[top]=element;		
			}
		}
		
	void pop()
	{
		if(top==-1)
		{
			printf("Stack is empty");
		}
		else
			{
			printf("Poped element is %d",stack[top]);
			top=top-1;
			}
	}
	
	void view()
	{
		int i;
		if(top>=0)
			{
			printf("Elements in the stack are : ");
				for(i=top;i>=0;i--)
				{
					printf("\n%d",stack[i]);
				}
			}
			else
			{
				printf("Stack is totally empty");
			}
	}