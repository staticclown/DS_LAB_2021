#include<stdio.h>
#include<stdio.h>
int i,ch,arr[100];
int lim,front=-1,rear=-1;
char ans;

void in_rear()
{   int val;
    printf("\n enter the value to insert");
    scanf("%d",&val);

    if(rear==lim-1)
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
        rear+=1;
        arr[rear]=val;

    }

}

void out_front()
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
    front+=1;

}

}

void in_front()
{
    int val;
    printf("\n enter the value to insert");
    scanf("%d",&val);
if(front==0)
{
    printf("\n not possible to insert");
}
else if(front==-1)
{
    rear=0;
    front=0;
    arr[front]=val;
}
else
{
    front--;
    arr[front]=val;
}

}
void out_rear()
{

if(rear==-1)
{
    printf("\n nothing to delete");

}
else
{   printf("\n deleting value =%d",arr[rear]);
    rear=rear-1;


}

}

void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("\n %d",arr[i]);
    }

}



void main()
{
printf("enter the limit ");
scanf("%d",&lim);
do
{

printf("\n MENU");
printf("\n 1.INSERT USING REAR");
printf("\n 2.DELETE USING FRONT");
printf("\n 3.INSERT FROM FRONT");
printf("\n 4.DELETE FROM REAR");
printf("\n 5.DISPLAY");


printf("\n enter your choice");
scanf("%d",&ch);
if(ch==1)
{
in_rear();
}
else if(ch==2)
{
out_front();
}
else if(ch==5)
{
display();
}

else if(ch==3)
{

in_front();

}
else if(ch==4)
{

out_rear();
}
printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');

}