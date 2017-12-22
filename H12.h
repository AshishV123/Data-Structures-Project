
#include<stdio.h>

void h13()
{
    system("cls");
int n,i,j,temp;printf("### BUBBLE SORT ###\n");
printf("how many numbers to be sorted:");
scanf("%d",&n);
printf("Enter %d numbers:",n);
int num[n];
for(i=0;i<n;i++)
{
scanf("%d",&num[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
if(num[j]>num[j+1])
{
temp=num[j];
num[j]=num[j+1];
num[j+1]=temp;
}
}}
for(i=0;i<n;i++)
{
printf(" %d ",num[i]);
}
printf("\nPress Enter to continue");
getche();
main();
}
