
#include<stdio.h>

#define max 10
int stack7[max];
int top7=-1;
int top1=max;
void push7()

{

int ch;

while(1)

{

printf("\nSelect stack:\n1:Stack 1\n2:Stack 2\nYour choice:"); scanf("%d",&ch);

if(ch==1 || ch==2)

break;
printf("\nWrong choice!!\n");

}
if(top7==top1-1)

{
printf("\nStack is full!!\n");
}
else

{

int x;

printf("\nEnter element:");
scanf("%d",&x);
if(ch==1)

{

top7++;
stack7[top7]=x;

}

else

{top1--; stack7[top1]=x;}

printf("\nElement pushed!!\n");

}

}

void pop7()

{

int ch;

while(1)

{

printf("\nSelect stack:\n1:Stack 1\n2:Stack 2\nYour choice:");

scanf("%d",&ch);

if(ch==1 || ch==2)

break;

printf("\nWrong choice!!\n");

}
if(ch==1)

{

if(top7==-1)

{

printf("\nStack1 is empty!!Can't pop!!\n");

}

else

{

printf("\nElement popped=%d\n",stack7[top7]);

top7--;

}

}

else

{

if(top1==max)

{

printf("\nStack2 is empty!!Can't pop!!\n");

}

else

{

printf("\nElement popped=%d\n",stack7[top1]);

top1++;

}

}

}

void display7()

{

if(top7==-1)

{printf("\nStack1 is empty!\n");

}

else

{

int i;

printf("\nStack1 is....\n");

for(i=top7;i>=0;i--)

{

printf("%d\n",stack7[i]);

}

}

if(top1==max)

{

printf("\nStack2 is empty!!\n");

}

else

{   int j;

printf("Stack2 is.....\n");

for(j=top1;j<max;j++)

{

printf("%d\n",stack7[j]);

}

}

}

int h8()

{
system("cls");
int ch;
printf("### TWO STACK in One ARRAY ###\n");
while(1)

{

printf("\nSelect an option:\n1:Push\n2:Pop\n3:Display\n4:Exit\nYour choice:");

scanf("%d",&ch);

switch(ch)

{

case 1:push7();

break;

case 2:pop7();

break;

case 3:display7();

break;

case 4:return 0;

break;

default:printf("\nWrong choice!!\n");

break;

}

} return 0;

}
