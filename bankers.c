#include<stdio.h>
#include<stdlib.h>

int i, j, k, nop, nor, pid;
int maxAvail[10], alloc[10][10], max[10][10], need[10][10], work[10] = {0}, avail[10], req[10];

void display_table() {
    printf("\nProcess    Allocation      Max       Need ");		// Printing Table
	for ( i=0 ; i<nop ; i++ ){	
		printf("\nP%d         ",i);
		for( j=0 ; j<nor ; j++ )
			printf("  %d",alloc[i][j] );
		printf("   ");
		for( j=0 ; j<nor ; j++ )
			printf("  %d",max[i][j] );
		printf("  ");
		for( j=0 ; j<nor ; j++ )
			printf("  %d",need[i][j] );
	}
}


int safety(int arr[]) {
    printf("\n Sequence : ");
    int finish[10] = {0}, target = 0;
    for (k = 0; k < 10; k++) {
        for (i = 0; i < nop; i++) {
            if (finish[i] == 0) {
                int flag = 0;

                // need <= available check
                for (j = 0; j < nor; j++) {
                    if (need[i][j] > arr[j]) {
                        flag = 1;
                        break;
                    }
                }

                // above condition is true
                if (flag == 0) {
                    printf("P%d  ", i);
                    for (j = 0; j < nor; j++) {
                        arr[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    target++;
                }
            }
        }
    }

    if (target == nop) {
        return 1;
    }
    else {
        printf("\n Unsafe state \n");
    }
}


void request(){
    printf("Enter Process ID : ");
    scanf("%d", &pid);

    printf("Enter Resource Vector : ");
    for(j = 0; j < nor; j++) {
        scanf("%d", &req[j]);
    }
    for (i = 0; i < nor; i++) {
        if (req[i] > need[pid][i]) {
            printf("Process P%d Exceeded Maximum claim !!!\n",pid);
            exit(0);
        }
    }
    for (i = 0; i < nor; i++) {
        if (req[i] > avail[i]) {
            printf("Process P%d is Waiting for availailing Resource !!!\n",pid);
            exit(0);
        }
    }

    for (i = 0; i < nor; i++) {
        alloc[pid][i] += req[i];
        avail[i] -= req[i];
        need[pid][i] -= req[i];
    }

    int c = safety(avail);

    if (c) {
        printf("\nSystem is SAFE and Resources are Allocated\n");
    }
}


void main() {
    printf("Enter number of processes : ");
    scanf("%d", &nop);

    printf("Enter number of resources : ");
    scanf("%d", &nor);

    printf("Enter maximum available : ");
    for (i = 0; i < nor; i++) {
        scanf("%d", &maxAvail[i]);
    }

    printf("Enter allocation matrix : ");
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Max matrix : ");
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // calculate need matrix
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // calculate work from max available
    for (j = 0; j < nor; j++){
        for (i = 0; i < nop; i++) {
            work[j] += alloc[i][j];
        }
        work[j] = maxAvail[j] - work[j];
        avail[j] = work[j];
    }

    display_table();

    int c = safety(work);
    int ch;

    if (c) {
        printf("\n System is in safe state \n");
        printf("Do you need a Resource request ? ( Yes = 1, No = 0) : ");
        scanf("%d", &ch);
        if(ch){
            request();
        }
    }

}



// 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
// 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3


/*
5
4
12 12 8 10
2 0 0 1 3 1 2 1 2 1 0 3 1 3 1 2 1 4 3 2
4 2 1 2 5 2 5 2 2 3 1 6 1 4 2 4 3 6 6 5
1
1 1 0 0

*/