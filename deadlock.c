#include<stdio.h>
#include<stdlib.h>

int nop, nor, i, j;
int alloc[10][10], req[10][10], avail[10], need[10][10];

int safety() {
    int finish[10] = {0}, target = 0;
    for (int k = 0; k < nop; k++) {
        for (i = 0; i < nop; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < nor; j++) {
                    // unlike bankers where u check need > available here u check request > available
                    // req matrix is inputted by the user
                    // dont calculate need matrix
                    if (req[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    finish[i] == 1;
                    target++;
                    for (j = 0; j < nor; j++) {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
    }
    if (target = nop) {
        return 1;
    }
    else {
        printf("\nUNSAFE\n");
    }
}

void main() {
    printf("Enter number of processes : ");
    scanf("%d", &nop);

    printf("Enter number of resources : ");
    scanf("%d", &nor);

    printf("Enter allocation matrix : ");
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Request matrix : ");
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            scanf("%d", &req[i][j]);
        }
    }

    // Prompt for the available matrix
    printf("Enter the Available Matrix : ");
    for (i = 0; i < nor; i++)
        scanf("%d", &avail[i]);

    //display_table();

    int c = safety();
    if (c)
        printf("\nSAFE\n");
}


/*
5
3
0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
0 0 0 2 0 2 0 0 0 1 0 0 0 0 2
0 0 0 
*/