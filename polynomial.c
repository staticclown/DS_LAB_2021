#include<stdio.h>
#include<stdlib.h>

// program to implement polynomial addition and multiplication using linked list

int lim1,lim2,i,j;
int e1,c1,e2,c2;
int flag=0;
struct node
{
    int exp;
    int coff;
    struct node *link;
    
};
struct node * start1=NULL;
struct node * start2=NULL;
struct node * temp=NULL,*temp1,*temp2,*temp3;
struct node *newn,*prev;
struct node *multi;
struct node * insert_value(struct node * start,int coff,int exp)
{

newn=(struct node *)malloc(sizeof(struct node ));

if(start==NULL)
{
    start=newn;
    start->coff=coff;
    start->exp=exp;
    start->link=NULL;
     return start;
}

else
{
    temp=start;

    while(temp->link!=NULL)
    {
        temp=temp->link;

    }
    newn->coff=coff;
    newn->exp=exp;
    temp->link=newn;
    newn->link=NULL;

    return start;

}


}


void display(struct node * start)
{

temp=start;

while(temp!=NULL)
{
    printf("%dx^%d + ",temp->coff,temp->exp);
    temp=temp->link;
}

printf("\n");

}


void add_polynomial()
{
int temp_coff,temp_exp;
temp1=start1;
for(i=0;i<lim1;i++)
{
    temp2=start2;
    while(temp2!=NULL)
    {
    
        if(temp1->exp==temp2->exp)
        {
            temp_coff=temp1->coff+temp2->coff;
            temp_exp=temp1->exp;
            temp=insert_value(temp,temp_coff,temp_exp);
            flag=1;
            break;
        }
    temp2=temp2->link;
    }
    if(flag==0)
    {
    temp_coff=temp1->coff;
    temp_exp=temp1->exp;
    temp=insert_value(temp,temp_coff,temp_exp);


    }

    flag=0;
    temp1=temp1->link;
}

temp2=start2;
while(temp2!=NULL)
{
    temp3=temp;
    while(temp3!=NULL)
    {
        if(temp3->exp==temp2->exp)
        {   flag=1;
            
            break;
        }
        temp3=temp3->link;
    }
    if(flag==0)
    {
        temp=insert_value(temp,temp2->coff,temp2->exp);
    }
    flag=0;
    temp2=temp2->link;


}

}

void multi_polynomail()
{
int temp_coff,temp_exp;
temp1=start1;
for(i=0;i<lim1;i++)
{
    temp2=start2;
    for(j=0;j<lim2;j++)
    {
        temp_coff=temp1->coff*temp2->coff;
        temp_exp=temp1->exp+temp2->exp;
        multi=insert_value(multi,temp_coff,temp_exp);
    
        temp2=temp2->link;
    }

    temp1=temp1->link;
}

display(multi);

temp1=multi;
start1=temp1;
while(temp1!=NULL)
{   prev=temp1;
    temp2=temp1->link;

    while(temp2!=NULL)
    {
        if(temp1->exp==temp2->exp)
        {  
            temp1->coff=temp1->coff+temp2->coff;
            prev->link=temp2->link;
            temp2=temp2->link;
                        
        }
        else{
        temp2=temp2->link;
        prev=prev->link;
        }
    }
    temp1=temp1->link;
}


}



void main()
{

    printf("enter the limit of the polynomial ");
    scanf("%d",&lim1);
    printf("enter the details of the first polynomial");

    for(i=0;i<lim1;i++)
    {

    printf("\n enter the coffeicent value");
    scanf("%d",&c1);
    
    printf("\n enter the exponent value");
    scanf("%d",&e1);
    start1=insert_value(start1,c1,e1);

    
    }

printf("\n enter the details of the second polynomial");
printf("\n enter the limit of the polynomial ");
scanf("%d",&lim2);
    for(i=0;i<lim2;i++)
    {

    printf("\n enter the coffeicent value");
    scanf("%d",&c2);
    
    printf("\n enter the exponent value");
    scanf("%d",&e2);
    start2=insert_value(start2,c2,e2);

    }


    printf("\n for 1st polynomial: ");
    display(start1);

    printf("\n for 2nd polynomial: ");
    display(start2);
    add_polynomial();
    printf("\n the polynomial after addition is : ");
    display(temp);

    multi_polynomail();
    printf("\n the polynomial after multiplication  is : ");
    display(start1);   

}