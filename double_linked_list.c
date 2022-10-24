
#include<stdio.h>
#include<stdlib.h>

int val;
struct node
{
    int data;
    struct node * rlink;
    struct node * llink;
    
};
struct node *newn,*temp,*start=NULL,*prev,*after;


void in_beg()
{
newn=(struct node *)malloc(sizeof(struct node));
printf("enter the value to insert");
scanf("%d",&val);

if(start==NULL)
{
    newn->llink=NULL;
    newn->rlink=NULL;
    newn->data=val;
    start=newn;
}
else
{
    newn->llink=NULL;
    newn->rlink=start;
    newn->data=val;
    start->llink=newn;
    start=newn;

}
}

void in_end()
{

newn=(struct node *)malloc(sizeof(struct node));
printf("enter the value to insert");
scanf("%d",&val);

if(start==NULL)
{
    newn->llink=NULL;
    newn->rlink=NULL;
    newn->data=val;
    start=newn;
}
else
{
    temp=start;

    while(temp->rlink!=NULL)
    {   
        temp=temp->rlink;

    }

    newn->rlink=NULL;
    newn->llink=temp;
    newn->data=val;
    temp->rlink=newn;

}


}


void in_spec()
{
    int pos;
newn=(struct node *)malloc(sizeof(struct node));
printf("enter the value to insert");
scanf("%d",&val);

printf("\n enter the value after which insert occur");
scanf("%d",&pos);

temp=start;
after=temp->rlink;
while(temp->data!=pos)
{   
    temp=temp->rlink;
    after=after->rlink;
}
newn->data=val;
newn->llink=temp;
newn->rlink=after;
temp->rlink=newn;
after->llink=newn;

}

void del_beg()
{

if(start==NULL)
{
    printf("empty");
}
else if(start->rlink==NULL && start->llink==NULL)
{
    printf("\n deleting value =%d",start->data);
    free(start);
    start=NULL;

}
else
{
    temp=start;
    start=start->rlink;
    start->llink=NULL;
    printf("\n deleting value =%d",temp->data);
    free(temp);
}

}

void del_end()
{
if(start==NULL)
{
    printf("empty");
}
else if(start->rlink==NULL && start->llink==NULL)
{
    printf("\n deleting value =%d",start->data);
    free(start);
    start=NULL;

}

else
{

temp=start;

while(temp->rlink!=NULL)
{   prev=temp;
    temp=temp->rlink;
}
printf("\n deleting value =%d",temp->data);
prev->rlink=NULL;
free(temp);


}

}


void del_spec()
{

 int pos;
printf("\n enter the value to delete");
scanf("%d",&pos);

if(start==NULL)
{
    printf("empty");
}

temp=start;

while(temp->data!=pos)
{     
    temp=temp->rlink;
}
printf("\n deleting value =%d",temp->data);
(temp->llink)->rlink=temp->rlink;
(temp->rlink)->llink=temp->llink;
free(temp);
}

void display()
{

temp=start;
printf("\n ");
while(temp!=NULL)
{   printf("\t %d",temp->data);
    temp=temp->rlink;
}

printf("\n ");
}

void main()
{

int ch;
char ans;
do
{

printf("\n MENU");
printf("\n 1.INSERT FROM BEG");
printf("\n 2.INSERT FROM END");
printf("\n 3.INSERT FROM SPECIFIED NODE");
printf("\n 4.DELETE FROM THE BEG");
printf("\n 5.DELETE FROM END");
printf("\n 6.DELETE FROM SPECIFIED NODE");
printf("\n 7.DISPLAY");
printf("\n enter your choice");
scanf("%d",&ch);

if(ch==1)
{
    in_beg();
}
else if(ch==2)
{
    in_end();
}
else if(ch==3)
{
    in_spec();
}
else if(ch==4)
{
    del_beg();
}
else if (ch==5)
{
    del_end();
}
else if (ch==6)
{
    del_spec();
}

else if (ch==7)
{
    display();
}


printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');

}