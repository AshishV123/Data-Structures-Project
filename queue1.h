#include"H18.h"
#include"H19.h"
#include"H20.h"
#include"H21.h"
#include"H22.h"

queue1()
{int a;
    system("cls");
    printf("### QUEUE ###\n");
     printf(" 1: Demonstration of the working of Queue using array\n");
    printf(" 2: Demonstration of the working of Circular Queue using array\n");
    printf(" 3: Demonstration of the working of Queue using single linked list\n");
    printf(" 4: Demonstration of the working of Queue using circular linked list\n");
    printf(" 5: Demonstration of the working of Deque using array\n");
    printf(" 6. To Exit");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        h18();
        break;
    case 2:
        h19();
        break;
    case 3:
        h20();
        break;
    case 4:
        h21();
        break;
    case 5:
        h22();
        break;
    case 6:
        main();
        break;
    default:
        printf("Enter correct choice\n");
        getche();
        main();

    }
}
