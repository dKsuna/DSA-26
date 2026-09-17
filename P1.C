#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node* createNode(int n)
{
       int i;
       struct node *p=NULL, *r=NULL, *q=NULL;
       q=p;
       for(i=1; i<=n; i++)
       {
		r=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data for node %d: ",i);
		scanf("%d",&r->data);
		r->next=NULL;
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
       }
       return p;

}

void displayNode(struct node *p)
{
	struct node *q;
	clrscr();
	printf("\t\t\t\tDISPLAYING THE NODES\n\n");
	if(p==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		q=p;
		while(q!=NULL)
		{
			printf("%d -> ", q->data);
			q=q->next;
		}
		printf("NULL");
	}
       //	return;
}

void main()
{
	int i,n;
	struct node *p;
	clrscr();
	printf("\t\t\tLINKED LISTS PROGRAM");
	printf("\nEnter the number of nodes to be created: ");
	scanf("%d", &n);
	p=createNode(n);
	displayNode(p);
	getch();
	//return 0;
}