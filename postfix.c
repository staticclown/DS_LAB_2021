#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char str[10];
int t=0,m=0;
char s[200][200];
char arr[100][200];
int top=-1;
int i=0,count=0,l;

char name[200][200];
int f[100];

int  priority(char p[20])
{
	if(strcmp(p,"^")==0)
	{
	
	return 3;
    }
    else if(strcmp(p,"*")==0||strcmp(p,"/")==0)
    {
    	return 2;
	}
    
	else if(strcmp(p,"+")==0||strcmp(p,"-")==0)
	{
	  return 1;	
	
	}
	else if(strcmp(p,"(")==0)
	{
		return 0;
	}
	
	
}

void check(char p[20])
{
	
  
  while(strcmp(arr[top],"(")!=0)
  { 
  	strcpy(s[i],arr[top]);
  	top=top-1;
  	i++;
  }

top=top-1;
}


void pop(char p[20])
{ int j,l1,l2;


	for(j=top;j>=0;j--)
	{ 
	  l1=priority(p);
	  l2=priority(arr[top]);
	if(l1<=l2)
	{
		strcpy(s[i],arr[j]);
		
		top=top-1;
		i++;
		
	}	
	
      }
}

void push(char p[20])
{
 
int l1,l2,flag=0;

	if(top==-1)
	{
	
		top=top+1;
		strcpy(arr[top],p);

    }
    
    else
    { l1=priority(p);
	  l2=priority(arr[top]);
    	if(l1<=l2)
    	{
    		pop(p);
    	top=top+1;
		 strcpy(arr[top],p);
		 
		}
		else
		{
			top=top+1;
		strcpy(arr[top],p);	
	
		}
			
	}

}


void op(char y[20])
{
  int s1,s2;
s1=f[t-1];
s2=f[t];
	if(strcmp(y,"+")==0)
	{
	
	f[t-1]=s1+s2;
	t--;
	
	}
	else if(strcmp(y,"-")==0)
	{ 
	f[t-1]=s1-s2;
	t--;
	
	}
	
	else if(strcmp(y,"*")==0)
	{  
	f[t-1]=s1*s2;
	t--;
	
	}
	else if(strcmp(y,"/")==0)
	{  
	f[t-1]=s1/s2;
	t--;
	
	}
	
	else if(strcmp(y,"^")==0)
	{  
	f[t-1]=pow(s1,s2);
	t--;
	
	}
}
	


void main()
{
	int lim,d,j=0,k=0,h,n;
	char ch[20],arr1[20],ans;
	int choice;
printf("\n enter the limit");
scanf("%d",&n);

	printf("\n enter the infix expression each character by character");
	
	for(d=0;d<n;d++)
{
  scanf("%s[^\n]",name[d]);
}

do
{
		
printf("\n **********************MENU*******************");
printf("\n 1.CONVERT INFIX TO POSTFIX");
printf("\n 2.EVALUATE THE EXPRESSION");
printf("\n ENTER YOUR CHOICE");
scanf("%d",&choice);

if(choice==1)
{


for(d=0;d<n;d++)
{  
	if((strcmp(name[d],"+")==0)||(strcmp(name[d],"-")==0)||(strcmp(name[d],"*")==0)||(strcmp(name[d],"/")==0)||(strcmp(name[d],"^")==0))
	{  
		
	push(name[d]);

		
	}
	
		else if(strcmp(name[d],"(")==0)
	{  top=top+1;
		strcpy(arr[top],"(");
	  m++;
	}
	else if(strcmp(name[d],")")==0)
	{ 
	   check(name[d]);
	m++;
	}
	
		else
	{		
		strcpy(s[i],name[d]);
		i++;    
	}
		count=count+1;
	
	}
	if(count==n)
	{
	
	for(j=top;j>=0;j--)
	{ strcpy(s[i],arr[j]);
		top=top-1;
		i++;
	}
     }
	

printf("\n final string is ");
for(d=0;d<n;d++)	
{

	printf(" %s",s[d]);
}



}

else if (choice==2)
{ char u[20];
int h;
printf("\n evaluation");

for(i=0;i<n-m;i++)
{  
	if((strcmp(s[i],"+")==0)||(strcmp(s[i],"-")==0)||(strcmp(s[i],"*")==0)||(strcmp(s[i],"/")==0)||(strcmp(s[i],"^")==0))
	{  
		
	op(s[i]);
	
	
		
	}
		else
	{
		t++;
		
	strcpy(u,s[i]); 	
        h=atoi(u);
        
	  f[t]=h;

         
	}

	}	
	
	printf(" \n value is %d",f[t]);
	
	
}
printf("\n do you wish to continue");
scanf(" %c",&ans);
}while(ans=='y'||ans=='Y');

}