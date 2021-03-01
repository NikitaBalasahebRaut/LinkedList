//program to demonstrate the concept of Doubly circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node** PPNODE;

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		newn->prev = *Tail;
		
		*Tail = newn;
		
		(*Tail)->next = *Head;
		(*Head)->prev = *Tail;
	}
		
}
void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
       newn->next = *Head;
	   (*Head)->prev = newn;
	   
	   *Head = (*Head)->prev;
	}
	   (*Head)->prev = *Tail;
	   (*Tail)->next = *Head;
}

void Display(PNODE Head,PNODE Tail)
{
	if((Head == NULL)&&(Tail == NULL))
	{
		return;
	}
	else
	{
	do
	{
		printf("%d\t", Head->data);
		Head = Head->next;
	}while(Head != Tail->next);
	
		printf("\n");
    }
}

int Count(PNODE Head,PNODE Tail)
{
	int iCnt = 0;
	if((Head == NULL)&&(Tail == NULL))
	{
		return 0;
	}
	else
	{
	do
	{
		iCnt++;
		Head = Head->next;
	}while(Head != Tail->next);
	
	printf("\n");
	}
	return iCnt;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	 if((*Head == NULL)&&(*Tail == NULL))
	 {
		 return;
	 }
	 else if(*Head == *Tail)
	 {
		 free(*Head);
		 *Head = NULL;
		 *Tail = NULL;
	 }
	 else
	 {
		 *Head = (*Head)->next;
		 free((*Head)->prev);  //free(*Tail->next)
		 
		 (*Head)->prev = *Tail;
		 (*Tail)->next = *Head;
	 }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	 if((*Head == NULL)&&(*Tail == NULL))
	 {
		 return;
	 }
	 else if(*Head == *Tail)
	 {
		 free(*Head);
		 *Head = NULL;
		 *Tail = NULL;
	 }
	 else
	 {
		 *Tail = (*Tail)->prev;
		 free((*Tail)->next);   //free(*Head->prev)
		 
		 
		 (*Head)->prev = *Tail;
		 (*Tail)->next = *Head;
	 }
}

void InserAtPossition(PPNODE Head,PPNODE Tail,int no,int iPose)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	int size = 0;
	size = Count(*Head,*Tail);
	
	if((iPose < 1) ||(iPose > size+1))
	{
		printf("Enter The valid possition\n");
		return;
	}
    else if(iPose == 1)
	{
		InsertFirst(Head,Tail,no);
	}
	else if(iPose == size+1)
	{
		InsertLast(Head,Tail,no);
	}
	else
	{
       int i = 0;
	   PNODE temp = *Head;
	   for(i = 1;i < iPose-1;i++)
	   {
		   temp = temp->next;
	   }
	   newn->next = temp->next;
	   temp->next->prev = newn;
	   
	   temp->next = newn;
	   newn->prev = temp;
	}
}

void DeleteAtPossition(PPNODE Head,PPNODE Tail,int iPose)
{
	int size = 0;
	size = Count(*Head,*Tail);
	
	if((iPose < 1) ||(iPose > size))
	{
		printf("Enter The valid possition\n");
		return;
	}
    else if(iPose == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPose == size)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
       int i = 0;
	   PNODE temp = *Head;
	   for(i = 1;i < iPose-1;i++)
	   {
		   temp = temp->next;
	   }
	   temp = temp->next->next;
	   free(temp->next->prev);
	   
	  temp->next->prev = temp;
	}
}
int main()
{
 int no = 0;
 PNODE First = NULL;
 PNODE Last = NULL;
 int iRet = 0;
 int iPose = 0;
 printf("Enter The Element(InsertLast) \n");
 scanf("%d",&no);
 InsertLast(&First,&Last,no);
 
 printf("Enter The Element(InsertLast) \n");
 scanf("%d",&no);
 InsertLast(&First,&Last,no);
 
  printf("Enter The Element(InsertFirst) \n");
  scanf("%d",&no);
  InsertFirst(&First,&Last,no);
 
  printf("Enter The Element(InsertFirst) \n");
  scanf("%d",&no);
  InsertFirst(&First,&Last,no);
  
  printf("Linked List\n");
  Display(First,Last);
 
  iRet = Count(First,Last);
  printf("No of elements are :  %d",iRet);
  
  DeleteFirst(&First,&Last);
  printf("\nAfter Delete First element Linked List\n");
  Display(First,Last);
  
  DeleteLast(&First,&Last);
  printf("\nAfter Delete Last Element Linked List\n");
  Display(First,Last);
 
  printf("Enter The Element(InserAtPossition) \n");
  scanf("%d",&no);
  printf("Insert The possition\n");
  scanf("%d",&iPose);
  InserAtPossition(&First,&Last,no,iPose);
  printf("Linked List\n");
  Display(First,Last);
return 0;
}

/*output 
Enter The Element(InsertLast)
1000
Enter The Element(InsertLast)
2000
Enter The Element(InsertFirst)
300
Enter The Element(InsertFirst)
400
Linked List
400     300     1000    2000

No of elements are :  4
After Delete First element Linked List
300     1000    2000

After Delete Last Element Linked List
300     1000
Enter The Element(InserAtPossition)
800
Insert The possition
2

Linked List
300     800     1000

*/