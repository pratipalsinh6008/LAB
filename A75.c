#include<stdio.h>
int main()
{
    int i,j,k,l;
    int r[10],s1[10],s2[10],s3[10],tm[10];
    
    printf("Enter the student Roll No. and his marks in subjects = ");
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",&r[i]);
        scanf("%d",&s1[i]);
        scanf("%d",&s2[i]);
        scanf("%d",&s3[i]);
    }
    
    printf("/nDisplay of info = ");
    
    for(int i=0;i<10;i++)
    {
        printf("\n\n Roll No. = %d , \n His Marks in Subject 1 = %d , \n Marks in Subject 2 = %d , \n Marks in Subject 3 = %d",r[i],s1[i],s2[i],s3[i]);
        
        tm[i] = s1[i] + s2[i] + s3[i] ;
        
        printf("\n Total Marks of all Three subjects = %d , of Roll No. = %d ",tm[i],r[i]);
    }
    
    int max1=s1[0];
    
    for( int i=0;i<10;i++)
    {
        if(s1[i]>max1)
        {
            max1=s1[i];  
        }
        
    }

    for( i=0;i<10;i++)
    {
        if(s1[i]==max1)
        {
            break;
        }
    }

    printf("\n Maximum marks in Subject 1 = %d , by roll no. = %d",max1,r[i]);
    
    int max2=s2[0];
    
    for(int j=0;j<10;j++)
    {
        if(s2[j]>max2)
        {
            max2=s2[j]; 
        }
        
    }

    for( j=0;j<10;j++)
    {
        if(s2[j]==max2)
        {
            break;
        }
    }

     printf("\n Maximum marks in Subject 2 = %d , by roll no. = %d",max2,r[j]);
    
    int max3=s3[0];
    
    for(int k=0;k<10;k++)
    {
        if(s3[k]>max3)
        {
            max3=s3[k]; 
        }
        
    }

    for( k=0;k<10;k++)
    {
        if(s3[k]==max3)
        {
            break;
        }
    }

    printf("\n Maximum marks in Subject 3 = %d , by roll no. = %d",max3,r[k]);
    
    
    int maxt=tm[0];
    
    for(int l=0;l<10;l++)
    {
        if(tm[l]>maxt)
        {
            maxt=tm[l];
            
        }
        
    }

    for( l=0;l<10;l++)
    {
        if(tm[l]==maxt)
        {
            break;
        }
    }

    printf("\n Maximum Total marks  = %d , by roll no. = %d",maxt,r[l]);

    return 0;
    
}