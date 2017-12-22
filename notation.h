

#include"H10.h"
#include"H11.h"
notation()
{int a;
    system("cls");
    printf("### NOTATION ###\n");
      printf(" 1: Implementation of a valid expression conversion to polish notation\n");
    printf(" 2: Evaluation of valid postfix expression using stack\n");
    printf(" 3. To Exit\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        h10();
        break;
    case 2:
        h11();
        break;
    case 3:
        main();
        break;
    default:
        printf("Enter correct choice\n");
        getche();
        main();

    }
}
