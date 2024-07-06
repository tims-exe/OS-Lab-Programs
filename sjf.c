#include<stdio.h>

struct pro{
	int id;
	int bt;
	int wt;
	int tat;
	int ct;
}p[20], temp;


void main(){
	float avg_wt = 0, avg_tat = 0;
	int n;
	
	printf("Enter number of processes : ");
	scanf("%d", &n);
	
	printf("Enter the burst time of each process : \n");
	for (int i = 0; i < n; i++){
		p[i].id = i+1;
		printf("P%d: ",i+1);
		scanf("%d", &p[i].bt);
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-i-1; j++){
			if (p[j].bt > p[j+1].bt){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	p[0].ct = p[0].bt;
	p[0].tat = p[0].ct;
	p[0].wt = 0;
	
	avg_wt += p[0].wt;
	avg_tat += p[0].tat;
	
	for (int i = 1; i < n; i++){
		p[i].ct = p[i-1].ct + p[i].bt;
		p[i].tat = p[i].ct;
		p[i].wt = p[i].tat - p[i].bt;
		
		avg_wt += p[i].wt;
		avg_tat += p[i].tat;
	}
	
	printf("\nProcess\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i = 0; i < n; i++){
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	
	printf("\nAverage Waiting Time : %f\n", avg_wt/n);
	printf("\nAverage Turnaround time : %f\n", avg_tat/n);
	
	printf("Gantt chart\n\n");
	printf("\n........................................................\n");
	for (int i = 0; i < n; i++){
		printf("|\tP%d\t|", p[i].id);
	}
	printf("\n........................................................\n");
	for(int i = 0; i < n; i++){
		printf("%d\t\t", p[i].wt);
	}
	
	printf("%d", p[n-1].tat);
	printf("\n........................................................\n");
	
}