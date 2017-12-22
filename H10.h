#include<stdio.h>

#include<stdlib.h>

#include<string.h>

char stack[20];

char postfix[20];

int top_stack = -1;

int top_postfix = -1;

int priority = 0;

char validity[20];

int top_validity = -1;

void push_stack(char item)

{

top_stack++;

stack[top_stack] = item;

}

void push_postfix(char item)

{

top_postfix++;

postfix[top_postfix] = item;

}

char pop_postfix()

{

char item = postfix[top_postfix];

top_postfix--;

return item;

}

char pop_stack()

{

char item = stack[top_stack];

top_stack--;

if(top_stack == -1)

{

priority = 0;

return item;

}

switch(stack[top_stack])

{

case '(':

priority = 1;break;

case '+':

priority = 2;break;

case '-':

priority = 2;break;

case '*':

priority = 3;break;

case '/':

priority = 3;break;

}

return item;

}

void transform(char p[], int loop)

{

int c = 0, t=strlen(p), o,i;

while(c!=strlen(p) && t!=0)

{

if(loop == 0)

i=c;

else

i=t-1;

if(p[i]=='+'|| p[i] == '-')

o = 1;

else if(p[i]=='*'|| p[i] == '/')

o = 2;

else if(p[i]=='(' || p[i] ==')')

o = 3;

else

o = 4;

switch(o)

{

case 1:

if(loop==0)

{

while(priority>=2)

push_postfix(pop_stack());

}

if(loop==strlen(p))

{

while(priority>2)

push_postfix(pop_stack());

}

push_stack(p[i]);

priority = 2;

break;

case 2:

if(loop==0){

while(priority>=3)

push_postfix(pop_stack());}

if(loop==strlen(p)){

while(priority>3)

push_postfix(pop_stack());}

push_stack(p[i]);

priority = 3;

break;

case 3:

if((p[i]==')' && loop ==0)|| (p[i]=='('&& loop==strlen(p)))

{

while(stack[top_stack]!= '(' && stack[top_stack]!= ')')

push_postfix(pop_stack());

pop_stack();

break;

}

push_stack(p[i]);

priority = 1;

break;

case 4:

push_postfix(p[i]);

break;

}

c++;t--;

}

while(top_stack!=-1)

push_postfix(pop_stack());

}

void push_validity(char item)

{

top_validity++;

validity[top_validity] = item;

}

char pop_validity()

{

char item = validity[top_validity];

top_validity--;

return item;

}

int exp_checking(char p[])

{

int i;

for(i=0;i<strlen(p);i++)

{

if(p[i]=='(' || p[i]=='[' || p[i]=='{')

push_validity(p[i]);

else if((p[i]==')' && validity[top_validity] == '(') || (p[i]=='}' && validity[top_validity] == '{') || (p[i]==']'

&&	validity[top_validity] == '[')) pop_validity();

else if(p[i]!= ']' || p[i]!= '}' || p[i]!= ')')

continue;

else

return 1;

}

if(top_validity == -1)

return 0;

else

return 1;

}

void h10()

{
    system("cls");

char exp[20]; int i, o;
printf("### Valid Expression conversion to Polish Notation ###\n");

printf("Enter the expression: ");

gets(exp);

printf("\nOptions:");

printf("\n1.Check Validity of the expression\n2.To POSTFIX\n3.To PREFIX"); scanf("%d", &o);
switch(o)

{

case 1:

{

if(exp_checking(exp))

{

printf("\n\nExpression written is not valid!!!\n\n");

exit(1);

}

printf("\n\nExpression is valid!!!");

break;

}

case 2:

{

transform(exp,0);

printf("\n\nThe POSTFIX expression: ");

for(i = 0;i<20;i++)

printf("%c", postfix[i]);

printf("\n\n\n");

break;

}

case 3:

{

transform(exp,strlen(exp));

printf("\n\nThe PREFIX expression: ");

while(top_postfix!=-1)

printf("%c", pop_postfix());

printf("\n\n\n");

}

}

}

