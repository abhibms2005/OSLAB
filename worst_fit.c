#include <stdio.h>

int main()
{
    int m,n;

    printf("Enter number of memory blocks: ");
    scanf("%d",&m);

    int block[m];

    for(int i=0;i<m;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int process[n];

    for(int i=0;i<n;i++)
        scanf("%d",&process[i]);

    int allocation[n];

    for(int i=0;i<n;i++)
        allocation[i]=-1;

    for(int i=0;i<n;i++)
    {
        int worst=-1;

        for(int j=0;j<m;j++)
        {
            if(block[j] >= process[i])
            {
                if(worst==-1 || block[j] > block[worst])
                    worst=j;
            }
        }

        if(worst!=-1)
        {
            allocation[i]=worst;
            block[worst]-=process[i];
        }
    }

    printf("\nProcess\tBlock\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",i+1);

        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
