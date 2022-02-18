#include<stdio.h>
#include<stdlib.h>
void infix_to_postfix(char[ ],char[ ]);
int precidence(char);
int main()
{
char infix[30],postfix[30];
printf("\n enter infix expression");
gets(infix);
infix_to_postfix(infix,postfix);
printf("\n postfix expression is %s",postfix);
return 0;

}
int precedence(char c)
{
switch(c)
{
case '+':
case '-': return 1;
case '*':
case '/':
case '%': return 2;
case '^': return 3;
    default    : return 0;
}

}
void infix_to_postfix(char infix[ ],char postfix[ ])
{
char s[30],ch;
int top=-1;
int i=0,j=0;
while(infix[i]!='\0')
{
ch=infix[i];
switch(ch)
{
case '(': top++;
 s[top]=ch;
 break;
case ')': while(s[top]!='(')
          postfix[j++]=s[top--];
 top--;
 break;
case '+':
case '-': 
case '*':
case '/':
case '%': 
case '^': while(precedence(s[top])>=precedence(ch))
postfix[j++]=s[top--];
 s[++top]=ch;
 break;
      default :  postfix[j++]=ch;
}
i++;
}
while(top!=-1)
postfix[j++]=s[top--];
postfix[j]='\0';
}
