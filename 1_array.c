#include<stdio.h>
int arr[50];
int i,size,s,pos,ele,found;
void insert(int *arr1);
void deletement(int *arr2);
void search(int *arr3);
int main()
{
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	printf("Enter the elements : ");
	for(i=0;i<size;i++)
	{
	   scanf("%d",&arr[i]);
	}
	printf("1. Insert \n");
	printf("2. Delete \n");
	printf("3. Search \n");
	printf("4. End \n");
	while(1)
	{
		int choice;
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	insert(arr);
				    break;
			case 2: deletement(arr);
				    break;
			case 3: search(arr);	
				    break;
			case 4: end(0);
		    default:
			{
				printf("Invalid choice");
			}
			
		}
	}
}
void insert(int arr1[])
{
	printf("Enter the position : ");
	scanf("%d",&pos);
	printf("Enter the element to be insert : ");
	scanf("%d",&ele);
	for(i=size;i>=pos;i--)
	{
	   arr[i]=arr[i-1];
	}
	arr[pos]=ele;
	size++;
	printf("\nResult : ");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
    printf("\n");
}
 void deletement(int arr2[])
{
	printf("Enter the position of element you want to delete : ");
	scanf("%d",&pos);
	size--;
	for(i=pos;i<=size;i++)
	{
		arr[i-1]=arr[i];
	}
	printf("\nResult : ");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void  search(int arr3[])
{
	printf("\nEnter the element you want to search : ");
	scanf("%d",&s);
	for(i=0;i<6;i++)
	{
		if(arr[i]==s)
	  {
		found=1;
		break;		
	  }
	}
	if(found==1)
	{
		printf("\n%d is found at %d position in the array\n",s,i+1);
	}
	else
	printf("\n%d is not found in the array \n",s);	
	
}