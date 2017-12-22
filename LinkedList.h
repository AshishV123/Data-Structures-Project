#include"H4.h"
#include"H5.h"
#include"H6.h"
h456()
{int a;
system("cls");printf("### LINKED LISTS ###\n");
    printf("Press\n 1. To implement Singly Linked List\n 2. To implement Singly Circular List\n 3. To implement Doubly linked List\n");
    printf(" 4. to exit to main menu\n");
    scanf("%d",&a);

    switch(a)
    {
    case 1:
        h4();
        break;
    case 2:
        h5();
        break;
    case 3:
        h6();
        break;
    case 4:
        main();
        break;
    default:
        printf("Enter Correct choice\n");
        getche();
        main();
    }
}
