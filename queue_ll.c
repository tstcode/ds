#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL, *rear=NULL;
void enqueue(int d)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=d;
    p->next=NULL;
    if(rear==NULL)
    {
        rear=front=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
void dequeue()
{
    struct node *q=front;
    if(front==NULL)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=NULL;
        free(q);
    }
    else
    {
        front=front->next;
        free(q);
    }
}
void display()
{
    struct node *p=front;
    if(front==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue elements are ");
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p=p->next;
        }       
    }
}
int main()
{
  int d,op;
  while(1)
  {
    printf("\n1. enQueue\n2. deQueue\n3. Display\n4. Exit\n");
    printf("Enter your option: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1: printf("Enter element to be inserted: ");
              scanf("%d",&d);
              enqueue(d);
              display();
              break;
      case 2: dequeue();
              display();
              break;
      case 3: display();
              break;
      case 4: exit(0);
      default: printf("Invalid option................................");
    }
  }
}
