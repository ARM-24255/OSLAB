/*#include <stdio.h>
struct process {
    int p_id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int type;
};
void FCFS(struct process p[], int n, int start) {
    int time = start;
    for(int i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}
int main() {
    int n, sys_n = 0, user_n = 0;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    struct process sys[20], user[20], all[50];
    for(int i = 0; i < n; i++) {
        struct process p;
        printf("\nProcess %d\n", i + 1);
        printf("Enter arrival time,burst time and type: ");
        scanf("%d %d %d", &p.at, &p.bt, &p.type);
        p.p_id = i + 1;
        if(p.type == 1)
            sys[sys_n++] = p;
        else
            user[user_n++] = p;
    }
    FCFS(sys, sys_n, 0);
    int last_time = 0;
    if(sys_n > 0)
        last_time = sys[sys_n - 1].ct;
    FCFS(user, user_n, last_time);
    int k = 0;
    for(int i = 0; i < sys_n; i++)
        all[k++] = sys[i];
    for(int i = 0; i < user_n; i++)
        all[k++] = user[i];
    float total_wt = 0;
    float total_tat = 0;
    printf("\nFinal Schedule:\n");
    printf("PID\tType\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < k; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",all[i].p_id,(all[i].type == 1) ? "Sys" : "User",all[i].at,all[i].bt,all[i].ct,all[i].tat,all[i].wt);
        total_wt += all[i].wt;
        total_tat += all[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f",total_wt / k);
    printf("\nAverage Turnaround Time = %.2f\n",total_tat / k);
    return 0;
}*/
