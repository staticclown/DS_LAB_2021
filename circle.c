#include<stdio.h>
int i,ch,arr[100];
int lim,front=-1,rear=-1;
char ans;

void in()
{   int val;
    printf("\n enter the value to insert");
    scanf("%d",&val);

    if(front==(rear+1)%lim)
    {
        printf("full");

    }
    else if(rear==-1 && front==-1)
    {
        rear=0;
        front=0;
        arr[rear]=val;
    }
    else
    {
        rear=(rear+1)%lim;
        arr[rear]=val;

    }

}

void out()
{

if(front==-1)
{
    printf("\n empty");

}
else if(front==rear)
{
printf("\n deleting value %d",arr[front]);
front=-1;
rear=-1;

}
else
{
    printf("\n deleting value %d",arr[front]);
    front=(front+1)%lim;

}

}

void display()
{
    i=front;
    while(i!=rear)
    {
    printf("\n %d",arr[i]);
    i=(i+1)%lim;
    }
    printf("\n %d",arr[i]);
}



void main()
{
printf("enter the limit ");
scanf("%d",&lim);
do
{

printf("\n MENU");
printf("\n 1.INSERT");
printf("\n 2.DELETE");
printf("\n 3.DISPLAY");


printf("\n enter your choice");
scanf("%d",&ch);
if(ch==1)
{
in();
}
else if(ch==2)
{
out();
}
else if(ch==3)
{
display();
}
printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');

}