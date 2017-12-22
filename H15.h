#include<stdio.h>
int h15()
{
int i,j,min,n;
system("cls");printf("### SELECTION SORT ###\n");
printf("How many nubers:\n");
scanf("%d",&n);
int a[n];
printf("Enter %d numbers:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
int temp;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
min=j;}

if(i!=min)
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}printf("\nPress Enter to continue");
getche();
main();
}

