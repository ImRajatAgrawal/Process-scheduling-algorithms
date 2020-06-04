//fcfs
#include <stdio.h>
#include<stdlib.h>
 struct process{
	int pid;
	int arrival_time;
	int  burst_time;
};
typedef struct process pr;
void chart(int waiting_time[],int limit,pr p[]);
void bubbleSort(pr p[], int n);

int main() 
{
   	pr p[10];   
	  int limit,waiting_time[20],c,i,j;
	  int turnaround_time[20];
	  float average_waiting_time=0, average_turnaround_time=0;
	  printf("\n\tFIRST COME FIRST SERVE SCHEDULING ALGORITHM:\n");
	  printf("\nEnter the Total Number of Processes:\t");
	  scanf("%d", &limit); 
	  printf("\nEnter Details of %d Processes\n", limit);
	  printf("\t\tPROCESS\t|\t    ARRIVAL-TIME  \t|    BURST-TIME ");
	  printf("\n\t\t----------------------------------------------------------\n");
	  
    for(i = 0; i < limit; i++){
        printf("\t\t  P%d",i+1);
        scanf("%d%d", &p[i].arrival_time,&p[i].burst_time); 
        p[i].pid = i+1;
     }	
    bubbleSort(p,limit);
    for(i=0;i<limit;i++){
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=p[j].burst_time;
    }
    waiting_time[i]=waiting_time[i-1]+p[j].burst_time;
    for(i=0;i<limit;i++){
        turnaround_time[i]=waiting_time[i+1]-p[i].arrival_time;
        average_waiting_time+=(turnaround_time[i]-p[i].burst_time);
        average_turnaround_time+=turnaround_time[i];
     }
    average_waiting_time/=i;
    average_turnaround_time/=i;
    printf("\n\nAverage Waiting Time:%f",average_waiting_time);
    printf("\nAverage Turnaround Time:%f",average_turnaround_time);
 printf("\n	GANTT CHART:\n");
 chart(waiting_time,limit,p); 
      return 0;
}
void bubbleSort(pr p[], int n){
   int i, j;
   pr temp;
   for (i = 0; i < n-1; i++)  {    
       for (j = 0; j < n-i-1; j++){ 
           if (p[j].arrival_time > p[j+1].arrival_time){
           		temp=p[j];
           		p[j]=p[j+1];
           		p[j+1]=temp;
           }
        }   
   }        
}
void chart(int waiting_time[],int limit,pr p[]){
	int i,j;
	printf("\n");
	printf(" ");
    for(i=0; i<limit; i++) {
        for(j=0; j<p[i].burst_time+1; j++) printf("--");
        printf(" ");
    }
     printf("\n|");
    
    for(i=0; i<limit; i++) {
        for(j=0; j<p[i].burst_time; j++) printf(" ");
        printf("P%d",p[i].pid);
        for(j=0; j<p[i].burst_time; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    
    for(i=0; i<limit; i++) {
        for(j=0; j<p[i].burst_time+1; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i=0; i<limit; i++) {
        for(j=0; j<p[i].burst_time; j++) printf(" ");
        printf(" ");
        for(j=0; j<p[i].burst_time; j++) printf(" ");
        printf("%d",waiting_time[i+1]);
    }
    printf("\n");
}
/*
OUTPUT:
FIRST COME FIRST SERVE SCHEDULING ALGORITHM:

Enter the Total Number of Processes:	5

Enter Details of 5 Processes
		PROCESS	|	    ARRIVAL-TIME  	|    BURST-TIME 
		----------------------------------------------------------
		  P1			0			10
		  P2			2			1
		  P3			3			2
		  P4			6			1
		  P5			7			5

Average Waiting Time:6.000000
Average Turnaround Time:9.800000
	GANTT CHART:

 ---------------------- ---- ------ ---- ------------ 
|          P1          | P2 |  P3  | P4 |     P5     |
 ---------------------- ---- ------ ---- ------------ 
0                     10   11     13   14           19

*/		

 

