#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*top=NULL;

void push();
void pop();
void display();


void main()
{
int ch;
printf("stack using linked list");
while(1)

{
printf("\n Menu");
printf("\n1. push 2.pop 3.display 4.exit");
printf("enter choice");
scanf("%d",&ch);

switch(ch)
{
case 1:push();
       break;
case 2:pop();
       break;
case 3:display();
       break;
case 4:exit(0);
default:printf("\n wrong choice") ;
}
}
}
void push()
{
int n;
struct node *newnode;
printf("enter value to be inserted");
scanf("%d",&n);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=n;
if(top==NULL)
newnode->next=NULL;
else
newnode->next=top;
top=newnode;
printf("insertion success");
}






void pop()
{
if(top==NULL)
printf("empty");
else
{
struct node *temp,*top;
printf("deleted element is %d",temp->data);
top=temp->next;
free(temp);
}
}



void display()
{
if(top==NULL)
printf("empty");
else
{
struct node *temp=top;
while(temp->next!=NULL)
{
printf("%d ->",temp->data);
temp=temp->next;
}
printf("%d ->NULL",temp->data);
}
}
