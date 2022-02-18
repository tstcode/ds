#include<stdio.h> 
#include<stdlib.h> 
void quicksort(int x[100],int first,int last){ 
int pivot,i,j,temp; 
if(first<last){ 
pivot=first; 
i=first; 
j=last; 
while(i<j){ 
while(x[i]<=x[pivot] && i<last) 
i++; 
while(x[j]>x[pivot]) 
j--; 
if(i<j){ 
temp=x[i]; 
x[i]=x[j]; 
x[j]=temp; 
} 
} 
temp=x[pivot]; 
x[pivot]=x[j]; 
x[j]=temp; 
quicksort(x,first,j-1); 
quicksort(x,j+1,last); 
} 
} 
int main(){ 
int a[100],n; 
printf("Enter Number of elements in array:\n"); 
scanf("%d",&n); 
printf("Enter %d Elements of array:\n",n); 
for(int i=0;i<n;i++) 
scanf("%d",&a[i]); 
quicksort(a,0,n-1); 
printf("Sorted Array is:\n"); 
for(int i=0;i<n;i++) 
printf("%d ",a[i]); 
return 0; 
}
