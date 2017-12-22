
#include<stdio.h>
#include<stdlib.h>

struct node33
{
	struct node33 *prev;
	int info;
	struct node33 *next;
};

struct node33 *create_list33(struct node33 *start);
void display33(struct node33 *start);
struct node33 *addtoempty33(struct node33 *start,int data);
struct node33 *addatbeg33(struct node33 *start,int data);
struct node33 *addatend33(struct node33 *start,int data);
struct node33 *addafter33(struct node33 *start,int data,int item);
struct node33 *addbefore33(struct node33 *start,int data,int item);
struct node33 *del33(struct node33 *start,int data);
struct node33 *reverse33(struct node33 *start);

h6()
{
    system("cls");
	int choice,data,item;
	struct node33*start=NULL;printf("### DOUBLY LINKED LIST ###\n");
	while(1)
	{

		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after\n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=create_list33(start);
			break;
		 case 2:
			display33(start);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addtoempty33(start,data);
			break;
		 case 4:
	        printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg33(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend33(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=addafter33(start,data,item);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=addbefore33(start,data,item);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del33(start,data);
	   		break;
		 case 9:
		 	start=reverse33(start);
			break;
		 case 10:
			exit(1);
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/
}/*End of main()*/

struct node33 *create_list33(struct node33 *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty33(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend33(start,data);
	}
	return start;
}/*End of create_list()*/

void display33(struct node33 *start)
{
	struct node33 *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}/*End of display() */

struct node33 *addtoempty33(struct node33*start,int data)
{
	struct node33 *tmp;
	tmp=(struct node33 *)malloc(sizeof(struct node33));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of addtoempty( )*/

struct node33 *addatbeg33(struct node33 *start,int data)
{
	struct node33 *tmp;
	tmp = (struct node33 *)malloc(sizeof(struct node33));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}/*End of addatbeg( )*/

struct node33 *addatend33(struct node33 *start,int data)
{
	struct node33 *tmp,*p;
	tmp=(struct node33 *)malloc(sizeof(struct node33));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/

struct node33 *addafter33(struct node33 *start,int data,int item)
{
	struct node33 *tmp,*p;
	tmp=(struct node33 *)malloc(sizeof(struct node33));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if(p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("%d not present in the list\n\n",item);
	return start;
}/*End of addafter()*/

struct node33 *addbefore33(struct node33 *start,int data,int item)
{
	struct node33 *tmp,*q;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info==item)
	{
		tmp = (struct node33 *)malloc(sizeof(struct node33));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return start;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp=(struct node33 *)malloc(sizeof(struct node33));
			tmp->info=data;
			tmp->prev=q->prev;
			tmp->next = q;
			q->prev->next=tmp;
			q->prev=tmp;
			return start;
		}
		q=q->next;
	}
	printf("%d not present in the list\n",item);
	return start;
}/*End of addbefore()*/

struct node33 *del33(struct node33 *start,int data)
{
	struct node33 *tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->next==NULL)	/*only one node in the list*/
		if(start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("Element %d not found\n",data);
			return start;
		}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return start;
	}
	/*Deletion in between*/
	tmp=start->next;
	while(tmp->next!=NULL )
	{
		if(tmp->info==data)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->next;
	}
	/*Deletion of last node*/
	if(tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("Element %d not found\n",data);
	return start;
}/*End of del()*/

struct node33 *reverse33(struct node33 *start)
{
	struct node33 *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	printf("List reversed\n");
	return start;
}/*End of reverse()*/

