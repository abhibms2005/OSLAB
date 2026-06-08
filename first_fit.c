#include <stdio.h>

int main()
{
    int m,n;

    printf("Enter number of memory blocks: ");
    scanf("%d",&m);

    int block[m];

    printf("Enter block sizes:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int process[n];

    printf("Enter process sizes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&process[i]);

    int allocation[n];

    for(int i=0;i<n;i++)
        allocation[i]=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(block[j] >= process[i])
            {
                allocation[i]=j;
                block[j]-=process[i];
                break;
            }
        }
    }

    printf("\nProcess\tBlock\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t", allocation[i]);
    }

    return 0;
}
