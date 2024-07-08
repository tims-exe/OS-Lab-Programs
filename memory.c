#include<stdio.h>

struct process{
    int id, size, status, blk, blk_size, rem;
}p[50], b[50];


void first(int p_no, int b_no, struct process p[50], struct process b[50]){
    for (int i = 0; i < b_no; i++) {
        b[i].status = 0;
    }
    for (int i = 0; i < p_no; i++) {
        for (int j = 0; j <  b_no; j++) {
            if (p[i].size <= b[j].size && b[j].status == 0){
                p[i].blk = b[j].id;
                p[i].blk_size = b[j].size;
                p[i].status = 1;
                p[i].rem = b[j].size - p[i].size;
                b[j].status = 1;
                break;
            }
        }
    }
    printf("\nProcess\t\tSize\t\tBlock\t\tSize\t\tRemaining\n");
	for (int i = 0; i < p_no; i++){
		if (p[i].status == 1){
			printf("P%d\t\t%d\t\tB%d\t\t%d\t\t%d\n", p[i].id, p[i].size, p[i].blk, p[i].blk_size, p[i].rem);
		}
		else {
			printf("P%d\t\t%d\t\t-\t\t-\t\t-\n", p[i].id, p[i].size);
		}
        p[i].status = 0;
        p[i].blk = -1;
        p[i].blk_size = -1;
        p[i].rem = -1;
	}
}

void best(int p_no, int b_no, struct process p[50], struct process b[50]){
    // sorting blocks in ascending order
    for (int i = 0; i < b_no; i++){
        for (int j = 0; j < b_no-i-1; j++) {
            if (b[j].size > b[j+1].size){
                struct process temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
    first(p_no, b_no, p, b);
}

void worst(int p_no, int b_no, struct process p[50], struct process b[50]){
    // sorting blocks in descending order
    for (int i = 0; i < b_no; i++){
        for (int j = 0; j < b_no-i-1; j++) {
            if (b[j].size < b[j+1].size){
                struct process temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }
    first(p_no, b_no, p, b);
}


void main(){
	int p_no, b_no;
	
	printf("Enter number of processes and blocks : ");
	scanf("%d%d", &p_no, &b_no);
	
	printf("Enter Process size of : \n");
	for (int i = 0; i < p_no; i++){
		printf("P%d : ", i);
		p[i].id = i;
		scanf("%d", &p[i].size);
	}
	
	printf("Enter Block size of : \n");
	for (int i = 0; i < b_no; i++){
		printf("B%d : ", i);
		b[i].id = i;
		scanf("%d", &b[i].size);
	}
	printf("\n\nFirst Fit");
	first(p_no, b_no, p, b);
	printf("\n\nBest Fit");
	best(p_no, b_no, p, b);
	printf("\n\nWorst Fit");
	worst(p_no, b_no, p, b);
}