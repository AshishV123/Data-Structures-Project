#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
    char data;
    struct tree *left,*right;
};

int top44=-1;
struct tree *stack44[20];
struct tree *node;

void push44(struct tree* node)
{
    stack44[++top44]=node;
}

struct tree * pop44()
{
    return(stack44[top44--]);
}

/* Calculating the value of postfix expression using recursion */
int check44(char ch)
{
if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
return 2;
else
return 1;
}

int cal(struct tree *node)
{
    int ch;
    ch=check44(node->data);
    if(ch==1)
    return node->data-48;
    else if(ch==2)
    {
        if(node->data=='+')
            return cal(node->left)+cal(node->right);
        if(node->data=='-')
            return cal(node->left)-cal(node->right);
        if(node->data=='*')
            return cal(node->left)*cal(node->right);
        if(node->data=='/')
            return cal(node->left)/cal(node->right);
    }
}

/* Displaying all node in order */

void inorder44(struct tree *node)
{
    if(node!=NULL)
    {
    inorder44(node->left);
    printf("%c",node->data);
    inorder44(node->right);
    }
}

/* making simple operand node and pushing into stack */

void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push44(node);
}

/* making operator node than pop-up two nodes from stack and adding into operator node and finally push node into stack  */

void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop44();
    node->left=pop44();
    push44(node);
}

void h26()
{
    int i,p,k,ans;
    char s[20];
    system("cls");

printf("### Expression tree for the given Postfix Expression ###\n");
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    gets(s);
    k=strlen(s);
    i=0;
    for(i=0;s[i]!='\0';i++)
        {
            p=check44(s[i]);
            if(p==1)
            operand(s[i]);
            else if(p==2)
            operators(s[i]);
        }
    ans=cal(stack44[top44]);
    printf("\nThe value of the postfix expression you entered is %d\n",ans);
    printf("\nThe inorder traversal of the tree is \n");
    inorder44(stack44[top44]);
    getche();
}
