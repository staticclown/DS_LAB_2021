#include<stdio.h>
int lim,val,arr[100];
char ans;
int i,j,flag=0,pos;
int low=0,high,mid;
void linear()
{
pos=0;
for(i=0;i<lim;i++)
{
if(arr[i]==val)
{
    flag=1;
    pos=i+1;
    break;
}
}
if(flag==0)
{
    printf("\n not found");

}
else if(flag==1)
{
printf("\n element found at %d",pos);
}

}

void binary()
{
high=lim;
low=0;


while(low<=high)
{
    mid=(low+high)/2;
    if(arr[mid]==val)
    {
        printf("\n element found at %d",mid+1);
        flag=1;
        break;

    }
    else if(arr[mid]>val)
    {
        high=mid-1;
    }
    else if (arr[mid]<val)
    {
        low=mid+1;
    }
    
}
if(flag==0)
{
    printf("\n element not found");
}

}



void main()
{int ch;
printf("\n enter the limit");
scanf("%d",&lim);
printf("enter the elements ");
for(i=0;i<lim;i++)
{
scanf("%d",&arr[i]);
}
do
{
printf("\n enter the value to search");
scanf("%d",&val);

printf("\n MENU");
printf("\n 1.LINEAR SEARCH");
printf("\n 2.BINARY SEARCH");
printf("\n enter your choice");
scanf("%d",&ch);

if(ch==1)
{
linear();
}
else if(ch==2)
{
binary();
}

printf("\n do you wish to continue");
scanf(" %c",&ans);
flag=0;

}while(ans=='y');
}