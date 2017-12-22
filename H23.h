

#include<stdio.h>

struct node1

{

int data;

struct node1* left;

struct node1* right;

};

int n;
void inorder1(struct node1*);
void preorder1(struct node1*);
void postorder1(struct node1*);

void create_tree(struct node1 *root, int tree[], int i)

{

if(root==NULL)

return;

int j;

if(i*2<=n)

{

struct node1* temp1 = (struct node1*)malloc(sizeof(struct node1));

temp1->data = tree[i*2];

root->left = temp1;

}

else

root->left=NULL;

if(i*2+1<=n)

{

struct node1* temp2 = (struct node1*)malloc(sizeof(struct node1));

temp2->data = tree[i*2+1];

root->right = temp2;

}

else

root->right=NULL;

create_tree(root->left, tree, i*2);

create_tree(root->right, tree,i*2+1);

}

void inorder1(struct node1* root)

{

if(root!=NULL)

{

inorder1(root->left);

printf("%d ", root->data);

inorder1(root->right);

}

}

void preorder1(struct node1* root)

{

if(root!=NULL)

{

printf("%d ", root->data);

preorder1(root->left);

preorder1(root->right);

}

}

void postorder1(struct node1* root)

{

if(root!=NULL)

{

postorder1(root->left);

postorder1(root->right);

printf("%d ", root->data);

}

}

void h23()

{
system("cls");
 printf("### Complete Binary Tree using Arrays ###\n");
printf("Enter the num of nodes: ");

scanf("%d", &n);

int tree[n+1];

tree[0] = -1;

int i;

printf("Enter the tree data\n");

for(i=1;i<n+1;i++)

scanf("%d", &tree[i]);

struct node1* root = NULL;

if(n!=0)

{

root = (struct node1*)malloc(sizeof(struct node1));

root->data = tree[1];

create_tree(root,tree,1);

}

int opt;

while(1){

printf("Options:\n");

printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Levelorder\n5.Exit\n");

scanf("%d", &opt);

if(opt==1){

inorder1(root);

printf("\n");}

else if(opt==2){

preorder1(root); printf("\n");}

else if(opt==3){

postorder1(root); printf("\n");}

else if(opt==4)

{

for(i=1;i<n+1;i++)

printf("%d ", tree[i]);

printf("\n");

}

else

break;

}

}
