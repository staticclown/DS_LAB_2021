#include<stdio.h>
#include<stdlib.h>
int target,flag=0;
struct tnode
{
    int data;
    struct tnode *rc,*lc;

};

struct tnode * ptr,*par,*succ,*temp,*root=NULL;

struct tnode * insert(struct tnode * ptr,int val)
{
  if(ptr==NULL)
        {
        struct tnode *newn=(struct tnode *)malloc(sizeof(struct tnode));
        newn->data=val;
        newn->lc=NULL;
        newn->rc=NULL;
        ptr=newn;
        }
    else if(val<ptr->data)
    {
        ptr->lc=insert(ptr->lc,val);
    }
    else
        ptr->rc=insert(ptr->rc,val);
    return ptr;

}

void pre_order(struct tnode  * ptr)
{
    if(ptr!=NULL)
    {
        printf("\t %d ",ptr->data);
        pre_order(ptr->lc);
        pre_order(ptr->rc);

    }


}
void in_order(struct tnode *ptr)
{

     if(ptr!=NULL)
    {
        in_order(ptr->lc);
        printf("\t %d",ptr->data);
        in_order(ptr->rc);
    }

}

void post_order(struct tnode *ptr)
{

if(ptr!=NULL)
{   post_order(ptr->lc);
    post_order(ptr->rc);
    printf("\t %d",ptr->data);
}


}

void delete_tree(struct tnode *ptr)
{   while(ptr!=NULL)
    {
    if(ptr->data>target)
    {   par=ptr;
        ptr=ptr->lc;
        printf("\n greater ptr_data=%d",ptr->data);
    }
    else if(ptr->data<target)
    {   par=ptr;
        ptr=ptr->rc;
        printf("\n lesser  ptr_data=%d",ptr->data);
    }
    else if(ptr->data==target)
    {  
        if(ptr->lc==NULL && ptr->rc==NULL)
        {   printf("\n deleting an leaf node");    
            if(ptr==par->lc)
                    par->lc=NULL;
            else if(ptr==par->rc)
                    par->rc=NULL;
            free(ptr);
            return;
        }
        else if(ptr->lc!=NULL && ptr->rc==NULL)
        {
            printf("\n deleting a node with left child");
            if(ptr==par->lc)
            {   
                par->lc=ptr->lc;
            }
            else if(ptr==par->rc)
            {
                par->rc=ptr->lc;
            }
        }

        else if(ptr->lc==NULL && ptr->rc!=NULL)
        {
            printf("\n deleting a node with right child");
            if(ptr==par->lc)
            {
                par->lc=ptr->rc;
            }
            else if(ptr==par->rc)
            {
                par->rc=ptr->rc;
            }
            free(ptr);
            return;
        }
        else if(ptr->lc!=NULL &&ptr->rc!=NULL)
        {
            printf("\n deleting a node with 2 children");
            succ=ptr->rc;
            if(succ->lc==NULL)
            {
                ptr->data=succ->data;
                ptr->rc=succ->rc;
                free(succ);
            }
            else
            {
                while(succ->lc!=NULL)
                {
                    temp=succ;
                    succ=succ->lc;
                }
                ptr->data=succ->data;
                temp->lc=succ->rc;
                free(succ);
            }
            return;
        }
    }


    }
}

void search(struct tnode *ptr,int target)
{
flag=0;
while(ptr!=NULL)
{

if(ptr->data==target)
{
    flag=1;
    break;

}
else if(ptr->data>target)
{
    ptr=ptr->lc;
}
else 
{
    ptr=ptr->rc;
}

}

if(flag==1)
{
printf("\n found");
}
else
{
    printf("\n not found");
}


}


void main()
{
int ch,val;
char ans;
do
{

printf("\n MENU");
printf("\n 1.INSERT INTO TREE");
printf("\n 2.PREORDER TRAVERSAL");
printf("\n 3.INORDER TRAVERSAL");
printf("\n 4.POSTORDER TRAVERSAL");
printf("\n 5.DELETE A NODE");
printf("\n 6.SEARCH");
printf("\n enter your choice");
scanf("%d",&ch);

if(ch==1)
{   printf("\n enter the value to insert");
    scanf("%d",&val);

    root=insert(root,val);
}
else if(ch==2)
{
    pre_order(root);
}
else if(ch==3)
{
   in_order(root);
}
else if(ch==4)
{
    post_order(root);
}
else if (ch==5)
{
    printf("\n enter the value to delete");
    scanf("%d",&target);
    delete_tree(root);
}

else if(ch==6)
{
    printf("\n enter the vlaue to search");
    scanf("%d",&target);
    search(root,target);
}

printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');

}



