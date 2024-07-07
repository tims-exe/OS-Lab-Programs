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

void main() {
    int n, i = 0, ptr = 0, sum = 0;

    printf("Enter number of processes : ");
    scanf("%d", &n);

    struct process p[n];

    /* printf("Enter Arrival Time and Burst Time for Processes : \n");
    for (int i = 0; i < n; i++) {
        printf("P%d : ", i);
        p[i].id = i;
        scanf("%d%d", &p[i].at, &p[i].bt);
        sum += p[i].bt;
        p[i].cp_bt = p[i].bt;
    } */

    p[0].id = 0;
    p[0].at = 0;
    p[0].bt = 5;
    p[0].cp_bt = p[0].bt;
    p[1].id = 1;
    p[1].at = 2;
    p[1].bt = 4;
    p[1].cp_bt = p[1].bt;
    p[2].id = 2;
    p[2].at = 3;
    p[2].bt = 1;
    p[2].cp_bt = p[2].bt;
    p[3].id = 3;
    p[3].at = 5;
    p[3].bt = 2;
    p[3].cp_bt = p[3].bt;
    sum = p[0].bt + p[1].bt + p[2].bt + p[3].bt;

    sort(n, p);

    /* printf("|  P%d  |", p[i].id); */
    p[i].cp_bt--;
    ptr++;
    i++;

    while (ptr <= sum){
        // arrival time of current process is greater than pointer
        if (p[i].at > ptr){
            /* printf("|  P%d  |", p[i-1].id); */
            p[i-1].cp_bt--;
            ptr++;
        }
        else {
            for (int j = 0; j <= i; j++){
                if (p[j].cp_bt < p[])
            }
        }
    }
}