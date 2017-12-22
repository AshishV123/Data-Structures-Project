
#include<stdio.h>

#include<stdlib.h>

typedef struct node6{

int info;

struct node6 *next;

}node6;
node6 *top6,*t;
node6 *create(int x)

{

node6 *y=malloc(sizeof(node6));

y->info=x;
y->next=NULL;

return y;
}
void push6()

{

int x;

printf("\nEnter element:");
scanf("%d",&x);
t=create(x);

t->next=top6;

top6=t;
printf("\nElement pushed!!\n");
}
void pop6()

{
if(top6==NULL)
{
printf("\nStack is empty!!Can't pop!!\n");
}

else

{

t=top6;

printf("\nElement popped=%d\n",t->info);
top6=top6->next;

free(t);

}

}

void display6()

{

if(top6==NULL)

{

printf("\nStack is empty!\n");

}else

{
t=top6;
printf("\nStack is....\n");

while(t!=NULL)

{

printf("%d\n",t->info);

t=t->next;

}

}

}void peek6()

{

if(top6==NULL)

{

printf("\nStack is empty!\n");

}

else

printf("\nElement at top=%d",top6->info);

}void size()

{

int i=0;
t=top6;
while(t!=NULL)
{

i++;

t=t->next;}

printf("\nSize=%d",i);

}int h9()

{
system("cls");
int ch;
printf("### STACK using Linked List ###\n");
while(1)

{

printf("\nSelect an option:\n1:Push\n2:Pop\n3:Size\n4:Peek\n5:Display\n6:Exit\nYour choice:"); scanf("%d",&ch);

switch(ch)

{
case 1:push6();

break;
case 2:pop6();

break;
case 3:size();

break;
case 4:peek6();

break;
case 5:display6();

break;
case 6:
    main();
    return 0;

break;
default:printf("\nWrong choice!!\n");

break;

}
}

return 0;
}
