#include<stdio.h>
#include<stdlib.h>
int n;
int pid[50],at[50],bt[50],ct[50],tat[50],wt[50],current_time=0;

int main(){
    float sum_wt=0,sum_tat=0;
    float avg_wt,avg_tat;
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    printf("\nEnter the arrival time for the processes:");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("\nEnter the burst time for the processes:");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        pid[i]=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;
                int temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;
                int temp6=pid[i];
                pid[i]=pid[j];
                pid[j]=temp6;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }
        ct[i]=current_time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        current_time=ct[i];

    }

    for(int i=0;i<n;i++){
        sum_wt=sum_wt+wt[i];
    }
    avg_wt=sum_wt/n;
    for(int i=0;i<n;i++){
        sum_tat=sum_tat+tat[i];
    }
    avg_tat=sum_tat/n;
    for(int i=0;i<n;i++){
        printf("\nProcess Id:%d",pid[i]);
        printf("\nArrival time:%d",at[i]);
        printf("\nBurst time:%d",bt[i]);
        printf("\nCompletion time:%d",ct[i]);
        printf("\nWaiting time:%d",wt[i]);
        printf("\nTurnaround time:%d",tat[i]);
        printf("\n");
        printf("\n");
    }
    printf("\nAverage of Waiting time:%f",avg_wt);
    printf("\nAverage of Turnaround time:%f",avg_tat);
    return 0;
}

