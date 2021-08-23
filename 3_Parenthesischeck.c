#include<stdio.h> 
int top=-1;      
int i;             
char Stack[50];                         
void push(char string)
{
      Stack[top] = string;
      top++;
}
                     
void pop()
{
      if (top==-1) 
      {
            printf("Unbalaced parenthesis.Please enter an opening bracket first\n");
      }
      else
      {
            top--;
      }
}
int main() 
{
      int option;             
      char string[50];
      do{
	  printf("----------------------------------------\n");   
	  printf("\"PLEASE SELECT ANY OF THE BELOW OPTIONS\"\n");
      printf("1.Check the Parenthesis of the expression\n");
      printf("2.Exit the Program\n");
      printf("Enter your choice ---> ");
      scanf("%d",&option);
      printf("----------------------------------------\n");
      
            switch (option)
            {
                  case 1:
                        printf("\nEnter expression : ");
                        scanf("%s",string);
                        for (i = 0; string[i] != '\0';i++)
                        {
                              if (string[i] == '(' || string[i]=='[' || string[i]=='{')
                              {
                                    push(string[i]);
                              }
                              else if (string[i] == ')' || string[i]==']' || string[i]=='}')
                              {
                                    pop();
                              }
                        }
                       if(top==-1) 
					    {
               			 printf("The Expression entered has BALANCED PARENTHESIS\n");
        				}
        else
        	{
                printf("The Parenthesis in the expression are not balanced\n");
				break; 
                  case 2:
                  	printf("You have exit the program");
                  	break;
                  default:
					printf("\nWrong Entry.....Please TRY AGAIN\n");
            }
      }
      printf("\n\n");
      }while(option!=2);
      return 0;
}