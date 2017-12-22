
/*P3.3 Program of circular linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node22
{
	int info;
	struct node22 *link;
};

struct node22 *create_list22(struct node22 *last);
void display22(struct node22 *last);
struct node22 *addtoempty22(struct node22 *last,int data);
struct node22 *addatbeg22(struct node22 *last,int data);
struct node22 *addatend22(struct node22 *last,int data);
struct node22 *addafter22(struct node22 *last,int data,int item);
struct node22 *del22(struct node22 *last,int data);

h5( )
{system("cls");
	int choice,data,item;
	struct node22	*last=NULL;
 printf("### CIRCULAR LINKED LIST ###\n");
	while(1)
	{

		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Delete\n");
		printf("8.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			last=create_list22(last);
			break;
		 case 2:
			display22(last);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addtoempty22(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatbeg22(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatend22(last,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=addafter22(last,data,item);
			break;
		 case 7:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			last=del22(last,data);
			break;
		 case 8:
		 	exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main( )*/

struct node22 *create_list22(struct node22 *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty22(last,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend22(last,data);
	}
	return last;
}/*End of create_list()*/

struct node22 *addtoempty22(struct node22 *last,int data)
{
	struct node22 *tmp;
	tmp=(struct node22 *)malloc(sizeof(struct node22));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}/*End of addtoempty( )*/

struct node22 *addatbeg22(struct node22 *last,int data)
{
	struct node22 *tmp;
	tmp=(struct node22 *)malloc(sizeof(struct node22));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}/*End of addatbeg( )*/

struct node22 *addatend22(struct node22 *last,int data)
{
	struct node22 *tmp;
	tmp=(struct node22 *)malloc(sizeof(struct node22));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}/*End of addatend( )*/

struct node22 *addafter22(struct node22 *last,int data,int item)
{
	struct node22 *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node22 *)malloc(sizeof(struct node22));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}/*End of addafter()*/

struct node22 *del22(struct node22 *last,int data)
{
	struct node22 *tmp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==data)
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==data)
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	/*Deletion in between*/
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	/*Deletion of last node*/
	if(last->info==data)
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("Element %d not found\n",data);
	return last;
}/*End of del( )*/

void display22(struct node22 *last)
{
	struct node22 *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of display( )*/

