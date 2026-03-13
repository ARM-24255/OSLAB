#include<stdio.h>

int main() {
    int n, at[50], bt[50], pid[50];
    int ct[50], wt[50], tat[50], pcompleted[50];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        pid[i] = i+1;
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
        pcompleted[i] = 0;
    }

    int current_time = 0, completed = 0;

    while(completed < n){
        int min_bt = 9999, index = -1;

        for(int i=0;i<n;i++){
            if(at[i] <= current_time && pcompleted[i] == 0){
                if(bt[i] < min_bt){
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index == -1){
            current_time++;
        }
        else{
            ct[index] = current_time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            current_time = ct[index];
            pcompleted[index] = 1;
            completed++;
        }
    }

    float sum_wt = 0, sum_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %f", sum_wt/n);
    printf("\nAverage Turnaround Time: %f", sum_tat/n);

    return 0;
}
