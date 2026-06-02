#include <stdio.h>

struct Process {
    int at, bt, ct, wt, tat;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i=0;i<n;i++) {
        printf("Arrival Time P%d: ", i+1);
        scanf("%d",&p[i].at);

        printf("Burst Time P%d: ", i+1);
        scanf("%d",&p[i].bt);
    }

    int time=0;

    for(int i=0;i<n;i++) {
        if(time < p[i].at)
            time = p[i].at;

        p[i].wt = time - p[i].at;
        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;

        time = p[i].ct;
    }

    float awt=0, atat=0;

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);

        awt += p[i].wt;
        atat += p[i].tat;
    }

    printf("\nAverage WT = %.2f",awt/n);
    printf("\nAverage TAT = %.2f",atat/n);

    return 0;
}
