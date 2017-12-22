
#include<stdio.h>

#define max8 20

int stack8[max8];

int top8=-1;



void push8()

{



if(top8==19)

{

printf("\nStack is full!!\n");

}

else

{

int x;

printf("\nEnter element:");

scanf("%d",&x);

top8++;

stack8[top8]=x;

printf("\nElement pushed!!\n");

}

}

void pop8()

{

if(top8==-1)

{

printf("\nStack is empty!!Can't pop!!\n");

}

else

{

printf("\nElement popped=%d\n",stack8[top8]);

top8--;

}

}

void display8()

{

if(top8==-1)

{

printf("\nStack is empty!\n");

}

else

{

int i;

printf("\nStack is....\n");

for(i=top8;i>=0;i--)

{

printf("%d\n",stack8[i]);

}

}

}

void size8()

{

printf("\nSize of stack=%d",top8+1);

}




void peek8()

{

if(top8==-1)

printf("\nStack is empty!!");

else

printf("\nElement at top=%d",stack8[top8]);

}



int h7()

{
 system("cls");
int ch;
printf("### STACK using ARRAY ###\n");
while(1)

{

printf("\nSelect an option:\n1:Push\n2:Pop\n3:Size\n4:Peek\n5:Display\n6:Exit\nYour choice:"); scanf("%d",&ch);

switch(ch)

{

case 1:push8();

break;

case 2:pop8();

break;

case 3:size8();

break;

case 4:peek8();

break;

case 5:display8();

break;

case 6:return 0;

break;

default:printf("\nWrong choice!!\n");

break;

}

}

return 0;

}

