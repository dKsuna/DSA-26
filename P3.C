#include <stdio.h>
#include <stdlib.h>

struct node *createNode(int n);
void displayNodes(struct node *p);

struct node {
	  struct node *prev;
	  int data;
	  struct node *next;
};

int main()
{
	  struct node *p=NULL;
	  int n;
	  clrscr();
	  p = (struct node *)malloc(sizeof(struct node));
	  p->prev = NULL;
	  p->next = NULL;
	  printf("\n\t\t\tPROGRAM FOR DOUBLY LINKED LIST");
	  printf("\nEnter the number of nodes you want to create: ");
	  scanf("%d", &n);
	  p = createNode(n);
	  displayNodes(p);
	  getch();
	  return 0;
}

struct node *createNode(int n)
{
	  struct node *p=NULL, *q=NULL, *r=NULL;
	  int i;
	  q = p;
	  for (i = 1; i <= n; i++)
	  {
		    r = (struct node *)malloc(sizeof(struct node));
		    printf("\nEnter the data for node %d: ", i);
		    scanf("%d", &r->data);
		    r->prev = q;
		    r->next = NULL;
		    if(p==NULL)
		    {
				p=r;
				q=r;
		    }
		    else
		    {
				q->next=r;
				q=r;
		    }
	  }//end of for loop
	  return p;
}

void displayNodes(struct node *p)
{
	  struct node *q;
	  q = p;
	  printf("\nThe data in the linked list in forward direction is:\n");
	  while (q != NULL)
	  {
		    printf("%d", q->data);
		    if (q->next != NULL)
		    {
			      printf("<->");
		    }
		    q = q->next;
	  }
	  printf("\n\nThe data in the linked list in backward direction is:\n");
	  q = p;
	  while (q->next != NULL)
	  {
		    q = q->next;
	  }
	  while (q != NULL)
	  {
		    printf("%d", q->data);
		    if (q->prev != NULL)
		    {
			  printf("<->");
		    }
		    q = q->prev;
	  }
	  printf("\n");
}
