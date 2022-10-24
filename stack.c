#include<stdio.h>
int arr[100];
int lim,top=-1;
int ch,i;
char ans;

void in()
{
int val;
printf("\n enter the value to insert");
scanf("%d",&val);

if(top==lim-1)
{
    printf("full");
}
else
{
top+=1;
arr[top]=val;
}

}

void out()
{

if(top==-1)
{
    printf("empty");
}
else
{
    printf("\n deleting value %d",arr[top]);
    top-=1;
}

}

void display()
{

for(i=0;i<=top;i++)
{
    printf("\n %d ",arr[i]);
}

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