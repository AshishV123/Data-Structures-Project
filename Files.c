#include"H.h"
void B()
{int a;
       while(1){     system("cls");
       printf("### SEARCHING ###\n");

    printf("\nEnter Searching Technique You Want to execute: \nPress: \n 1: Linear Search\n 2: Bubble Search\n 3: Fibonacci Search\n");
    printf(" 4. To Exit\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            system("cls");
            A();
            break;
        case 2:

            system("cls");
            h12b();
            break;
        case 3:
            system("cls");
            h12c();
            break;
        case 4:
            system("cls");
            main();
        default:
            {printf("Enter correct choice\n");
            B();}
    }}
}


sorting1()
{
    system("cls");printf("### SORTING ###\n");
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

}}
