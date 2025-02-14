#include <stdio.h>
struct process {
int index, bt, remaining_bt, wt, tat, ct;
};
void roundRobin(struct process p[], int n, int timeSlice, float *avgWT, float *avgTAT) {
int time=0, completed=0, totalWT=0, totalTAT=0;
while (completed<n) {
for (int i=0; i<n; i++) {
if (p[i].remaining_bt > 0) {
if (p[i].remaining_bt > timeSlice) {
time += timeSlice;
p[i].remaining_bt -= timeSlice;
} else {
time += p[i].remaining_bt;
p[i].remaining_bt = 0;
p[i].ct = time;
p[i].tat = p[i].ct;
p[i].wt = p[i].tat - p[i].bt;
totalWT += p[i].wt;
totalTAT += p[i].tat;
completed++;
}
}
}
}
*avgWT = (float)totalWT/n;
*avgTAT = (float)totalTAT/n;
}
void printGanttChart (struct process p[], int n, int timeSlice) {
int time=0, remaining_bt[n], processQueue[100], processTimes[100], queueIndex=0;
for (int i=0; i<n; i++) {
remaining_bt[i] = p[i].bt;
}
while (1) {
int done = 1;
for (int i=0; i<n; i++) {
if (remaining_bt[i] > 0) {
done = 0;
processQueue[queueIndex] = p[i].index;
processTimes[queueIndex++] = time;
if (remaining_bt[i] > timeSlice) {
time += timeSlice;
remaining_bt[i] -= timeSlice;
} else {
time += remaining_bt[i];
remaining_bt[i] = 0;
}
}
}
if (done) 
break;
}
processTimes[queueIndex] = time;
printf("\nGanttChart:\n|");
for (int i=0; i<queueIndex; i++) {
printf(" P%d |",processQueue[i]);
}
printf("\n");
for (int i=0; i<=queueIndex; i++) {
printf("%d ",processTimes[i]);
}
printf("\n");
}
void display(struct process p[], int n) {
printf("\nProcess\tBT\tWT\tTAT\tCT\n");
for(int i=0; i<n; i++) {
printf("P%d\t%d\t%d\t%d\t%d\n",p[i].index,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
}
}
int main() {
int n, timeSlice;
float avgWT, avgTAT;
printf("Enter the number of processes: ");
scanf("%d", &n);
struct process p[n];
printf("Enter the Burst time for each processes:\n");
for (int i=0; i<n; i++) {
printf("Process%d: ",i+1);
p[i].index = i+1;
scanf("%d", &p[i].bt);
p[i].remaining_bt = p[i].bt;
}
printf("Enter the time slice: ");
scanf("%d", &timeSlice);
roundRobin(p,n,timeSlice,&avgWT,&avgTAT);
display(p,n);
printGanttChart(p,n,timeSlice);
printf("\nAverage Waiting time: %.2f",avgWT);
printf("\nAverage Turn around time: %.2f\n",avgTAT);
return 0;
}