#include<stdio.h>
#include<stdlib.h>

struct nod
{
	int info;
	struct nod *link;
}*front1=NULL,*rear1=NULL;

void insert2(int item);
int del2();
int peek2();
int isEmpty2();
void display2();

h20()
{
    system("cls");
	int choice,item;
	printf("###  Queue using Single Linked List ###\n");
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert2(item);
			break;
		case 2:
			printf("Deleted element is  %d\n",del2());
			break;
		case 3:
			printf("Element at the front of the queue is %d\n", peek2() );
			break;
		case 4:
			display2();
			break;
		case 5:
			main();
		default :
			printf("Wrong choice\n");
		}
	}
}

void insert2(int item)
{
	struct nod *tmp;
	tmp=(struct nod *)malloc(sizeof(struct nod));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info = item;
	tmp->link=NULL;
	if(front1==NULL)
		front1=tmp;
	else
		rear1->link=tmp;
	rear1=tmp;
}

int del2()
{
	struct nod *tmp;
	int item;
	if( isEmpty2( ) )
	{
		printf("Queue Underflow\n");

	}
	tmp=front1;
	item=tmp->info;
	front1=front1->link;
	free(tmp);
	return item;
}

int peek2()
{
	if( isEmpty2( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front1->info;
}

int isEmpty2()
{
	if(front1==NULL)
		return 1;
	else
		return 0;

}

void display2()
{
	struct nod* ptr;
	ptr=front1;
	if(isEmpty2())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n\n");
}


