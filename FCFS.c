#include<stdio.h>
struct process{
    int at, bt, ct, tat, wt;
};
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(int i=0; i<n; i++){
        printf("Enter arrival time P%d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter burst time P%d: ", i+1);
        scanf("%d", &p[i].bt);
    }

    int time=0;
    for(int i=0; i<n; i++){
        if(time<p[i].at){
            time=p[i].at;
        }

            p[i].wt=time-p[i].at;
            p[i].ct=time+p[i].bt;
            p[i].tat=p[i].ct-p[i].at;

            time=p[i].ct;
        }
    

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    return 0;
}