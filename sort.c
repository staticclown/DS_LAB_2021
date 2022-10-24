#include<stdio.h>
int i,j,lim,arr[100],input[100];
int temp;
int res[100],k=0,c[100];
void bubble()
{
for(i=0;i<lim;i++)
{
    for(j=0;j<lim-i-1;j++)
    {
        if(arr[j+1]<arr[j])
        {
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
}

for ( i =0;i<lim; i++)
{
printf("\t %d",arr[i]);

}
}

void insertion()
{

for(i=1;i<lim;i++)
{ temp=arr[i];
  j=i-1;
    while(j>=0 && temp<arr[j])
    {
        arr[j+1]=arr[j];
        j--;

    }
    arr[j+1]=temp;
}

for ( i = 0; i < lim; i++)
{
printf("\t %d",arr[i]);
}

}

void selection()
{
    int pos,temp1;
 for(i=0;i<lim;i++)
    {  
    temp=arr[i];
    pos=i;
    for(j=0;j<lim;j++)
    {
        if(temp<arr[j])
        {
            temp=arr[j];
            pos=j;
        }
    }
    temp1=arr[i];
    arr[i]=arr[pos];
    arr[pos]=temp1;
    }
for ( i = 0; i < lim; i++)
{
    printf("\t %d",arr[i]);
}

}

void quicksort(int arr[100],int p,int r)
{
if (p<r)
{
int pivot=arr[p];
i=p,j=r+1;
int d;
do
{
    do
    {
        i++;
    } while (arr[i]<=pivot);
    
    do
    {
        j--;
    } while (pivot<arr[j]);

    if(j>i)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
     for ( d= 0; d < lim; d++)
    {
    printf("\t %d",arr[d]);
    }
    printf("\n");
    
} while (j>i);

temp=arr[j];
arr[j]=arr[p];
arr[p]=temp;

quicksort(arr,p,j-1);
quicksort(arr,j+1,r);
}
}

void merge(int arr[100],int start,int mid,int end)
{int d;
    i=start;
    j=mid+1;

    while(i<=mid && j<=end)
    {
        
        if(arr[j]>arr[i])
        {
            res[k]=arr[i];
            k++;
            i++;
        }
        if(arr[i]>arr[j])
        {
            res[k]=arr[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid)
    {
        res[k++]=arr[i];
        i++;
        
    }
    
    
    while (j<=end)
    {
        res[k++]=arr[j];
        j++;
    }
    
     
    for(i=start,j=0;i<=end;i++,j++)
    {
        c[i]=res[j];
    }
    
}

void merge_sort(int arr[100],int start,int end)
{
int mid;
    if(start<end)
    {
        mid=(start+end)/2;
        merge_sort(arr,start,mid);
     
        merge_sort(arr,mid+1,end);
        
       
        merge(arr,start,mid,end);
    }

}


void main()
{int ch;
char ans;
printf("\n enter the limit");
scanf("%d",&lim);
printf("enter the elements ");
for(i=0;i<lim;i++)
{
scanf("%d",&input[i]);
}
do
{

for(i=0;i<lim;i++)
{
    arr[i]=input[i];
}

for ( i = 0; i < lim; i++)
{
printf("\t %d",arr[i]);
}

printf("\n MENU");
printf("\n 1.BUBBLE SORT");
printf("\n 2.INSERTION SORT");
printf("\n 3.SELECTION  SORT");
printf("\n 4.QUICK SORT");
printf("\n 5.MERGE SORT");
printf("\n enter your choice");
scanf("%d",&ch);

if(ch==1)
{
bubble();
}
else if(ch==2)
{
    insertion();
}
else if (ch==3)
{
    selection();
}
else if(ch==4)
{
    quicksort(arr,0,lim-1);
    for ( i = 0; i < lim; i++)
    {
    printf("\t %d",arr[i]);
    }

}
else if(ch==5)
{
merge_sort(arr,0,lim-1);
for ( i = 0; i < lim; i++)
    {
    printf("\t %d",c[i]);
    }
}

printf("\n do you wish to continue");
scanf(" %c",&ans);

}while(ans=='y');
}