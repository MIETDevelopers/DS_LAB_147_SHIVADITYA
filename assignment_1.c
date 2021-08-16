#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct info
{
int item0;
char name[30];
int price;
struct info *next;
};
struct info *temp,*disp,*head; 

int catSearch;

void addrecord();
void display();
void displaymin();
void displaymax();
void deleterecord();
void displaySpecMin();
void displaySpecMax();

int main()
{
  int ch, ch1;
  while (1) 
    {
      printf("\n~Dry Fruit tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
      
      scanf("%d",&ch);   
      
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  addrecord();
                      break;

              case 2:
                  deleterecord();
                    break;
              
              case 3:
                  printf("\n 1. Display whole list.");
                  printf("\n 2. Display minimum priced item.");
                  printf("\n 3. Display maximum priced item.");
                  printf("\n 4. Display minimum price of Walnuts.");
                  printf("\n 5. Display maximum price of Walnuts.");
                  printf("\n 6. Display minimum price of Almonds.");
                  printf("\n 7. Display maximum price of Almonds.");
                  printf("\n 8. Display minimum price of Cashew.");
                  printf("\n 9. Display maximum price of Cashew.");
                  printf("\n10. Display minimum price of Peanut.");
                  printf("\n11. Display maximum price of Peanut.");
                  printf("\n Enter desired display option: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      display();
                        break;

                    case 2:
                      displaymin();
                        break;

                    case 3:
                      displaymax();
                        break;

                    case 4: 
                      catSearch = 1;
                      displaySpecMin(catSearch);
                      break;

                    case 5:
                      catSearch = 1;
                      displaySpecMax(catSearch);
                      break;

                    case 6: 
                      catSearch = 2;
                      displaySpecMin(catSearch);
                      break;

                    case 7:
                      catSearch = 2;
                      displaySpecMax(catSearch);
                      break;

                    case 8: 
                      catSearch = 3;
                      displaySpecMin(catSearch);
                      break;

                    case 9:
                      catSearch = 3;
                      displaySpecMax(catSearch);
                      break;

                    case 10: 
                      catSearch = 4;
                      displaySpecMin(catSearch);
                      break;

                    case 11:
                      catSearch = 4;
                      displaySpecMax(catSearch);
                      break;

                    default:
                      printf("\n Invalid choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");
                    break;
            }

    }
return 0;
}

void addrecord()
{
  struct info *add;
  
  add=(struct info*)malloc(sizeof(struct info));

  printf("\n Enter the name of dealer: ");
  gets(add->name);
  printf("\n Enter the price of item: ");
  scanf("%d",&add->price);

  printf("\nWhich item's record you want to store?\n Available categories:");
  printf("\n1. Walnut\n2. Almond\n3. Cashew\n4. Peanut\n Enter your choice: ");
  scanf("%d", &add->item0);
  
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }

        add->next=temp->next;
        temp->next=add;
      }

  return;
 }

void display()
{
  int count=0, category;
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\n -- \nSerial number: %d", count);
      printf("\nName of dealer: %s",disp->name);
      category=disp->item0;
      switch(category)
      {
        case 1: printf("\nCategory of item: Walnut"); 
                break;

        case 2: printf("\nCategory of item: Almond");
                break;

        case 3: printf("\nCategory of item: Cashew");
                break;

        case 4: printf("\nCategory of item: Peanut");
                break; 
      } 
      printf("\nPrice of item: %d \n",disp->price);
      count++;
    }
  count=0;
return;
}

void deleterecord()
{
    display();

    int i,pos;
    struct info *temp,*ptr;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }

    else
    {
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=head;
                head=head->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
            else
            {
                ptr=head;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
    }
}

void displaymin()
{
  int category;
  if(head==NULL)
    {
      printf("\n No records to view!\n");
      return;
    }


  for(disp=head;disp!=NULL;disp=disp->next)
    {
      if(disp=head)
      {
        printf("\nName of dealer: %s",disp->name);
        category=disp->item0;
        switch(category)
        {
          case 1: printf("\nCategory of item: Walnut"); 
                  break;

          case 2: printf("\nCategory of item: Almond");
                  break;

          case 3: printf("\nCategory of item: Cashew");
                  break;

          case 4: printf("\nCategory of item: Peanut");
                  break;
        }
        printf("\nPrice of item: %d \n",disp->price); 
        return; 
      }
    }
return;  
}

void displaymax()
{
  int count1=0, count2=0,category;
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count1++;
  }

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count2++;
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    category=disp->item0;
    switch(category)
    {
      case 1: printf("\nCategory of item: Walnut"); 
              break;

      case 2: printf("\nCategory of item: Almond");
              break;

      case 3: printf("\nCategory of item: Cashew");
              break;

      case 4: printf("\nCategory of item: Peanut");
              break;
    }
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
  }
    count1=0;
    count2=0;
}

void displaySpecMin()
{
  int count3=0;
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(catSearch==disp->item0) 
    {
      count3++;
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of item: %d \n",disp->price);
      return; 
    }
  }
    if(count3==0) 
    {
      printf("\n No records to view!\n");
      return;
    }
}

void displaySpecMax()
{
  int count1=0, count2=0,category;
  
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->item0==catSearch)
    {
      count1++;
    }
    
  }

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->item0==catSearch)
    {
      count2++;
    }
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
     
  }
      if(count1==0)
      {
        printf("\n No records to view!\n");
        return;
      }
    count1=0;
    count2=0; 
}
