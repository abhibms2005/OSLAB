#include <stdio.h>

struct Process {
    int at, bt, pr, wt, tat, ct, done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++) {
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);

        p[i].done=0;
    }

    int completed=0,time=0;

    while(completed<n) {
        int idx=-1;
        int highest=9999;

        for(int i=0;i<n;i++) {
            if(p[i].at<=time && p[i].done==0) {
                if(p[i].pr<highest) {
                    highest=p[i].pr;
                    idx=i;
                }
            }
        }

        if(idx!=-1) {
            p[idx].wt=time-p[idx].at;
            p[idx].ct=time+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;

            time=p[idx].ct;
            p[idx].done=1;
            completed++;
        }
        else
            time++;
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,p[i].at,p[i].bt,p[i].pr,
               p[i].ct,p[i].wt,p[i].tat);
    }

    return 0;
}
