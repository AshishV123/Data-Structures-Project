#include<stdio.h>

int n;

struct node4

{

int data;

struct node4* left;

struct node4* right;

int lthread;

int rthread;

};

int traverse[20];

struct node4* root_n4 = NULL;

struct node4* node_index4(struct node4* root, int val)

{

if(root==NULL)

return NULL;

if(root->data==val)

return root;

if(val<root->data)

return node_index4(root->left,val);

else

return node_index4(root->right,val);

}

void make_threads4(struct node4* root)

{

if(root==NULL)

return;

int i;	struct node4* temp = NULL;

struct node4* templ = root->left;

struct node4* tempr = root->right;

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

root->left = node_index4(root_n4,traverse[i-1]);

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

temp = node_index4(root_n4,traverse[i+1]);

root->right = temp;

}

}

make_threads4(templ);

make_threads4(tempr);

}

void inorder4(struct node4* root)

{

if(root!=NULL)

{

inorder4(root->left);

printf("%d ", root->data); traverse[n] = root->data; n++; inorder4(root->right);

}

}
void in_threaded4(struct node4* root)

{

n=0;

inorder4(root);

make_threads4(root);

}
void preorder4(struct node4* root)

{

if(root!=NULL)

{

printf("%d ", root->data); traverse[n] = root->data; n++;

preorder4(root->left);

preorder4(root->right);

}

}

void pre_threaded4(struct node4* root)

{

n=0;

preorder4(root);

make_threads4(root);

}

void postorder4(struct node4* root)

{

if(root!=NULL)

{

postorder4(root->left);

postorder4(root->right);

printf("%d ", root->data); traverse[n] = root->data; n++;

}

}

void post_threaded4(struct node4* root)

{

n=0;

postorder4(root);

make_threads4(root);

}

struct node4* insert_node4(struct node4* root, int val)

{

if(root==NULL)

{

struct node4* temp = (struct node4*)malloc(sizeof(struct node4));

temp->data = val;

temp->left = NULL;

temp->right = NULL;

temp->lthread = 0;

temp->rthread = 0;

return temp;

}

if(val<root->data)

root->left = insert_node4(root->left,val);

else if(val>root->data)

root->right = insert_node4(root->right,val);

return root;

}



void h27()

{
system("cls");

printf("### Heap Tree and Heap sort using array ###\n");
struct node4* root = NULL;

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

root = insert_node4(root,val);

root_n4 = root;

break;

case 2:

printf("Options:\n");

printf("1.Inorder\n2.Preorder\n3.Postorder\n");

scanf("%d", &op);

if(op==1){

inorder4(root);

printf("\n");}

else if(op==2){

preorder4(root); printf("\n");}

else if(op==3){

postorder4(root); printf("\n");}

break;

case 3:

printf("\n1.In-threaded\n2.Pre-threaded\n3.Post-threaded");

scanf("%d", &op);

if(op==1)

in_threaded4(root);

if(op==2)

pre_threaded4(root);

if(op==3)

post_threaded4(root);

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

