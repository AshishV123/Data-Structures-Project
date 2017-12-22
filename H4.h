


#include<stdio.h>

struct node9

{

int info;

struct node9 *link;

};

struct node9 *create_list9(struct node9 *start);

void display9(struct node9 *start);

void search9(struct node9 *start,int data);

struct node9*addatbeg9(struct node9 *start,int data);

struct node9 *addatend9(struct node9 *start,int data);

struct node9 *addafter9(struct node9 *start,int data,int item);

struct node9 *addbefore9(struct node9 *start,int data,int item );

struct node9 *addatpos9(struct node9 *start,int data,int pos);

struct node9 *del9(struct node9 *start,int data);

struct node9 *reverse9(struct node9 *start);

h4()

{
system("cls");
struct node9 *start=NULL;

int ch,data,item,pos;

printf("### SINGLY LINKED LIST ###\n");
while(1)

{
printf("1.Create List\n");

printf("2.Display\n");

printf("3.Search\n");

printf("4. Add at beginning\n");

printf("5.Add at end\n");

printf("6.Add after node\n");

printf("7.Add before node\n");

printf("8.Add at position\n");

printf("9.Delete\n");

printf("10.Reverse\n");

printf("Enter your choice : ");

scanf("%d",&ch);

switch(ch)

{

case 1:

start=create_list9(start);

break;

case 2:

display9(start);

break;

case 3:

printf("Enter the element to be searched : ");

scanf("%d",&data);

search9(start,data);

break;

case 4:

printf("Enter the element to be inserted : ");

scanf("%d",&data);

start=addatbeg9(start,data);

break;

case 5:

printf("Enter the element to be inserted : ");

scanf("%d",&data);

start=addatend9(start,data);

break;

case 6:

printf("Enter the element to be inserted : ");

scanf("%d",&data);

printf("Enter the element after which to insert : ");

scanf("%d",&item);

start=addafter9(start,data,item);

break;

case 7:

printf("Enter the element to be inserted : ");

scanf("%d",&data);

printf("Enter the element before which to insert : ");

scanf("%d",&item);

start=addbefore9(start,data,item);

break;

case 8:

printf("Enter the element to be inserted : ");

scanf("%d",&data);

printf("Enter the position at which to insert : ");

scanf("%d",&pos);

start=addatpos9(start,data,pos);

break;

case 9:

printf("Enter the element to be deleted : ");

scanf("%d",&data);

start=del9(start, data);

break;

case 10:

start=reverse9(start);

break;

default:

printf("Wrong choice\n");

}

}

}

struct node9 *create_list9(struct node9 *start)

{

int i,n,data;

printf("Enter the number of nodes : ");

scanf("%d",&n);

start=NULL;

if(n==0)

return start;

printf("Enter the element to be inserted : ");

scanf("%d",&data);

start=addatbeg9(start,data);

for(i=2;i<=n;i++)

{

printf("Enter the element to be inserted : ");

scanf("%d",&data);

start=addatend9(start,data);

}

return start;

}

void display9(struct node9 *start)

{

struct node9 *p;

if(start==NULL)

{

printf("List is empty\n");

return;

}

p=start;

printf("List is :\n");

while(p!=NULL)

{

printf("%d ",p->info);

p=p->link;

}

printf("\n\n");

}

void search9(struct node9 *start,int item)

{

struct node9 *p=start;

int pos=1;

while(p!=NULL)

{

if(p->info==item)

{

printf("Item %d found at position %d\n",item,pos); return;

}

p=p->link;

pos++;

}

printf("Item %d not found in list\n",item);

}

struct node9 *addatbeg9(struct node9 *start,int data)

{

struct node9 *tmp;

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

tmp->link=start;

start=tmp;

return start;

}

struct node9 *addatend9(struct node9 *start,int data)

{

struct node9 *p,*tmp;

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

p=start;

while(p->link!=NULL)

p=p->link;

p->link=tmp;

tmp->link=NULL;

return start;

}

struct node9 *addafter9(struct node9 *start,int data,int item)

{

struct node9 *tmp,*p;

p=start;

while(p!=NULL)

{

if(p->info==item)

{

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

tmp->link=p->link;

p->link=tmp;

return start;

}

p=p->link;

}

printf("%d not present in the list\n",item);

return start;

}

struct node9 *addbefore9(struct node9 *start,int data,int item)

{

struct node9 *tmp,*p;

if(start==NULL )

{

printf("List is empty\n");

return start;

}

if(item==start->info)

{

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

tmp->link=start;

start=tmp;

return start;

}

p=start;

while(p->link!=NULL)

{

if(p->link->info==item)

{

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

tmp->link=p->link;

p->link=tmp;

return start;

}

p=p->link;

}

printf("%d not present in the list\n",item);

return start;

}

struct node9 *addatpos9(struct node9 *start,int data,int pos)

{

struct node9 *tmp,*p;

int i;

tmp=(struct node9 *)malloc(sizeof(struct node9));

tmp->info=data;

if(pos==1)

{

tmp->link=start;

start=tmp;

return start;

}

p=start;

for(i=1; i<pos-1 && p!=NULL; i++)

p=p->link;

if(p==NULL)

printf("There are less than %d elements\n",pos);

else

{

tmp->link=p->link;

p->link=tmp;

}

return start;

}

struct node9 *del9(struct node9 *start,int data)

{

struct node9 *tmp,*p;

if(start==NULL)

{

printf("List is empty\n");

return start;

}

if(start->info==data)

{

tmp=start;

start=start->link;

free(tmp);

return start;

}

p=start;

while(p->link!=NULL)

{

if(p->link->info==data)

{

tmp=p->link;

p->link=tmp->link;

free(tmp);

return start;

}

p=p->link;

}

printf("Element %d not found\n",data);

return start;

}

struct node9 *reverse9(struct node9 *start)

{

struct node9 *prev, *ptr, *next;

prev=NULL;

ptr=start;

while(ptr!=NULL)

{

next=ptr->link;

ptr->link=prev;

prev=ptr;

ptr=next;

}

start=prev;

return start;

}

