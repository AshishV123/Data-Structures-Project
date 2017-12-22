#include<stdio.h>

#define MAX4 10

int queue_arr[MAX4];

int rear4=-1;

int front4=-1;

void insert4(int item);

int del4();

int peek4();

void display4();

int isFull4();

int isEmpty4();

void h22()
{
system("cls");
int choice,item;
printf("###  Deque using array ###\n");
while(1)

{

printf("1.Insert\n");

printf("2.Delete\n");

printf("3.Display element at the front\n");

printf("4.Display all elements of the queue\n");

printf("5.Quit\n");

printf("Enter your choice : ");

scanf("%d",&choice);

switch(choice)

{

case 1:

printf("Input the element for adding in queue : ");

scanf("%d",&item);

insert4(item);

break;

case 2:

item=del4();

printf("Deleted element is %d\n",item);

break;

case 3:

printf("Element at the front is %d\n",peek4());

break;

case 4:

display4();

break;
case 5:
    main();
}

}

}

void insert4(int item)

{

if( isFull4())
{

printf("Queue Overflow\n");

return;

}

if( front4 == -1 )

front4=0;

rear4=rear4+1;

queue_arr[rear4]=item ;

}

int del4()

{

int item;

if( isEmpty4() )

{

printf("Queue Underflow\n");

exit(1);

}

item=queue_arr[front4];

front4=front4+1;

return item;

}

int peek4()

{

if( isEmpty4() )

{

printf("Queue Underflow\n");

exit(1);

}

return queue_arr[front4];

}

int isEmpty4()

{

if( front4==-1 || front4==rear4+1 )

return 1;

else

return 0;

}

int isFull4()

{

if( rear4==MAX4-1 )

return 1;

else

return 0;

}

void display4()

{

int i;

if ( isEmpty4() )

{

printf("Queue is empty\n");

return;

}

printf("Queue is :\n\n");

for(i=front4;i<=rear4;i++)

printf("%d ",queue_arr[i]);

printf("\n\n");

}

