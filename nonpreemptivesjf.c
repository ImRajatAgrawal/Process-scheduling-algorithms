//non-peemptive sjf
#include <stdio.h>
#include<stdlib.h>
 struct process{
	int pid;
	int arrival_time;
	int  burst_time;
};
typedef struct process pr;
void bubbleSort(pr p[], int n);
int main() 
{
	pr p[10];   
  	int limit,waiting_time[20],c,i,j,time,count=0;
  	int turnaround_time[20],end,temp[20];
  	float average_waiting_time=0, average_turnaround_time=0;
    printf("\n\tNON-PREEMPTIVE SJF SCHEDULING ALGORITHM:\n");
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &limit); 
    printf("\nEnter Details of %d Processes\n", limit);
    printf("\t\tPROCESS\t|\t    ARRIVAL-TIME  \t|    BURST-TIME ");
    printf("\n\t\t----------------------------------------------------------\n");
	for(i = 0; i < limit; i++){
        printf("\t\t  P%d",i+1);
        scanf("%d%d", &p[i].arrival_time,&p[i].burst_time); 
        temp[i]=p[i].burst_time;
        p[i].pid = i+1;
  	}	
   time=0;
   bubbleSort(p,limit);
	for(j=0;j<limit;){
		if(p[j].arrival_time<=time && p[j].burst_time>0){
			printf("P%d ",p[j].pid);
			time+=p[j].burst_time;
			p[j].burst_time=0;
			end=time;
			average_waiting_time = average_waiting_time + end - p[j].arrival_time - temp[j];
			average_turnaround_time = average_turnaround_time + end - p[j].arrival_time;
			j=0;	
		}
		else{
			j++;
		}
	}
	average_waiting_time/=limit;
	average_turnaround_time/=limit;
	printf("\n\nAverage Waiting Time:  %f\n", average_waiting_time);
	printf("Average Turnaround Time:   %f\n", average_turnaround_time);      
  return 0;
}
void bubbleSort(pr p[], int n){
   int i, j;
   pr temp;
   for (i = 0; i < n-1; i++)  {     
       for (j = 0; j < n-i-1; j++){ 
           if (p[j].burst_time > p[j+1].burst_time){
           		temp=p[j];
           		p[j]=p[j+1];
           		p[j+1]=temp;
           }
       }   
   }                   		
}
/*
OUTPUT:
	NON-PREEMPTIVE SJF SCHEDULING ALGORITHM:

Enter the Total Number of Processes:	5

Enter Details of 5 Processes
		PROCESS	|	    ARRIVAL-TIME  	|    BURST-TIME 
		----------------------------------------------------------
		  P1			0			10
		  P2			2			1
		  P3			3			2
		  P4			6			1
		  P5			7			5

Average Waiting Time:  5.800000
Average Turnaround Time:   9.600000
*/
