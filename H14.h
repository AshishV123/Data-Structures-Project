

#include<stdio.h>


int h14()


{
    system("cls");printf("### INSERTION SORT ###\n");
int i,j,k,n;printf("how many numbers to be sorted:");
scanf("%d",&n);
printf("Enter %d numbers:",n);
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=1;i<n;i++)
{
k=a[i];
for(j=i-1;j>=0 && k<a[j];j--)
{
a[j+1]=a[j];
}
a[j+1]=k;
}
for(i=0;i<n;i++)
{
printf(" %d ",a[i]);

}
printf("\nPress Enter to continue");
getche();
main();
}
