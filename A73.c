#include<stdio.h>
int main()
{
    int n,z;
    int v[5],sb=0;

    printf("Number of voters = ");
    scanf("%d",&n);

    for(int i=1;i<=5;i++)
    {
        v[i]=0;
    }

    printf("\n POLITICAL PARTY to vote \nPARTY 1 \nPARTY 2 \nPARTY 3 \nPARTY 4 \nPARTY 5 ");

    for(int i=1;i<=n;i++)
    {
        printf("\n Candidate %d",i);

        printf("\n Select the PARTY to vote = ");
        scanf("%d",&z);

        if(z>=1&&z<=5)
        {
            switch(z)
            {
                case 1: v[1]++;
                break;

                case 2: v[2]++;
                break;

                case 3: v[3]++;
                break;

                case 4: v[4]++;
                break;

                case 5: v[5]++;
                break;
            }
        }

        else
        {
            sb++;
        }

    }

    for(int i=1;i<=5;i++)
    {
        printf("\n Votes to PARTY %d = %d ",i,v[i]);
    }

    printf("\n Number of Spoilt Ballots = %d ",sb);

    return 0;
}