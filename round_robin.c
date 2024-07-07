#include<stdio.h>

struct process {
    int id, at, bt, ct, tat, wt, cp_bt;
};

void sort(int n, struct process p[n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++){
           if (p[j].at > p[j+1].at){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void display(int n, struct process p[n]){
    printf("\nProcess\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i = 0; i < n; i++){
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt );
	}    
}

void main() {
    int n, tq, x = 1;

    printf("Enter number of processes : ");
    scanf("%d", &n);

    struct process p[n];
    struct process q[n*n], gc[n*n];
    int qf = -1, qr = -1, ptr = 0;

    printf("Enter Arrival Time and Burst Time for Processes : \n");
    for (int i = 0; i < n; i++) {
        printf("P%d : ", i);
        p[i].id = i;
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].cp_bt = p[i].bt;
    }

    printf("Enter Time Quantum : ");
    scanf("%d", &tq);

    sort(n, p);

    // if there are multiple processes with at = 0....use for loop to insert into ready queue

    // inserting first element into ready queue
    qf = 0;
    qr = 0;
    q[qr] = p[0];
    
    // insertion into gantt chart
    gc[ptr] = q[qf];
    if (q[qf].cp_bt <= tq){
        ptr += q[qf].cp_bt;
        q[qf].cp_bt -= tq;
        for (int i = 0; i < n; i++){
            if (q[qf].id == p[i].id){
                p[i].ct = ptr;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
            }
        }
    }
    else {
        ptr += tq;
        q[qf].cp_bt -= tq;
    }

    while (qf <= qr) {
        //check for pocesses to be inserted into qr
        // x : incrementer for processes
        while (x < n && p[x].at <= ptr){
            qr++;
            q[qr] = p[x];
            x++;
        }

        //check if process in gantt chart has finished execution...else add it to queue
        if (q[qf].cp_bt > 0) {
            qr++;
            q[qr] = q[qf];
        }

        // adding into gc
        qf++;
        gc[qf] = q[qf];

        // update pointer and cp_bt
        if (q[qf].cp_bt > tq) {
            q[qf].cp_bt -= tq;
            ptr += tq;
        }
        else {
            ptr += q[qf].cp_bt;
            q[qf].cp_bt -= tq;
            for (int i = 0; i < n; i++){
                if (q[qf].id == p[i].id){
                    p[i].ct = ptr;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
            }
        }
    }

    display(n, p);
}


/*
p[0].id = 0;
p[0].at = 0;
p[0].bt = 8;
p[0].cp_bt = p[0].bt;
p[1].id = 1;
p[1].at = 5;
p[1].bt = 2;
p[1].cp_bt = p[1].bt;
p[2].id = 2;
p[2].at = 1;
p[2].bt = 7;
p[2].cp_bt = p[2].bt;
p[3].id = 3;
p[3].at = 6;
p[3].bt = 3;
p[3].cp_bt = p[3].bt;
p[4].id = 4;
p[4].at = 8;
p[4].bt = 5;
p[4].cp_bt = p[4].bt;

*/