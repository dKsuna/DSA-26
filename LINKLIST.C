#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node* createNode(int n);
struct node* insertBegin(struct node *p);
struct node* deleteBegin(struct node *p);
void displayNodes(struct node *p);

struct node* createNode(int n)
{
	int i;
	struct node *p=NULL, *q=NULL, *r=NULL;
	for(i=1;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data for node %d: ",i);
		scanf("%d", &r->data);
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

struct node* insertBegin(struct node *p)
{
	struct node *r;
	r=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for the new node: ");
	scanf("%d", &r->data);
	r->next=p;
	p=r;
	return p;
}

struct node* deleteBegin(struct node *p)
{
	struct node *q;
	if(p==NULL)
	{
		printf("\nNo nodes found");
	}
	else
	{
		q=p;
		p=p->next;
		free(q);
		printf("\nNode deleted successfully");
		printf("\nThe Linked List will now be:\n ");
		displayNodes(p);
	}
	return p;
}

void displayNodes(struct node *p)
{
	struct node *q;
	if(p==NULL)
	{
		printf("\nEmpty List");
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
	}//end of else
}


int main()
{
	int n, choice;
	struct node *p=NULL;
	do
	{
		clrscr();

		printf("\t\t\tLINKED LIST CREATION AND DISPLAYING\n");
		printf("\n1. Create a Linked List\n2. Insert a node into the list\n3. Delete a node from the list");
		printf("\n4. Display the Linked List\n5. Exit");
		printf("\n\nEnter your choice [1-5]: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the number of nodes: ");
				scanf("%d", &n);
				if(n>0)
				{
					p=createNode(n);
				}
				else
				{
					printf("\nInvalid number of nodes.");
				}
				break;
			case 2:
				p=insertBegin(p);
				break;
			case 3:
				printf("\The first node will be deleted\n");
				getch();
				p=deleteBegin(p);
				getch();
				break;
			case 4:
				printf("\nThe created Linked List is:\n");
				displayNodes(p);
				getch();
				break;
			case 5:
				printf("\nYou have chosen to exit.\nGoodbye.");
				break;
			default:
				printf("\nInvaild Choice");
				break;

		}//switch
	}while(choice!=5);//end of do-while

	getch();
	return 0;
}