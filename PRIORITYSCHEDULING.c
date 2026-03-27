/*#include<stdio.h>
int n,at[50],bt[50],ct[50],tat[50],wt[50],pid[50],priority[50],pcompleted[50];
int main(){
    printf("\nEnter the number of processes:");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("\nEnter arrival time for process %d:",i+1);
    scanf("%d",&at[i]);
    printf("\nEnter burst time for process %d:",i+1);
    scanf("%d",&bt[i]);
    printf("\nEnter the priority for process %d:",i+1);
    scanf("%d",&priority[i]);
    pid[i]=i+1;
    pcompleted[i]=0;
}
int current_time=0,completed=0;
while(completed<n){
        int max_p=-1;
    for(int i=0;i<n;i++){
        if(at[i]<=current_time && pcompleted[i]==0){
            if(max_p==-1 || priority[i]<priority[max_p]){
                max_p=i;
            }
        }
    }
        if(max_p==-1){
            current_time=current_time+1;
        }
        else{
            ct[max_p]=current_time+bt[max_p];
            tat[max_p]=ct[max_p]-at[max_p];
            wt[max_p]=tat[max_p]-bt[max_p];
            pcompleted[max_p]=1;
            current_time=ct[max_p];
            completed++;
        }

}
float sum_wt=0,sum_tat=0,avg_wt,avg_tat;
for(int i=0;i<n;i++){
    sum_tat=sum_tat+tat[i];
    sum_wt=sum_wt+wt[i];
}
avg_tat=sum_tat/n;
avg_wt=sum_wt/n;
printf("\nPID\tAT\tBT\tPriority\tCT\tWT\tTAT\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],priority[i],ct[i],wt[i],tat[i]);
}
printf("\nAverage TAT:%f",avg_tat);
printf("Average WT:%f",avg_wt);
return 0;
}
*/
