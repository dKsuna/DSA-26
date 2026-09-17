#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node* createNode(int n);
void displayNode(struct node *p);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *p=NULL, *q, *r;
	int choice,n;
	clrscr();
	printf("\n\t\t\tLinked List Program to Create and Delete Nodes");
	p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	p=createNode(n);
	do
	{
		clrscr();
		printf("\n----Menu Driven Linked-List Program----\n");
		printf("\n1.Create a Linked List\n");
		printf("2.Deletion at the Beginning\n");
		printf("3.Deletion at the Middle\n");
		printf("4.Deletion at the End\n");
		printf("5.Display the List\n");
		printf("6.Exit\n");
		printf("\nEnter Your Choice [1-6]:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the number of nodes to be created: ");
				scanf("%d", &n);
				p=createNode(n);
				break;
			case 2:
				if(p==NULL)
				{
					printf("\nLinked-List is empty");
				}
				else
				{
					q=p;
					p=p->next;
					free(q);
					printf("\nDeleted successfully!");
				}
				break;

			case 3:
				if(p==NULL)
				{
					printf("\nLinked-List is empty");
				}
				else
				{
					r=p;
					q=NULL;
					printf("\nEnter the value to be deleted:");
					scanf("%d",&n);
					while(r!=NULL && r->data!=n)
					{
						q=r;
						r=r->next;
					}
					if(r==NULL)
					{
						printf("\nValue not found in the list\n");
					}
					else if(q==NULL)
					{
						p=p->next;
						free(r);
						printf("\nNode deleted successfully");
					}
					else
					{
						q->next=r->next;
						free(r);
						printf("\nDeleted successfully!");
					}

				}
				break;

			case 4:
				if(p==NULL)
				{
					printf("\nLinked-List is empty");
				}
				else if(p->next==NULL)
				{
					free(p);
					p=NULL;
					printf("\nDeleted successfully");
				}
				else
				{
					r=p;
					while(r->next!=NULL)
					{
						q=r;
						r=r->next;
					}
					q->next=NULL;
					free(r);
					printf("\nDeleted Successfully!");
				}
				break;
			case 5:
				displayNode(p);
				break;
		}
	       //getch();
	}while(choice!=5);
	getch();
	return 0;
}


void displayNode(struct node *p)
{
	struct node *q;
	q=p;
	printf("\n\t\tDisplaying the List\n");
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
	printf("NULL");
}


struct node* createNode(int n)
{
	int i;
	struct node *p=NULL, *q=NULL, *r=NULL;
	q=p;
	for(i=1;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter the value for Node %d:",i);
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