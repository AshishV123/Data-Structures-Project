
#include<stdio.h>

int n;

struct node3

{

int data;

struct node3* left;

struct node3* right;

int lthread;

int rthread;

};
void inorder2(struct node3* root);
void preorder2(struct node3* root);
void postorder2(struct node3* root);
int traverse[20];

struct node3* root_n = NULL;

struct node3* node_index(struct node3* root, int val)

{

if(root==NULL)

return NULL;

if(root->data==val)

return root;

if(val<root->data)

return node_index(root->left,val);

else

return node_index(root->right,val);

}

void make_threads(struct node3* root)

{

if(root==NULL)

return;

int i;	struct node3* temp = NULL;

struct node3* templ = root->left;

struct node3* tempr = root->right;

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

root->left = node_index(root_n,traverse[i-1]);

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

temp = node_index(root_n,traverse[i+1]);

root->right = temp;

}

}

make_threads(templ);

make_threads(tempr);

}

void in_threaded(struct node3* root)

{

n=0;

inorder2(root);

make_threads(root);

}

void pre_threaded(struct node3* root)

{

n=0;

preorder2(root);

make_threads(root);

}

void post_threaded(struct node3* root)

{

n=0;

postorder2(root);

make_threads(root);

}

struct node3* insert_node(struct node3* root, int val)

{

if(root==NULL)

{

struct node3* temp = (struct node3*)malloc(sizeof(struct node3));

temp->data = val;

temp->left = NULL;

temp->right = NULL;

temp->lthread = 0;

temp->rthread = 0;

return temp;

}

if(val<root->data)

root->left = insert_node(root->left,val);

else if(val>root->data)

root->right = insert_node(root->right,val);

return root;

}

void inorder2(struct node3* root)

{

if(root!=NULL)

{

inorder2(root->left);

printf("%d ", root->data); traverse[n] = root->data; n++; inorder2(root->right);

}

}

void preorder2(struct node3* root)

{

if(root!=NULL)

{

printf("%d ", root->data); traverse[n] = root->data; n++;

preorder2(root->left);

preorder2(root->right);

}

}

void postorder2(struct node3* root)

{

if(root!=NULL)

{

postorder2(root->left);

postorder2(root->right);

printf("%d ", root->data); traverse[n] = root->data; n++;

}

}

void h25()

{
system("cls");

printf("### Conversion of BST to Threaded Binary Tree ###\n");
struct node3* root = NULL;

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

root = insert_node(root,val);

root_n = root;

break;

case 2:

printf("Options:\n");

printf("1.Inorder\n2.Preorder\n3.Postorder\n");

scanf("%d", &op);

if(op==1){

inorder2(root);

printf("\n");}

else if(op==2){

preorder2(root); printf("\n");}

else if(op==3){

postorder2(root); printf("\n");}

break;

case 3:

printf("\n1.In-threaded\n2.Pre-threaded\n3.Post-threaded");

scanf("%d", &op);

if(op==1)

in_threaded(root);

if(op==2)

pre_threaded(root);

if(op==3)

post_threaded(root);

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
