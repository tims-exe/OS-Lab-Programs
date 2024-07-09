#include<stdio.h>

int i,j,n,flag,totalWT=0,totalTAT=0,proarr[20],noarr[20],ptr=-1;
int currentTime = 0, completed = 0, shortest = 0, minRemTime = 9999;

struct process{
    int num,TR;
    int AT,BT,CT,TAT,WT;
}pro[10],temp;

void main(){
    
    printf("Enter the Number of Process : ");
    scanf("%d",&n);
    
    printf("Enter Arrival Time and Burst Time of each process : \n");
    for ( i=0 ; i<n ; i++ ){
        printf("P%d\t",i+1);
        pro[i].num=(i+1);
        scanf("%d",&pro[i].AT);
        scanf("%d",&pro[i].BT);
        pro[i].TR=pro[i].BT;
    }

    while (completed != n) {
        for (int i = 0; i < n; i++){
            if ((pro[i].AT <= currentTime) && (pro[i].TR<minRemTime) && (pro[i].TR > 0)) {
                shortest = i;
                minRemTime = pro[i].TR;
            }
        }
 
        pro[shortest].TR--;
        minRemTime = pro[shortest].TR;

               
        if(proarr[ptr] != shortest || ptr==-1 ){
            ptr++;
            proarr[ptr]=shortest;
            noarr[ptr]=currentTime;
        }
        else
            noarr[ptr]++;
        
        if (minRemTime == 0)
            minRemTime = 9999;
        
        if (pro[shortest].TR == 0) {
            completed++;
            pro[shortest].CT = currentTime + 1;
            pro[shortest].TAT = pro[shortest].CT - pro[shortest].AT;
            pro[shortest].WT = pro[shortest].TAT - pro[shortest].BT;
            totalWT += pro[shortest].WT;
            totalTAT += pro[shortest].TAT;
        }
        currentTime++;
    }

    printf("\n\nGANTT CHART \n--------------------------------------------------------\n");
    for( i=0;i<=ptr;i++)
        printf("| P%d\t",proarr[i]+1);
        printf("|\n---------------------------------------------------------------\n%d\t",pro[0].AT);
    for(i=0;i<=ptr;i++)
        printf("%d\t",noarr[i]+1);
        printf("\n %15s %15s %15s %15s %15s%15s","Process","Arrival","Burst","Completion","TurnAround","Waiting");
        printf("\n-------------------------------------------------------------------------");
    for ( int i=0 ; i<n ; i++ )
        printf("\n P%d %13d %15d %15d %15d %15d", pro[i].num,pro[i].AT,pro[i].BT,pro[i].CT,pro[i].TAT,pro[i].WT);
    
    printf("\n\n Average Waiting Time : %.2f ms", (float)totalWT/n);
    printf("\n Average TurnAround Time : %.2f ms", (float)totalTAT/n);
}