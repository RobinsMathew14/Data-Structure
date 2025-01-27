#include <stdio.h>
void findWaitingTime(int n,int bt[],int wt[])
{
    wt[0]=0;
    for (int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }
}
void findTurnAroundTime(int n,int bt[],int wt[],int tat[])
{
    for (int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}
void findAverageTime(int n,int bt[],int index[])
{
    int wt[n],tat[n];
    float total_wt=0,total_tat=0;
    findWaitingTime(n,bt,wt);
    findTurnAroundTime(n,bt,wt,tat);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n",index[i]+1,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time: %.2f",total_wt / n);
    printf("\nAverage turnaround time: %.2f",total_tat / n);
    printf("\n\nGantt Chart:\n");
    for (int i=0;i<n;i++)
    {
        printf("| P%d ",index[i]+1);
    }
    printf("|\n");
    printf("  0  ");
    for (int i=0;i<n;i++)
    {
        printf("   %d ",wt[i]+bt[i]);
    }
    printf("\n");
}
void sortProcesses(int n,int bt[],int index[]) {
    int temp;
    for (int i = 0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}
int main() 
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int bt[n],index[n];
    printf("Enter burst times for each process: \n");
    for (int i=0;i<n;i++)
    {
        index[i] = i;
        printf("Process %d: ",i+1);
        scanf("%d", &bt[i]);
    }

    // Print each process number and burst time separately
    printf("\nEntered burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", index[i] + 1, bt[i]);
    }

    sortProcesses(n, bt, index);
    findAverageTime(n, bt, index);
    printf("\n");
    return 0;
}
