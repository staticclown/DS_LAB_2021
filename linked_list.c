#include<stdio.h>
#include<stdlib.h>
int val,ch,pos;
struct node
{
    int data;
    struct  node * link;
    
};
struct node *start=NULL,*after,*prev;
struct node *newn,*temp;
void insert_beg()
{
newn=(struct node *)malloc(sizeof(struct node));
printf("\n enter the value to be inserted");
scanf("%d",&val);

if(start==NULL)
{
    start=newn;
    start->data=val;
    start->link=NULL;
}

}

void insert_end()
{
newn=(struct node *)malloc(sizeof(struct node));
printf("\n enter the value to be inserted");
scanf("%d",&val);

temp=start;
while(temp->link!=NULL)
{
    temp=temp->link;
}
newn->data=val;
temp->link=newn;
newn->link=NULL;
}
void insert_spec()
{
newn=(struct node *)malloc(sizeof(struct node));
printf("\n enter the value to be inserted");
scanf("%d",&val);
printf("\n enter the value after insertion occur");
scanf("%d",&pos);
temp=start;
after=temp->link;
while(temp->data!=pos)
{    
    temp=temp->link;
    after=after->link;
}
newn->data=val;
temp->link=newn;
newn->link=after;

}

void del_beg()
{
    temp=start;
    printf("\n deleting value %d",temp->data);
    start=start->link;
    free(temp);
}

void del_end()
{
    temp=start;
    while(temp->link!=NULL)
    {   prev=temp;
        temp=temp->link;
    }
    printf("deleting value %d",temp->data);
    prev->link=NULL;
    free(temp);
}

void del_sep()
{
    printf("\n enter the specific  value to be deleted");
    scanf("%d",&val);
    temp=start;
    after=temp->link;
    while(temp->data!=val)
    {   prev=temp;
        temp=temp->link;
        after=after->link;
    }
    printf("\n deleting value =%d",temp->data);
    prev->link=after;
    free(temp);


}

void display()
{
temp=start;


while(temp!=NULL)
{   printf("\n %d ",temp->data);
    temp=temp->link;
}




}

void main()
{
char ans;
do
{
    

printf("\n MENU");
printf("\nINSERTION");
printf("\n1.INSERT AT THE BEG" );
printf("\n2.INSERT AT THE END");
printf("\n3.INSERT AFTER SPECIFICED NODE");
printf("\nDELETION");
printf("\n4.DELETE FROM THE BEGINNING");
printf("\n5.DELETE FROM THE END" );
printf("\n6.DELETE A SPECIFIED NODE");
printf("\n7.DISPLAY");
printf("\n enter the choice");
scanf("%d",&ch);
if(ch==1)
{
 insert_beg();   
}
else if(ch==2)
{
insert_end();
}
else if(ch==3)
{
insert_spec();
}
else if(ch==4)
{
del_beg();

}
else if (ch==5)
{
del_end();
}
else if(ch==6)
{
del_sep();
}
else if(ch==7)
{
    display();
}

printf("\n do you wish to continue");
scanf(" %c",&ans);
}while(ans=='y');


}