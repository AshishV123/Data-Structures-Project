#include<stdio.h>

#include<ctype.h>
#define SIZE 50
int s[SIZE];

int top=-1;
int push(int elem)

{

s[++top]=elem;

}
int pop()
{return(s[top--]);}
int h11()
{
system("cls");
char pofx[50],ch;
printf("### Valid Postfix Expression using Stack ###\n");
int i=0,op1,op2;
printf("\n\nRead the Postfix Expression ? ");
scanf("%s",pofx);
while( (ch=pofx[i++]) != '\0')

{

if(isdigit(ch)) push(ch-'0');

else

{
op2=pop();
op1=pop();
switch(ch)

{

case '+':push(op1+op2);break;
case '-':push(op1-op2);break;
case '*':push(op1*op2);break;
case '/':push(op1/op2);break;

}

}} printf("\n Result after Evaluation: %d\n",s[top]);

}

