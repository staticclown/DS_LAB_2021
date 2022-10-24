#include<stdio.h>
#include<stdlib.h>
int arr[100],lim;
int matrix[100][100],vist[100],rest[100],uniq[100];
int i,j,temp,sv;
int top=-1,front=-1,rear=-1,dfs_arr[100],bfs_arr[100];

struct tnode 
{
    int data;
    struct tnode *link;
};

struct tnode * start[100],*newn,*node_temp;


void insert(int val)
{
    newn=(struct tnode *)malloc(sizeof(struct tnode));
    if(start[i]==NULL)
    {
        newn->data=val;
        newn->link=NULL;
        start[i]=newn;

    }
    else
    {
        node_temp=start[i];
        while(node_temp->link!=NULL)
        {
            node_temp=node_temp->link;
        }
        node_temp->link=newn;
        newn->data=val;
        newn->link=NULL;
    }
}

void adj_list()
{ int node;
    for(i=0;i<lim;i++)
    {
        node=arr[i];
        insert(node);

        for(j=0;j<lim;j++)
        {
            if(matrix[node][arr[j]]==1)
            {
                insert(arr[j]);
            }
        }
    }
}

void display()
{
    for(i=0;i<lim;i++)
    {
        node_temp=start[i];
        printf("\n");
        while(node_temp!=NULL)
        {
            printf(" %d-> ",node_temp->data);
            node_temp=node_temp->link;
        }
    }
}

void in_bfs(int val)
{
if(front==-1 && rear==-1)
{
    front=0;
    rear=0;
    bfs_arr[rear]=val;
    
    
}
else
{
    rear=rear+1;
    bfs_arr[rear]=val;
}

}

int  out_bfs()
{
    if(front==rear)
    {   temp=bfs_arr[front];
        front=-1;
        rear=-1;
        return temp;

    }
    else
    {   temp=bfs_arr[front];
        front=front+1;
        return temp;
    }

}

void bfs()
{
    
while(rear!=-1)
{
    sv=out_bfs();

    printf("\t %d",sv);

    vist[sv]=1;
    

    for(i=0;i<lim;i++)
    {
        if(matrix[sv][arr[i]]==1 )
        {   if(uniq[arr[i]]==0)
            {   
            in_bfs(arr[i]);
            uniq[arr[i]]=1;
            }
        }
    }
    

}
for(i=0;i<lim;i++)
{
    if(vist[arr[i]]==0)
    {
        in_bfs(arr[i]);
        bfs();

    }
}

}

void in_dfs(int val)
{
    top=top+1;
    dfs_arr[top]=val;
}

int out_dfs()
{
    temp=dfs_arr[top];
    top=top-1;    
    return temp;
}

void dfs()
{

while(top!=-1)
{
    sv=out_dfs();

    printf("\t %d",sv);

    vist[sv]=1;
    

    for(i=0;i<lim;i++)
    {
        if(matrix[sv][arr[i]]==1 )
        {   if(uniq[arr[i]]==0)
            {   
            in_dfs(arr[i]);
            uniq[arr[i]]=1;
            }
        }
    }
    

}
for(i=0;i<lim;i++)
{
    if(vist[arr[i]]==0)
    {
        in_dfs(arr[i]);
        dfs();

    }
}


}

void view()
{
 printf("\n\t");
for(i=0;i<lim;i++)
{
    printf("\t %d",arr[i]);
}
printf("\n");

    for(i=0;i<lim;i++)
    {   printf("\t %d",arr[i]);
        for(j=0;j<lim;j++)
        {
            printf("\t %d",matrix[arr[i]][arr[j]]);
        }
    printf("\n");
    }
}

void indegree()
{
    int count[100],d=0;
    for(i=0;i<lim;i++)
    {
        count[i]=0;
    }

    for(i=0;i<lim;i++)
    {
        for(j=0;j<lim;j++)
        {
            if(matrix[arr[i]][arr[j]]==1)
            {
                count[d]+=1;
                
            }
            d++;
        }
        d=0;
    }

    for(i=0;i<lim;i++)
    {
        printf("\n %d \t %d",arr[i],count[i]);
    }
    
}

void outdegree()
{

    int count[100],d=0;
    for(i=0;i<lim;i++)
    {
        count[i]=0;
    }

    for(i=0;i<lim;i++)
    {
        for(j=0;j<lim;j++)
        {
            if(matrix[arr[j]][arr[i]]==1)
            {   
                count[d]+=1;
                
            }
            d++;
        }
        d=0;
    }

    for(i=0;i<lim;i++)
    {
        printf("\n %d \t %d",arr[i],count[i]);
    }
    

}

void main()
{
    int t,ch;
    char ans;
printf("\n enter the limit");
scanf("%d",&lim);
printf("\n enter the vetex of the graph");
for(i=0;i<lim;i++)
{
    scanf("%d",&arr[i]);
}

for(i=0;i<lim;i++)
{
    for(j=0;j<lim;j++)
    {
            printf("\n does there exists a edge b/w %d and %d (1-yes/0-no)",arr[i],arr[j]);
            scanf("%d",&t);
        matrix[arr[i]][arr[j]]=t;
    }
}


do
{
printf("\n MENU");
printf("\n 1.ADJANCENCY MATRIX");
printf("\n 2.INDEGREE OF All VERTEX");
printf("\n 3.OUTDEGREE OF All VERTEX");
printf("\n 4.BFS");
printf("\n 5.DFS");
printf("\n 6.ADJANCENCY LIST");
printf("\n ENTER YOUR CHOICE");
scanf("%d",&ch);

if(ch==1)
{
 view();  
}
else if(ch==2)
{
indegree();
}
else if(ch==3)
{
    outdegree();
}
else if(ch==4)
{   for(i=0;i<lim;i++)
    {
        vist[arr[i]]=0;
        uniq[arr[i]]=0;
    }
    uniq[arr[0]]=1;
    in_dfs(arr[0]);
    dfs();
}
else if(ch==5)
{
    for(i=0;i<lim;i++)
    {
        vist[arr[i]]=0;
        uniq[arr[i]]=0;
    }
    uniq[arr[0]]=1;
    in_bfs(arr[0]);
    bfs();

}
else if(ch==6)
{
adj_list();
display();

}
printf("\n do you wish to continue");
scanf(" %c",&ans);
}while(ans=='y');

}