#include<stdio.h> 
#include<stdlib.h> 
void swap(int *a,int *b){ 
int t=*a; 
*a=*b; 
*b=t; 
} 
void heapify(int a[],int n,int i){ 
int largest=i; 
int left=2*i+1; 
int right=2*i+2; 
if(left<n && a[left]> a[largest]) 
largest=left; 
if(right<n && a[right]>a[largest]) 
largest=right; 
if(largest!=i){ 
swap(&a[i],&a[largest]); 
heapify(a,n,largest); 
} 
} 
void heapsort(int a[],int n){ 
int i; 
for(i=n/2-1;i>=0;i--) 
heapify(a,n,i); 
for(i=n-1;i>=0;i--){ 
swap(&a[0],&a[i]); 
heapify(a,i,0); 
} 
} 
int main(){ 
int a[100],n; 
printf("Enter Number of elements in array:\n"); 
scanf("%d",&n); 
printf("Enter %d Elements of array:\n",n); 
for(int i=0;i<n;i++) 
scanf("%d",&a[i]); 
heapsort(a,n); 
printf("Sorted Array is:\n"); 
for(int i=0;i<n;i++) 
printf("%d ",a[i]); 
return 0; 
} 
 
