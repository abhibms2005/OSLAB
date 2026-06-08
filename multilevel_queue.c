#include <stdio.h>

struct Process {
    int id, at, bt, ct, wt, tat, type;
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++) {
        p[i].id=i+1;

        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Type (0-System 1-User): ");
        scanf("%d",&p[i].type);
    }

    int time=0;

    for(int q=0; q<=1; q++ ){
        for(int i=0; i<n; i++){
            if (p[i].type==q){
                if(time<p[i].at){
                    time=p[i].at;
                }

                    p[i].ct=time+p[i].bt;
                    p[i].wt=time-p[i].at;
                    p[i].tat=p[i].ct-p[i].at;

                    time=p[i].ct;
            }
        }
    }

    printf("\nPID\tTYPE\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,p[i].type,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    }

    return 0;
}
