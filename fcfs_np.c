// FCFS (non pre-emptive)

#include<stdio.h>

struct process {
    int id, at, bt, ct, tat, wt;
};

void sort(int n, struct process p[n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (p[j].at > p[j+1].at){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void display(int n, struct process p[n], int avg_wt, int avg_tat){
    printf("\nProcess\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i = 0; i < n; i++){
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt );
	}    

    printf("\nAverage Waiting Time : %d\n", avg_wt/n);
	printf("\nAverage Turnaround time : %d\n", avg_tat/n);
	
	printf("Gantt chart\n\n");
	printf("\n...........................................................................................................\n");
	for (int i = 0; i < n; i++){
		if (p[i].at > p[i-1].ct){
			printf("|\t\t|");
		}
		printf("|\tP%d\t|", p[i].id);
	}
	printf("\n...........................................................................................................\n");
	printf("%d  \t\t", p[0].at);
	for(int i = 0; i < n; i++){	
		if (p[i].at > p[i-1].ct){
			printf("%d  \t\t", p[i].at);
		}
		printf("%d  \t\t", p[i].ct);	
	}
	printf("\n...........................................................................................................\n");
	
} 

void main() {
    int n;

    printf("Enter number of processes : ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter Arrival Time and Burst Time for Processes : \n");
    for (int i = 0; i < n; i++) {
        printf("P%d : ", i);
        p[i].id = i;
        scanf("%d%d", &p[i].at, &p[i].bt);
    }
    sort(n, p); 

    int ptr = 0, avg_wt = 0, avg_tat = 0;

    p[0].wt = 0;
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;

    ptr += p[0].ct;
    avg_wt += p[0].wt;
	avg_tat += p[0].tat;

    for (int i = 1; i < n; i++){
        if (p[i].at <= ptr){
            //printf("P%d : ptr = %d \n", i, ptr);
            p[i].ct = ptr + p[i].bt;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            ptr = p[i].ct;

            avg_wt += p[i].wt;
		    avg_tat += p[i].tat;
        }
    }
    display(n, p, avg_wt, avg_tat);
}



/*
Output

enter number of processes : 4

enter the burst time :
P1 : 4
P2 : 8
P3 : 3
P4 : 7

Process      Burst Time      Waiting Time      Turnaround Time
P3           3               0                 3
P1           4               3                 7
P4           7               7                 14
P2           8               14                22

Avg waiting time : 6.00
Ag Turnaround time : 11.50

Gantt Chart

|  P3  ||  P1  ||  P4  ||  P2  |
0      3        7      14      22

*/