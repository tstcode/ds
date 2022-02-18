#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

struct Node *head;
void insert_beg(int d)
{
  struct Node *p;
  p=(struct Node*)malloc(sizeof(struct Node));
  p->data=d;
  if(head==NULL)
     p->next=NULL;
  else
     p->next=head;
     head=p;
}
 void insert_end(int d)
{
 struct Node *p,*q=head;
 p=(struct Node*)malloc(sizeof(struct Node));
 p->data=d;
 p->next=NULL;
 if(head==NULL)
    head=p;
 else
 {
   while(q->next!=NULL)
   q=q->next;
   q->next=p;
 }
}

void insert_pos(int d,int pos)
{
  int c=1;
  struct Node *p,*q=head;
  p=(struct Node *)malloc(sizeof(struct Node));
  p->data=d;
  while(c<pos-1)
  {
    q=q->next;
    c++;
  }
  p->next=q->next;
  q->next=p;
}

void delete_beg()
{
  struct Node *q=head;
  if(head==NULL)
  {
    printf("Linked List is empty and deletion is not possible");
    return;
  }
  else
  {
    q=head;
    head=head->next;
    free(q);
  }
}
void delete_end()
{
  struct Node *p=head,*q=head;
  if(head==NULL)
  {
   printf("Linked List and deeletion is not possible");
   return;
  }
  if(head->next==NULL)
  {
    head=NULL;
     free(q);
  }
 else
 {
   while(q->next!=NULL)
   {
     p=q;
     q=q->next;
   }
   p->next=NULL;
   free(q);
   }
}
void delete_pos(int pos)
{
 struct Node *p=head,*q=head;
 int c=1;
 while(c<pos)
 {
  p=q;
  q=q->next;
  c++;
 }
 p->next=q->next;
 free(q);
}


void display()
{
 struct Node *p=head;
 if(head==NULL)
 {
 printf("\n Linked List is empty");
 return;
}
 printf("In Linked List elements are");
 while(p!=NULL)
 {
  printf("%d  ",p->data);
  p=p->next;
 }
}
void isempty()
{
 if(head==NULL)
  printf("In Linked List is empty");
 else
  printf("In Linked List is not empty");
}


void size()
{
  struct  Node *p=head;
  int c=0;
  while(p!=NULL)
  {
    c++;
    p=p->next;
  }
  printf("\n no of nodes in linked list is %d",c);
}


int main()
{
  int op, ch, d, pos;
while(1)
{
printf("\n 1.Insertion 2.Deletion 3.Display 4.Size 5.Empty 6.Exit\n");
scanf("%d",&op);
switch(op)
{
case 1:printf("\nEnter an element to be inserted ");
      scanf("%d",&d);
      printf("\nInsert from 1.Beg 2.End 3.Position ");
      scanf("\nEnter your choice:");
      scanf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:insert_beg(d);
                 display();
                 break;
          case 2:insert_end(d);
                 display();
                 break;
          case 3:printf("\n Enter the position ");
                 scanf("%d",&pos);
                 insert_pos(d,pos);            
                 display();
                 break;
      }
break;
case 2:printf("\nDelete from 1.Beg 2.End 3.Position ");
    printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1:delete_beg();
                 display();
                 break;
          case 2:delete_end();
                 display();
                 break;
          case 3:printf("\nEnter the position: ");
                 scanf("%d",&pos);
                 delete_pos(pos);
                 display();
                 break;
      }
      break;
case 3:display();
      break;
case 4: size();
       break;
case 5:isempty();
      break;
case 6:exit(0);
default: printf("\nInvalid option and the option fron 1-6 ");
}
}
 return 0;
}
