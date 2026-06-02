#include <stdio.h>

int main()
{
    int n,m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[n][m], request[n][m];
    int avail[m];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&request[i][j]);

    printf("Enter Available Resources:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&avail[i]);

    int finish[n];

    for(int i=0;i<n;i++)
        finish[i]=0;

    int count=0;

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
                    if(request[i][j] > avail[j])
                    {
                        possible=0;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j=0;j<m;j++)
                        avail[j]+=alloc[i][j];

                    finish[i]=1;
                    found=1;
                    count++;
                }
            }
        }

        if(!found)
            break;
    }

    if(count==n)
        printf("No Deadlock Detected\n");
    else
        printf("Deadlock Detected\n");

    return 0;
}
