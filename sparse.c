#include<stdio.h>

void main()
{
	int i,j,mt1[100][100],mt2[100][100],mt3[100][100];
	int lim1,lim2;
	int i1,j1,k,k1;
	int temp;
	int l1,l2,l3;
	int ch,flag=0;
	int m3[100][100],m4[100][100],m5[100][100],m6[100][100];
	int count1,count2;
	int i2,j2,k2;
	int f=0;
        char ans;

    printf("\n enter the  row limit for the matrix");
	scanf("%d",&lim1);
	printf("\n enter the column limit for the matrix");
	scanf("%d",&lim2);
	
	printf("\n enter the elements of the matrix");
	for(i=0;i<lim1;i++)
	{
		for(j=0;j<lim2;j++)
		{
			printf("\n enter the element");
			scanf("%d",&mt1[i][j]);
		}
	}
	printf("\n entered element");
	for(i=0;i<lim1;i++)
	{ printf("\n");
		for(j=0;j<lim2;j++)
		{
			printf("%d ",mt1[i][j]);
		}
	}
       do
        {
	printf("\n ***********MENU***************");
	printf("\n 1.MATRIX TRANSPOSE");
	printf("\n 2.MATRIX ADDITIONN");
	printf("\n ENTER YOUR CHOICE ");
	scanf("%d",&ch);
	
	if(ch==1)
	{
		
	

	i1=1,j1=0,k=1;
	
	
	for (i=0;i<lim1;i++)
	{
		for(j=0;j<lim2;j++)
		{
			if(mt1[i][j]!=0)
			{
				mt2[i1][j1]=i;
				mt2[i1][j1+1]=j;
				mt2[i1][j1+2]=mt1[i][j];
				i1++;
				k++;
			}
			
		}
    }
    mt2[0][0]=lim1;
    mt2[0][1]=lim2;
    mt2[0][2]=k-1;
    
    printf("\n sparse matrix");
    for(i=0;i<i1;i++)
		{ printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d  ",mt2[i][j]);
			}
		}
		
		for(i=0;i<k;i++)
		{
			  temp=mt2[i][0];
			  mt2[i][0]=mt2[i][1];
			  mt2[i][1]=temp;
			
		}
		
	
	int h=k-1;
	//sorting
	
	for(i=0;i<h;i++)
	{
		for(j=0;j<h-i-1;j++)
		{ f=0;
			if(mt2[j+1][0]>mt2[j+2][0])
			{ 
			 while(f<3)
		     	{
			
			      temp=mt2[j+1][f];
				  mt2[j+1][f]=mt2[j+2][f];
				  mt2[j+2][f]=temp;
				  f++;
		       }   
			}
		}
	}
	printf("\n after sorting");
	
		for(i=0;i<i1;i++)
		{ printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d  ",mt2[i][j]);
			}
		}
		
		for(i=0;i<lim2;i++)
		{
			for(j=0;j<lim1;j++)
			{
				mt3[i][j]=0;
			}
		}
		
			for(i=1;i<k;i++)
		     { 
		       l1=mt2[i][0];
		       l2=mt2[i][1];
		       l3=mt2[i][2];
		       
		       mt3[l1][l2]=l3;
		   }
		printf("\n transpose");
		
		
		for(i=0;i<lim2;i++)
		{ printf("\n");
			for(j=0;j<lim1;j++)
			{
				printf("%d  ",mt3[i][j]);
			}
		}
	
	}
	
	else if(ch==2)
	{ int a1,a2,no,b1,b2,m;
	
	   printf("\n enter the second sparse matrix");
        printf("\n enter the row limit");
        scanf("%d",&a1);
        printf("\n enter the column limit");
        scanf("%d",&a2);
        if((lim1!=a1)||(lim2!=a2))
          {
          	printf("\n the no of rows and coloums should be same");
          	
          	flag=1;
          	
          }
     if(flag==0)
	 {
		       
		 printf("\n enter the no of non-zero numbers");
		 scanf("%d",&no);
	
	m4[0][0]=a1;
    m4[0][1]=a2;
    m4[0][2]=no;	
	i=1;
	
	while(i<=no)
	{
		printf("\n enter the non-zero value");
		scanf("%d",&m);
		printf("\n enter the row position of the no of non-zero element");
		scanf("%d",&b1);
		
		
		printf("\n enter the coloumn postion of the non-zero element");
		scanf("%d",&b2);
		m4[i][0]=b1;
		m4[i][1]=b2;
		m4[i][2]=m;
		i++;
	
	}


	printf("\n sparse matrix for first");
		i1=1,j1=0,k1=1;
	
	
	for (i=0;i<lim1;i++)
	{
		for(j=0;j<lim2;j++)
		{
			if(mt1[i][j]!=0)
			{
				m3[i1][j1]=i;
				m3[i1][j1+1]=j;
				m3[i1][j1+2]=mt1[i][j];
				i1++;
				k1++;
			}
			
			
		}
    }
    m3[0][0]=lim1;
    m3[0][1]=lim2;
    m3[0][2]=k1-1;
    

    
    
    
	 for(i=0;i<i1;i++)
		{ printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d  ",m3[i][j]);
			}
		}
		
	
		
printf("\n sparx matrix inputed ");
 for(i=0;i<=no;i++)
		{ printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d  ",m4[i][j]);
			}
		}



	printf("\n addition sparse matrix");
 i=1,j=1,k=1;     
 count1=m3[0][2];
 count2=m4[0][2];   
		 while(i<=count1 && j<=count2)	
         {
         	if(m3[i][0]<m4[j][0])
         	{  
         		m5[k][0]=m3[i][0];
         		m5[k][1]=m3[i][1];
         		m5[k][2]=m3[i][2];
         		k++;
         		i++;
         		
			 }
			 
			 else if(m3[i][0]>m4[j][0])
			 {
			    m5[k][0]=m4[j][0];
         		m5[k][1]=m4[j][1];
         		m5[k][2]=m4[j][2];
         		k++;
         		j++;
			 	
			 }
         	
         	else if((m3[i][0]==m4[j][0])&&(m3[i][1]<m4[j][1]))
			 { 
			 	m5[k][0]=m3[i][0];
         		m5[k][1]=m3[i][1];
         		m5[k][2]=m3[i][2];
         		k++;
         		i++;
			 	
			  }         	
         	else if((m3[i][0]==m4[j][0])&&(m3[i][1]>m4[j][1]))
			 { 
			    m5[k][0]=m4[j][0];
         		m5[k][1]=m4[j][1];
         		m5[k][2]=m4[j][2];
         		k++;
         		j++;
			 	
			 	
			  }         	
         	else if((m3[i][0]==m4[j][0])&&(m3[i][1]==m4[j][1]))
			 { 
			 	m5[k][0]=m4[j][0];
         		m5[k][1]=m4[j][1];
         		m5[k][2]=m4[j][2]+m3[i][2];
         		k++;
         		j++;
         		i++;
	      	  }         	
         	
         	
		 }
			  
		
	while(i<=count1)
	{
		        m5[k][0]=m3[i][0];
         		m5[k][1]=m3[i][1];
         		m5[k][2]=m3[i][2];
         		k++;
         		i++;
		
	}
	
	while(j<=count2)
	{
		        m5[k][0]=m4[j][0];
         		m5[k][1]=m4[j][1];
         		m5[k][2]=m4[j][2];
         		k++;
         		j++;
			 	
	}

	m5[0][0]=lim1;
	m5[0][1]=lim2;
	m5[0][2]=k-1;
	
	 for(i=0;i<k;i++)
		{ printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d  ",m5[i][j]);
			}
		}
	
	
	
	
		for(i=0;i<lim1;i++)
		{
			for(j=0;j<lim2;j++)
			{
				m6[i][j]=0;
			}
		}
		
			for(i=1;i<k;i++)
		     { 
		       l1=m5[i][0];
		       l2=m5[i][1];
		       l3=m5[i][2];
		       
		       m6[l1][l2]=l3;
		   }
		printf("\n addition of matrix");
		
		
		for(i=0;i<lim1;i++)
		{ printf("\n");
			for(j=0;j<lim2;j++)
			{
				printf("%d  ",m6[i][j]);
			}
       }
   }//flag
	}//if choice
  printf("\n do you wish to continue");
  scanf(" %c",&ans);
    }while(ans=='Y'||ans=='y');
}

