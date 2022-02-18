#include<stdio.h>
#include<stdlib.h>
int Q[6];
int front=-1,rear=-1;
void enQueue(int d)
{
	if(rear==5)
		printf("\n Queue is full and no insertion is possible");
	else if(rear==-1)
		front=rear=0;
	else
		rear++;
	Q[rear]=d;
}
void deQueue()
{
	int i;
	if(front==-1)
		printf("\nQueue is empty and no deletion is possible");
	else if(front==rear)
		front=rear=-1;
	else
	{
		for(i=front+1;i<=rear;i++)
			Q[i-1]=Q[i];
		rear--;
	}
}
void display()
{
	int i;
	if(front==-1)
		printf("Queue is empty");
	else
	{
		printf("\nQueue elements are : ");
		for(i=front;i<=rear;i++)
			printf("%d  ",Q[i]);
		
	}
}
int main()
{
  int d,op;
  while(1)
  {
    printf("\n1.enqueue  2.dequeue  3.Display  4.Exit\n");
    printf("Enter your option: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1: printf("Enter element to be inserted: ");
              scanf("%d",&d);
              enQueue(d);
              display();
              break;
      case 2: deQueue();
              display();
              break;
      case 3: display();
              break;
      case 4: exit(0);
      default: printf("Invalid option ......enter option between 1-4!");
    }
  }
}
