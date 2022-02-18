#include<stdio.h>
#include<stdlib.h>

int a[10],top=-1;

void isempty()
{
if(top== -1)
printf("Stack is empty");
else
printf("Stack is not empty");
}

void Top()
{
 if(top== -1)
 printf("Stack is empty");
 else
 printf("Top element is %d",a[top]);
}

void push(int d)
{
 if(top == 9)
printf("Stack is full & NO insertions possible");
 else
 {
 top++;
 a[top]=d;
 }
}

void pop()
{
 if(top == -1)
 printf("Stack is empty & deletion NOT possible");
 else
 {
 printf("\nDeleted element is %d\n",a[top]);
 top--;
 }
}

void display()
{
 int i;
 if(top == -1)
  printf("Stack is empty");
 else
 {
  printf("Stack elements are ");
  for(i=0;i<=top;i++)
  printf("%d ",a[i]);
 }
}

int main()
{
 int d,op;
 while(1)
 {
  printf("\n1.Push\n2.Pop\n3.Display\n4.Empty\n5.Top\n6.Exit\n");
  printf("Enter your option: ");
  scanf("%d",&op);
  switch(op)
  {
 case 1: printf("Enter element to be inserted: ");
scanf("%d",&d);
push(d);
display();
   break;
   case 2: pop();
    display();
    break;
   case 3: display();
    break;
   case 4: isempty();
 break;
case 5: Top();
    break;
   case 6: exit(0);
   default: printf("Invalid option.Enter option from 1-6");
  }
 }
}
