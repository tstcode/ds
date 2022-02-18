#include<stdio.h> 
#include<stdlib.h> 
void merge(int a[],int l,int h,int m){ 
int c[100],i,j,k; 
i=1; 
j=m+1; 
k=1; 
while(i<=m && j<=h){ 
if(a[i]<a[j]) 
c[k++]=a[i++]; 
else 
c[k++]=a[j++]; 
} 
while(i<=m) 
c[k++]=a[i++]; 
while(j<=h) 
c[k++]=a[j++]; 
for(i=1;i<k;i++) 
a[i]=c[i]; 
} 
void mergesort(int a[],int low,int high){ 
int mid; 
if(low<high){ 
mid=(low+high)/2; 
mergesort(a,low,mid); 
mergesort(a,mid+1,high); 
merge(a,low,high,mid); 
} 
} 
int main(){ 
int a[100],n; 
printf("Enter Number of elements in array:\n"); 
scanf("%d",&n); 
printf("Enter %d Elements of array:\n",n); 
for(int i=0;i<n;i++) 
scanf("%d",&a[i]); 
mergesort(a,0,n-1); 
printf("Sorted Array is:\n"); 
for(int i=0;i<n;i++) 
printf("%d ",a[i]); 
return 0; 
} 
