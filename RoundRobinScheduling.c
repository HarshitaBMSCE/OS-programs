#include <stdio.h>
#include <limits.h>

int main()
{
    int n,i,time=0,qt=0;
    int at[20],bt[20],rt[20];
    int ct[20],wt[20],tat[20];
    int completed=0;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter time quantum: ");
    scanf("%d",&qt);

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i]=bt[i]; // remaining time
    }

    while(completed!=n)
    {
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0)
            {
                rt[i]-= qt;
                time+=qt;
            }
            else{
                time+= rt[i];
                completed++;

                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];

                    avgwt+=wt[i];
                    avgtat+=tat[i];
                }
            }
        }  
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);

    return 0;
}