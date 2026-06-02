#include <stdio.h>

int main()
{
    int n,m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available Resources:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&avail[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    int finish[n];
    int safe[n];
    int count=0;

    for(int i=0;i<n;i++)
        finish[i]=0;

    while(count<n)
    {
        int found=0;

        for(int i=0;i<n;i++)
        {
            if(!finish[i])
            {
                int possible=1;

                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        possible=0;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j=0;j<m;j++)
                        avail[j]+=alloc[i][j];

                    safe[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count==n)
    {
        printf("Safe Sequence: ");
        for(int i=0;i<n;i++)
            printf("P%d ",safe[i]);
    }
    else
        printf("Unsafe State");

    return 0;
}
