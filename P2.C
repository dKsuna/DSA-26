#include<stdio.h>
#include<stdlib.h>

struct node* createNodes(struct node *p, int n);
struct node* insertAtBegin(struct node *p);
struct node* insertAtMid(struct node *p);
struct node* insertAtEnd(struct node *p);
void displayNodes(struct node *p);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *p=NULL;
	int n, choice;
	clrscr();
	//.p=(struct node*)malloc(sizeof(struct node));
	//printf("\nEnter the data for first node:");
	//scanf("%d",&p->data);
	//p->next=NULL;
	do
	{
		clrscr();
		printf("\nMenu Driven Linked-List Program\n");
		printf("1.Create a Linked List\n");
		printf("2.Insertion at the Beginning\n");
		printf("3.Insertion at the Middle\n");
		printf("4.Insertion at the End\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("\nEnter Your Choice [1-6]:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the number of nodes to be created: ");
				scanf("%d", &n);
				p=createNodes(p,n);
				break;
			case 2:
				printf("\n----Insertion at the Beginning----\n");
				p=insertAtBegin(p);
				break;

			 case 3:
				printf("\n----Insertion at the Middle----\n");
				p=insertAtMid(p);
				break;

			 case 4:
				printf("\n----Insertion at the End----\n");
				p=insertAtEnd(p);
				break;
			 case 5:
				displayNodes(p);
				break;
		}
		//getch();
	}while(choice!=6);
	getch();
	return 0;
}

struct node* createNodes(struct node *p, int n)
{
	struct node *q, *r;
	int i;
	q = p;
	for (i = 1; i <= n; i++)
	{
		    r = (struct node *)malloc(sizeof(struct node));
		    printf("\nEnter the data for node %d: ", i);
		    scanf("%d", &r->data);
		    r->next = NULL;
		    q->next = r;
		    q = r;
	}
	return p;
}

void displayNodes(struct node *p)
{
	struct node *q;
	q=p;
	printf("\t\t\n----Displaying the List----\n");
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
	printf("NULL");
	getch();
}

struct node* insertAtBegin(struct node *p)
{
	struct node *r;
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=p;
	p=r;
	return p;
}


struct node* insertAtMid(struct node *p)
{
	struct node *q,*r;
	int n;
	q=p;
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of the node to insert after:");
	scanf("%d",&n);
	while(q->data!=n)
	{
		q=q->next;
	}
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=q->next;
	q->next=r;
	return p;
}


struct node* insertAtEnd(struct node *p)
{
	struct node *q,*r;
	int n;
	q=p;
	r=(struct node*)malloc(sizeof(struct node));
	while(q->next!=NULL)
	{
		q=q->next;
	}
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=NULL;
	q->next=r;
	return p;
}