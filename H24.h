#include<stdio.h>

struct node2

{

int data;

struct node2* left;

struct node2* right;

};

struct node2* insert_node1(struct node2* root, int val)

{

if(root==NULL)

{

struct node2* temp = (struct node2*)malloc(sizeof(struct node2));

temp->data = val;

temp->left = NULL;

temp->right = NULL;

return temp;

}

if(val<root->data)

root->left = insert_node1(root->left,val);

else if(val>root->data)

root->right = insert_node1(root->right,val);

return root;;

}

int search_node(struct node2* root, int val)

{

if(root==NULL)

return 0;

if(root->data==val)

return 1;

if(val<root->data)

return search_node(root->left,val);

else

return search_node(root->right,val);

}

struct node2* node_index2(struct node2* root, int val)

{

if(root==NULL)

return NULL;

if(root->data==val)

return root;

if(val<root->data)

return node_index2(root->left,val);

else

return node_index2(root->right,val);

}

int left_max(struct node2* root)

{

if(root->right!=NULL)

return left_max(root->right);

else

return root->data;

}

void delete_node(struct node2* root, int val)

{

if(search_node(root,val)==1)

{

struct node2* elem_index = node_index2(root,val);

if((elem_index->left==NULL)&&(elem_index->right==NULL))

{

free(elem_index);

return;

}

int lmax = left_max(elem_index->left);

root->data = lmax;

struct node2* free_node = node_index2(root,lmax);

free(free_node);

}

else return;

}

void inorder(struct node2* root)

{

if(root!=NULL)

{

inorder(root->left);

printf("%d ", root->data);

inorder(root->right);

}

}

void preorder(struct node2* root)

{

if(root!=NULL)

{

printf("%d ", root->data);

preorder(root->left);

preorder(root->right);

}

}

void postorder(struct node2* root)

{

if(root!=NULL)

{

postorder(root->left);

postorder(root->right);

printf("%d ", root->data);

}

}

void h24()

{
system("cls");
printf("### Binary Search Tree (BST) using Linked List ###\n");
struct node2* root = NULL;

int opt, val,op;

while(1)

{

printf("\nOptions:\n");

printf("1.Insert node\n2,Delete a node\n3.Traverse\n4.Search a node\n5.Find Height\n6.Find Ancestors and descendant\n7.Find successor and predecessor\n8.Exit\n");

scanf("%d", &opt);

switch(opt)

{

case 1:

printf("Enter the data: ");

scanf("%d", &val);

root = insert_node1(root,val);

break;

case 2:

printf("Enter the value: ");

scanf("%d", &val);

delete_node(root,val);

break;

case 3:

printf("Options:\n");

printf("1.Inorder\n2.Preorder\n3.Postorder\n");

scanf("%d", &op);

if(op==1){

inorder(root);

printf("\n");}

else if(op==2){

preorder(root); printf("\n");}

else if(op==3){

postorder(root); printf("\n");}

break;

case 4:

printf("Enter the value: ");

scanf("%d", &val);

if(search_node(root,val)==0)

printf("Node was not Found!!\n\n");

else

printf("Node was found!!\n\n");

break;

default:

break;

}

}

}
