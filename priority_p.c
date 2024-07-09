#include<stdio.h>
int main() {
    int n, p[10], at[10], bt[10], i, j, temp = 0, ct[10], wt[10], tat[10], flag = 0, si = 0, sp = 0, currtime = 0, tempbt[10], prio[10], executed[10];
    float atat = 0, awt = 0;
    printf("enter no of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("enter arrival time and burst time and priority:");
        scanf("%d%d%d", &at[i], &bt[i], &prio[i]);
    }
    for (i = 0; i < n; i++) 
    {
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
        tempbt[i] = bt[i];
    }
    while (flag < n)
   {
        sp = 9999;
        for (i = 0; i < n; i++) {
            if (at[i] <= currtime && bt[i] > 0 && prio[i] < sp) {
                sp = prio[i];
                 si = i;
            }
        }
        if (sp == 9999)
       {
            currtime++;
        }
        else
        {
            tempbt[si]--;
            if (tempbt[si] == 0) 
           {
                ct[si] = currtime + 1;
                tat[si] = ct[si] - at[si];
                wt[si] = tat[si] - bt[si];
                bt[si] = 0;
                executed[flag++] = si;
            }
            currtime++;
        }
    }
    for (i = 0; i < n; i++)
   {
        atat = atat + tat[i];
        awt = awt + wt[i];
    }
    printf("avg tat: %f\n", atat / n);
    printf("avg tat: %f\n", awt / n);
    printf("arrival \t burst \t completion \twaiting\t turnaround\n");
    for (i = 0; i < n; i++)
   {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], tempbt[i], ct[i], wt[i], tat[i]);
    }
    printf("gantt chart:\n");
    for (i = 0; i < n; i++) 
   {
        printf("|P%d|", p[i]);
    }
    printf("Gantt Chart:\n");
    printf("|");
    for (int i = 0; i < flag; i++) {
        printf("  P%d  |", executed[i] + 1);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", ct[i]);
    }
    printf("\n");
}