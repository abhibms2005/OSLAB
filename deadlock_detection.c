#include<stdio.h>
int main(){
    int n,m;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter available resources: ");
    scanf("%d", &m);
    int allocation[n][m], request[n][m], available[m];
    printf("Enter Allocation Matrix: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter Request matrix: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &request[i][j]);
        }
    }
    printf("Enter Available Resources: ");
    for(int i=0; i<m; i++){
        scanf("%d", &available[i]);
    }
    int finish[n];
    for(int i=0; i<n; i++){
        finish[i]=0;
    }
    int count=0;
    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
           if (!finish[i]){
            int possible =1;
                for(int j=0; j<m; j++){
                    if(request[i][j]>available[j]){
                        possible=0;
                        break;
                    }    
                }
                if(possible){
                    for (int j=0; j<m; j++){
                        available[j]+=allocation[i][j];

                        found=1;
                        finish[i]=1;
                        count++;
                    }
                }
            }
        }
        if(!found){
                break;
            }
    }
    if (count == n){
        printf("No Deadlock Detected");
    } else {
        printf("Deadlock Detected");
    }
    return 0;
}