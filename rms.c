#include <stdio.h>

struct Process
{
    int id, bt, period, ct, wt, tat;
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

        printf("Period: ");
        scanf("%d",&p[i].period);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(p[j].period > p[j+1].period)
            {
                struct Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    int time=0;

    for(int i=0;i<n;i++)
    {
        p[i].wt=time;
        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct;
    }

    printf("\nID\tBT\tPeriod\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,p[i].bt,p[i].period,
               p[i].ct,p[i].wt,p[i].tat);
    }

    return 0;
}
