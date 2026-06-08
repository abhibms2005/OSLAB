#include<stdio.h>
struct process {
    int at, bt, ct, pr, wt, tat, done;
};
int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(int i=0; i<n; i++){
        printf("Enter Arrival Time P%d: ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time P%d: ", i+1);
        scanf("%d", &p[i].bt);
        printf("Enter priority: ");
        scanf("%d", &p[i].pr);

        p[i].done=0;
    }

    int completed=0; int time=0;
    while(completed<n){
        int idx=-1;
        int highest=9999;

        for(int i=0; i<n; i++){
            if(p[i].at<=time && p[i].done==0){
                if (p[i].pr<highest){
                    highest=p[i].pr;
                    idx=i;
                }
            }
        }

        if(idx!=-1){
            p[idx].wt=time-p[idx].at;
            p[idx].ct=time+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;

            time=p[idx].ct;
            p[idx].done=1;
            completed++;
        }
        else{
            time++;
        }
        
    }
    printf("PID\tAT\tBT\tCT\tPR\tWT\tTAT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", i+1,p[i].at, p[i].bt, p[i].ct,p[i].pr, p[i].wt, p[i].tat);
    }
    return 0;
}