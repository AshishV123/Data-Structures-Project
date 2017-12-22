#include<stdio.h>

#include<stdlib.h>
int search(int *a,int n,int x)

{int i; for(i=0;i<n;i++)

{

if(a[i]==x) return i;
}

return -1;

}
int A()

{
printf("### LINEAR SEARCH ###\n");
int *a=NULL,n=0;

int i;

while(1)

{

fflush(stdin);

printf("\nEnter element(-1 to terminate):");
scanf("%d",&i);

if(i==-1)break;

n++;

a=realloc(a,n*sizeof(int));

a[n-1]=i;

}

printf("\nEnter no. to search:");

int x;

scanf("%d",&x);

int k=search(a,n,x);

if(k==-1)

printf("\nElement not present!!");

else

printf("\nElement found at index:%d",k);

}



#include<limits.h>

int search2(int *a,int l,int r,int x)

{

int m,j=-1;

m=l+(r-l)/2;

if(l>r)

return -1;

if(x==a[m])

j=m;

else if(x<a[m])

j=search2(a,l,m-1,x);

else

j=search2(a,m-1,r,x);

return j;

}

int h12b()

{
printf("### BINARY SEARCH ###\n");
int *a=NULL,n=0;

printf("\nEnter elements in sorted order(change order to terminate):\n");

int i,j=INT_MIN;

while(1)

{fflush(stdin); printf("\nEnter element:"); scanf("%d",&i);
if(j>i)

break;

n++;

a=realloc(a,n*sizeof(int)); a[n-1]=i;

j=i;

}

printf("\nEnter no. to search:");

int x;

scanf("%d",&x);

int k=search2(a,0,n-1,x);

if(k==-1)

printf("\nElement not present!!");

else

printf("\nElement found at index:%d",k);}





int min(int x, int y) { return (x<=y)? x : y; }

int fibMonaccianSearch(int arr[], int x, int n){

int fibMMm2 = 0;

int fibMMm1 = 1;

int fibM = fibMMm2 + fibMMm1;

while (fibM < n)

{

fibMMm2 = fibMMm1;

fibMMm1 = fibM;

fibM = fibMMm2 + fibMMm1;

}

int offset = -1;

while (fibM > 1)

{

int i = min(offset+fibMMm2, n-1);

if (arr[i] < x)

{

fibM = fibMMm1;

fibMMm1 = fibMMm2;

fibMMm2 = fibM - fibMMm1;

offset = i;

}

else if (arr[i] > x)

{fibM = fibMMm2; fibMMm1 = fibMMm1 - fibMMm2; fibMMm2 = fibM - fibMMm1;

}

else return i;

}

if(fibMMm1 && arr[offset+1]==x)return offset+1;

return -1;

}

int h12c()

{
    printf("### FIBONACCI SEARCH ###\n");
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};

int n = sizeof(arr)/sizeof(arr[0]);

int x = 85;

printf("Found at index: %d",

fibMonaccianSearch(arr, x, n));

return 0;}

