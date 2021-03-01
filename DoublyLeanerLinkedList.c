//Program to perform doubly leaner linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int no)
{
	PNODE temp = *Head;
  	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
		newn->next = NULL;
	}
}

void DeleteFirst(PPNODE Head)
{	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Head)->prev);
		(*Head)->prev = NULL;
	}
}

void DeleteLast(PPNODE Head)
{
  PNODE temp = *Head;
 
  	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
        while(temp->next->next != NULL)
        {
           temp = temp->next;
         }
   
         free(temp->next);   
         temp->next = NULL;
	}
}

void Display(PNODE Head)
{
   while(Head != NULL)
   {
      printf("%d\t", Head->data);
      Head = Head->next;
   }	  
}

int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

void InsertAtPossitio(PPNODE Head,int no,int iPose)
{
  	PNODE temp = *Head;
	int size = 0;
	size = Count(*Head);
	
	if((iPose < 1) || (iPose > size+1))
	{
		printf("please Enter The right possition\n");
		return;
	}
	else if(iPose == 1)
	{
		InsertFirst(Head,no);
	}
	else if(iPose == size+1)
	{
		InsertLast(Head,no);
	}
	else
	{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;	
	int i = 0;
	
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

void DeleteAtPossition(PPNODE Head,int iPose)
{
	PNODE temp = NULL;
	temp = *Head;
	int i = 0;
	int size = 0;
	size = Count(*Head);
	
	if((iPose < 1)||(iPose > size))
	{
		printf("please enter the valid possition\n");
		return;
	}
	else if(iPose == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPose == size)
	{
	   DeleteLast(Head);
	}
	else
	{
	    for(i = 1;i < iPose-1;i++)
	    {
		   temp = temp->next;
	    }
	      temp->next = temp->next->next;
	      free(temp->next->prev);
	      temp->next->prev = temp;
	}
}


int main()
{
	PNODE First = NULL;
	int no = 0;
	int iRet = 0;
	int iPose = 0;
	
	printf("Enter The value(InsertFirst)\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("Enter The value(InsertFirst)\n");
	scanf("%d",&no);
	InsertFirst(&First,no);
	
	printf("\nLinked List\n");
	Display(First);
	
	printf("\nEnter The value(InsertLast)\n");
	scanf("%d",&no);
	InsertLast(&First,no);
	
	printf("Enter The value(InsertLast)\n");
	scanf("%d",&no);
	InsertLast(&First,no);
	
	printf("\nLinked List\n");
	Display(First);
	
	printf("\nDelete The First Element \n");
	DeleteFirst(&First);
	
	printf("\nLinked List\n");
	Display(First);
	
	printf("\nDelete The Last Element\n");
	DeleteLast(&First);
	
	printf("\nLinked List\n");
	Display(First);
	
	printf("\nEnter The element(InsertAtPossitio)\n");
	scanf("%d",&no);
	printf("Enter The possition where you want to insert element\n");
	scanf("%d",&iPose);
	InsertAtPossitio(&First,no,iPose);
	
	printf("\nLinked List\n");
	Display(First);
	
	printf("\nEnter The possition of element that you want to delete\n");
	scanf("%d",&iPose);
	DeleteAtPossition(&First,iPose);
	
	printf("\nLinked List\n");
	Display(First);
	
	iRet = Count(First);
	printf("\nNo of Element In Linked List:%d \t",iRet);
	return 0;
}

/*output 
Enter The value(InsertFirst)
200
Enter The value(InsertFirst)
100

Linked List
100     200
Enter The value(InsertLast)
300
Enter The value(InsertLast)
400

Linked List
100     200     300     400
Delete The First Element

Linked List
200     300     400
Delete The Last Element

Linked List
200     300
Enter The element(InsertAtPossitio)
400
Enter The possition where you want to insert element
3

Linked List
200     300     400
Enter The possition of element that you want to delete
3

Linked List
200     300
No of Element In Linked List:2

*/