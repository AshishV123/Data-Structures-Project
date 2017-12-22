
#include"H7.h"
#include"H8.h"
#include"H9.h"

h789()
{int a;
    system("cls");
    printf("Press\n 1. Demonstration of the working of Stack using array\n");
    printf(" 2: Implementation of two stack in one array\n");
    printf(" 3: Demonstration of the working of Stack using linked list\n");
    printf(" 4. To Exit");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        h7();
        break;
    case 2:
        h8();
        break;
    case 3:
        h9();
        break;
    case 4:
        main();
        break;
    default:
        printf("Enter correct choice\n");
        getche();
        main();

    }
}
