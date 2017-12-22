
#include"H23.h"
#include"H24.h"
#include"H25.h"
#include"H26.h"
#include"H27.h"
#include"H28.h"
tree1()
{int a;
    system("cls");
    printf("### TREE ###\n");
    printf(" 1: Implementation of Complete Binary Tree using arrays\n");
    printf(" 2: Implementation of Binary Search Tree (BST) using linked list\n");
    printf(" 3: Implementation of conversion of BST to Threaded Binary Tree\n");
    printf(" 4: Implementation of Expression tree for the given postfix expression\n");
    printf(" 5: Implementation of Heap Tree and Heap sort using array\n");
    printf(" 6: Implementation of AVL: A height balanced binary search tree\n");
    printf(" 7. To Exit");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        h23();
        break;
    case 2:
        h24();
        break;
    case 3:
        h25();
        break;
    case 4:
        h26();
        break;
    case 5:
        h27();
        break;
    case 6:
        h28();break;
    case 7:

        main();
        break;
    default:
        printf("Enter correct choice\n");
        getche();
        main();

    }
}
