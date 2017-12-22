
#include"H12.h"
#include"H14.h"
#include"H15.h"
#include"H16.h"
#include"H17.h"



sorting1()
{
    system("cls");
     printf(" Press\n 1: Implementation of Bubble sort\n");
    printf(" 2: Implementation of Insertion sort\n");
    printf(" 3: Implementation of Selection sort\n");
    printf(" 4: Implementation of Quick sort\n");
    printf(" 5: Implementation of Merge sort\n");
    printf(" 6: To Exit\n");
    int a;
     scanf("%d",&a);
    switch(a)
    {
    case 1:
        h13();
        break;
    case 2:
        h14();
        break;
    case 3:
        h15();
        break;
    case 4:
        h16();
        break;
    case 5:
        h17();
        break;
    case 6:
        main();
        break;
    default:
        printf("Enter correct choice\n");
        getche();
        main();

}
