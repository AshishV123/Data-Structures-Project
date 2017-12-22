
#include<stdio.h>

#include<stdlib.h>

struct node11

{

int info;

struct node11 *link;

}*front11=NULL,*rear11=NULL;

void insert11(int item);

int del11();

int peek11();

int isEmpty11();

void display11();

void h2()

{
system("cls");
int choice,item;
printf("## ARRAY ##\n");
while(1)

{

printf("1.Insert\n");

printf("2.Delete\n");

printf("3.Display the element at the front\n");

printf("4.Display all elements of the queue\n");
printf("5. Exit\n");

printf("Enter your choice : ");

scanf("%d", &choice);

switch(choice)

{

case 1:

printf("Input the element for adding in queue : ");

scanf("%d",&item);

insert11(item);

break;

case 2:

printf("Deleted element is %d\n",del11());

break;

case 3:

printf("Element at the front of the queue is %d\n", peek11() ); break;

case 4:

display11();

break;

case 5:

main();

default :

printf("Wrong choice\n");

}

}

}

void insert11(int item)

{

struct node11 *tmp;

tmp=(struct node11 *)malloc(sizeof(struct node11));

if(tmp==NULL)

{

printf("Memory not available\n");

return;

}

tmp->info = item;

tmp->link=NULL;

if(front11==NULL)

front11=tmp;

else

rear11->link=tmp;

rear11=tmp;

}

int del11()

{

struct node11 *tmp;

int item;

if( isEmpty11( ) )

{

printf("Queue Underflow\n");

}

tmp=front11;

item=tmp->info;

front11=front11->link;

free(tmp);

return item;

}

int peek11()

{

if( isEmpty11( ) )

{

printf("Queue Underflow\n");

exit(1);

}

return front11->info;

}

int isEmpty11()

{

if(front11==NULL)

return 1;

else

return 0;

}

void display11()

{

struct node11 *ptr;

ptr=front11;

if(isEmpty11())

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

