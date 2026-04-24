#include<stdio.h>
int main(){
int n; float avgwt =0,avgtat =0;
printf("Enter the number of processes: ");
scanf("%d",&n);
int bt[n],wt[n],tat[n];
printf("Enter the burst times for each of the processes: ");
for(int i=0;i<n;i++){
    scanf("%d",&bt[i]);
}
wt[0]=0;
for(int i=0;i<n;i++)
{
    printf("burst time of process %d = %d\n",i+1,bt[i]);
    wt[i] = wt[i-1]+bt[i-1];
}
for(int i=0;i<n;i++){
    tat[i] = wt[i]+bt[i];
    avgwt = avgwt+wt[i];
    avgtat = avgtat+tat[i];
}
for(int i=0;i<n;i++)
{
    printf("wait time of process %d = %d\n",i+1,wt[i]);
    printf("turn around time of process %d = %d\n",i+1,tat[i]);
}
    printf("average wait time = %.2f \n", avgwt/n);
    printf("average turn around time = %.2f", avgtat/n);
}
