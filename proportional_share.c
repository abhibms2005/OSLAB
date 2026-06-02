#include <stdio.h>

struct Process
{
    int id, bt, share, ct, wt, tat;
};

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Share: ");
        scanf("%d",&p[i].share);
    }

    int time=0;

    for(int i=0;i<n;i++)
    {
        p[i].wt=time;
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct;
    }

    printf("\nID\tBT\tShare\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,p[i].bt,p[i].share,
               p[i].ct,p[i].wt,p[i].tat);
    }

    return 0;
}
