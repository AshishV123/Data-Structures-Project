
#include<stdio.h>

int n;

struct node5
{

int data;

struct node5* left;

struct node5* right;

int lthread;

int rthread;

};

int traverse[20];

struct node5* root_n5 = NULL;

struct node5* node_index5(struct node5* root, int val)

{

if(root==NULL)

return NULL;

if(root->data==val)

return root;

if(val<root->data)

return node_index5(root->left,val);

else

return node_index5(root->right,val);

}

void make_threads5(struct node5* root)

{

if(root==NULL)

return;

int i;	struct node5* temp = NULL;

struct node5* templ = root->left;

struct node5* tempr = root->right;

if(root->left==NULL)

{

root->lthread = 1;

for(i=0;i<n;i++)

{

if(root->data == traverse[i])

break;

}

if(i>0)

{

root->lthread = 1;

root->left = node_index5(root_n5,traverse[i-1]);

}

}

if(root->right==NULL)

{

root->rthread = 1;

for(i=0;i<n;i++)

{

if(root->data == traverse[i])

break;

}

if(i<=n-2)

{

temp = node_index5(root_n5,traverse[i+1]);

root->right = temp;

}

}

make_threads5(templ);

make_threads5(tempr);

}

void inorder5(struct node5* root)

{

if(root!=NULL)

{

inorder5(root->left);

printf("%d ", root->data); traverse[n] = root->data; n++; inorder5(root->right);

}

}

void in_threaded5(struct node5* root)

{

n=0;

inorder5(root);

make_threads5(root);

}

void preorder5(struct node5* root)

{

if(root!=NULL)

{

printf("%d ", root->data); traverse[n] = root->data; n++;

preorder5(root->left);

preorder5(root->right);

}

}

void pre_threaded5(struct node5* root)

{

n=0;

preorder5(root);

make_threads5(root);

}
void postorder5(struct node5* root)

{

if(root!=NULL)

{

postorder5(root->left);

postorder5(root->right);

printf("%d ", root->data); traverse[n] = root->data; n++;

}

}

void post_threaded5(struct node5* root)

{

n=0;

postorder5(root);

make_threads5(root);

}

struct node5* insert_node5(struct node5* root, int val)

{

if(root==NULL)

{

struct node5* temp = (struct node5*)malloc(sizeof(struct node5));

temp->data = val;

temp->left = NULL;

temp->right = NULL;

temp->lthread = 0;

temp->rthread = 0;

return temp;

}

if(val<root->data)

root->left = insert_node5(root->left,val);

else if(val>root->data)

root->right = insert_node5(root->right,val);

return root;

}


void h28()

{
    system("cls");

printf("###  AVL: A height balanced binary search tree ###\n");
struct node5* root = NULL;

int opt, val,op;

while(1)

{

printf("\nOptions:\n");

printf("1.Insert node\n2.Traverse\n3.Build threaded tree\n4.Exit\n");

scanf("%d", &opt);

switch(opt)

{

case 1:

printf("Enter the data: ");

scanf("%d", &val);

root = insert_node5(root,val);

root_n5 = root;

break;

case 2:

printf("Options:\n");

printf("1.Inorder\n2.Preorder\n3.Postorder\n");

scanf("%d", &op);

if(op==1){

inorder5(root);

printf("\n");}

else if(op==2){

preorder5(root); printf("\n");}

else if(op==3){

postorder5(root); printf("\n");}

break;

case 3:

printf("\n1.In-threaded\n2.Pre-threaded\n3.Post-threaded");

scanf("%d", &op);

if(op==1)

in_threaded5(root);

if(op==2)

pre_threaded5(root);

if(op==3)

post_threaded5(root);

printf("\n\nThreaded tree was made!!!");

break;

case 4:
main();
break;

}

if(opt==4 || opt==3)

break;

}

}
