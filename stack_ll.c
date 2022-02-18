#include<stdio.h>
#include<stdlib.h>
struct node
{  
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int d)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=d;
    if (top==NULL)
    {
        top=p;
        top->next=NULL;
    }
    else
    {
        p->next=top;
        top=p;
    }
}
void pop()
{
    struct node *p=top;
    if(top==NULL)
        printf("stack is empty");
    else
    {
        top=top->next;
    }
    free(p);
}
void display()
{
    int i;
    struct node *p=top;
    if (top==NULL)
        printf("stack is empty");
    else
    {
        while(p!=NULL)
        {
            printf("Stack elements are %d ",p->data);
            p=p->next;
        }
    }
}
void Top()
{
    if(top==NULL)
        printf("stack is empty");
    else
    {
        printf("top element is %d", top->data);
    }
}

void empty()
{
    if(top==NULL)
printf("Stack is empty");
    else
printf("Stack is not empty");
}

int main()
{
  int d,op;
  while(1)
  {
    printf("\n1.Push  2.Pop  3.Display  4.Top  5.Empty  6.Exit\n");
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
      case 4: Top();
              break;
      case 5: empty();
              break;        
      case 6: exit(0);
      default: printf("Invalid option");
    }
  }
}
