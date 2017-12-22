#include<stdio.h>

#define MAX1 10

int queue_arr[MAX1];

int r=-1;

int f=-1;

void insert1(int item);

//int del1();

int peek1();

void display1();

int Full();

int Empty();

void h18()

{
system("cls");
int choice,item;
printf("### Queue using Array ###\n");
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

insert1(item);

break;

case 2:

item=del1();

printf("Deleted element is %d\n",item);

break;

case 3:

printf("Element at the front is %d\n",peek1());

break;

case 4:

display1();

break;
case 5:
    main();
default:
    {printf("\n Enter correct choice\n");
    getche();
    system("cls");}
}
}
}
void insert1(int item)
{
if( Full() )
{
printf("Queue Overflow\n");
return;
}
if( f == -1 )
f=0;
r=r+1;
queue_arr[r]=item ;
}
int del1()
{
int item;
if( Empty() )
{
printf("Queue Underflow\n");
exit(1);
}
item=queue_arr[f];
f=f+1;
return item;
}
int peek1()
{
if( Empty() )
{
printf("Queue Underflow\n");
exit(1);
}
return queue_arr[f];
}
int Empty()
{
if( f==-1 || f==r+1 )
return 1;
else
return 0;
}
int Full()
{
if( r==MAX1-1 )
return 1;
else
return 0;
}
void display1()
{
int i;
if ( Empty() )
{
printf("Queue is empty\n");
return;
}
printf("Queue is :\n\n");
for(i=f;i<=r;i++)
    printf("%d ",queue_arr[i]);
printf("\n\n");

}
