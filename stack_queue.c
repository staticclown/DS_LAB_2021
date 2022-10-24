#include<stdlib.h>
#include<stdio.h>
int val;
struct node
{
    int data;
    struct node * link;
    
};

struct node *top=NULL,*rear=NULL,*front=NULL,*newn,*temp;

void stack_in()
{
    newn=(struct node *)malloc(sizeof(struct node));
printf("enter the value to insert");
scanf("%d",&val);

if(top==NULL)
{
    newn->link=NULL;
    newn->data=val;
    top=newn;
}
else 
{   newn->link=top;
    newn->data=val;
    top=newn;
    
    
}

}

void stack_out()
{

if(top==NULL)
{
    printf("EMPTY");
}
else if(top->link==NULL)
{
    printf("\n deleting value =%d",top->data);
    free(top);
    top=NULL;
}
else
{
temp=top;
top=top->link;
free(temp);

}

}

void stack_display()
{
    printf("\n");
    temp=top;
while(temp!=NULL)
    {
    printf("\t %d",temp->data);
    temp=temp->link;
    }
printf("\n");
}

void queue_in()
{
newn=(struct node *)malloc(sizeof(struct node));
printf("enter the value to insert");
scanf("%d",&val);

if(rear==NULL)
{
    newn->data=val;
    newn->link=NULL;
    rear=newn;
    front=newn;

}
else
{
    newn->data=val;
    newn->link=NULL;
    rear->link=newn;
    rear=newn;
}

}

void queue_out()
{
    if(front==NULL)
    {
        printf("\n empty");

    }
    else if(front->link==NULL)
    {
        printf("deleting value =%d",front->data);
        front=NULL;
        rear=NULL;

    }
    else
    {
        printf("deleting value =%d",front->data);
        temp=front;
        front=front->link;
        free(temp);
    }
}

void queue_display()
{
    temp=front;
    printf("\n");
while(temp!=NULL)
    {
    printf("\t %d",temp->data);
    temp=temp->link;
    }
printf("\n");
}

void main()
{
int ch;
char ans;
do
{

printf("\n MENU");
printf("\n A.LINKED_STACK");
printf("\n 1.INSERT INTO STACK");
printf("\n 2.POP OUT OF STACK");
printf("\n 3.DISPLAY");
printf("\n B.LINKED_QUEUE");
printf("\n 4.INSERT INTO QUEUE");
printf("\n 5.POP OUT OF QUEUE");
printf("\n 6.DISPLAY");
printf("\n enter your choice");
scanf("%d",&ch);

if(ch==1)
{
    stack_in();
}
else if(ch==2)
{
    stack_out();
}
else if(ch==3)
{
    stack_display();
}
else if(ch==4)
{
    queue_in();
}
else if(ch==5)
{
    queue_out();
}
else if(ch==6)
{
    queue_display();
}

printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');

}