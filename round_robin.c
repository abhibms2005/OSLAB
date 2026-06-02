#include <stdio.h>

struct Process {
    int at, bt, rt, ct, wt, tat;
};

int main() {
    int n,tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++) {
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        p[i].rt=p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int complete=0,time=0;

    while(complete<n) {
        int done=1;

        for(int i=0;i<n;i++) {
            if(p[i].rt>0) {
                done=0;

                if(p[i].rt>tq) {
                    time+=tq;
                    p[i].rt-=tq;
                }
                else {
                    time+=p[i].rt;
                    p[i].ct=time;
                    p[i].rt=0;

                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;

                    complete++;
                }
            }
        }

        if(done)
            break;
    }

    printf("\nPID\tBT\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               i+1,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    }

    return 0;
}
