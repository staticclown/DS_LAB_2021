
#include<stdio.h>

struct arr
{
	int coff;
	int exp;
	
}s1[100],s2[100],s3[100],s4[100];


void main()
{ int lim1,lim2,i,ch,j;
	
	printf("\n enter the limit of the first expression");
	scanf("%d",&lim1);
	printf("\n enter the limit for the second expression");
	scanf("%d",&lim2);
	
	printf("\n enter the elements of the first expression");
	
	for(i=0;i<lim1;i++)
	{
		printf("\n enter the coff of the exp");
		scanf("%d",&s1[i].coff);
		printf("\n enter the exponents of the exp");
		scanf("%d",&s1[i].exp);
	}
	
	
	printf("\n enter the elements of the second expression");
	
	for(i=0;i<lim2;i++)
	{
		printf("\n enter the coff of the exp");
		scanf("%d",&s2[i].coff);
		printf("\n enter the exponents of the exp");
		scanf("%d",&s2[i].exp);
	}
	
	printf("\n ***********menu*********");
	printf("\n 1.polynomial addition");
	printf("\n 2.polynomial multiplication");
	printf("\n enter the choice");
	scanf("%d",&ch);
	i=0,j=0;
	if(ch==1)
	{ int k=0;
		while(i<lim1 && j<lim2)
		{
		
		if(s1[i].exp==s2[j].exp)
		{
			s3[k].coff=s1[i].coff+s2[j].coff;
			s3[k].exp=s1[i].exp;
			k++;
			i++;
			j++;
				
			
		
		}
		
		else if(s1[i].exp>s2[j].exp)
		{
			s3[k].coff=s1[i].coff;
			s3[k].exp=s1[i].exp;
			k++;
			i++;
			
		}
		
		else if(s2[j].exp>s1[i].exp)
		{
			
			s3[k].coff=s2[j].coff;
			s3[k].exp=s2[j].exp;
			k++;
			j++;
			
			
		}
		
		
	}
		
		
	while(i<lim1)
	{
	     	s3[k].coff=s1[i].coff;
			s3[k].exp=s1[i].exp;
			k++;
			i++;
			
	}
	
	while(j<lim2)
	{
		    s3[k].coff=s2[j].coff;
			s3[k].exp=s2[j].exp;
			k++;
			j++;		
	}	
	
		printf("\n the 1st polynomial");
	for(i=0;i<lim1;i++)
	{	printf("%d(x^%d )+",s1[i].coff,s1[i].exp);
     }
     
     		printf("\n the 2nd polynomial");
	for(i=0;i<lim2;i++)
	{	printf("%d(x^%d )+",s2[i].coff,s2[i].exp);
     }
     
     printf("\n the added polynomial");
	for(i=0;i<k;i++)
	{
		printf("%d(x^%d )+",s3[i].coff,s3[i].exp);
		
		}	
		
		
	}
	else if(ch==2)
	{ int b=0,l;
		for(i=0;i<lim1;i++)
		{
			for(j=0;j<lim2;j++)
			{
				s4[b].coff=s1[i].coff*s2[j].coff;
				s4[b].exp=s1[i].exp+s2[j].exp;
			     b++;
			}
		}
		
		for(i=0;i<b;i++)
		{
			for(j=i+1;j<b;)
			{
				if(s4[i].exp==s4[j].exp)
				{
					s4[i].coff+=s4[j].coff;
				
				
				for(l=j;l<b;l++)
				{
					s4[l]=s4[l+1];
				}
				b--;
			}
			else
			{
				j++;
			}
		}
}
	printf("\n the added polynomial");
	for(i=0;i<b;i++)
	{
		printf("%d(x^%d )+",s4[i].coff,s4[i].exp);
		
		}	
	
}

}
