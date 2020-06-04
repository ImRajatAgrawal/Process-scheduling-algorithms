//preemptive sjf
#include <stdio.h>
void chart(int waiting_time[],int limit,int x,int k,int pid[],int p[],int arr[]);
int main(){

  int arrival_time[10], burst_time[10], temp[10];
  int i,j=0,p[20],t, smallest,pid[10],process[200],count=0;
  int time, limit,waiting_time[20],k,c,arr[20],wt[20],y;
  double wait_time = 0, turnaround_time = 0, end;
  float average_waiting_time, average_turnaround_time;

  printf("\n\t\tPREEMPTIVE SJF SCHEDULING ALGORITHM:\n");
  printf("\nEnter the Total Number of Processes:\t");

  scanf("%d", &limit); 

  printf("\nEnter Details of %d Processes\n", limit);
  printf("\t\tPROCESS\t|\t    ARRIVAL-TIME  \t|    BURST-TIME ");
  printf("\n\t\t----------------------------------------------------------\n");

  for(i = 0; i < limit; i++){
    printf("\t\t  P%d",i+1);
    scanf("%d%d", &arrival_time[i],&burst_time[i]); 
    temp[i] = burst_time[i];
    pid[i] = i+1;
  }

  burst_time[9] = 9999;

  for(time = 0; count != limit; time++){	
    smallest = 9;
    for(i = 0; i < limit; i++){
          if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0){
                smallest = i;
               
          }
    }
    
    burst_time[smallest]--;
    	process[j]=pid[smallest];
    	j++;
    
    if(burst_time[smallest] == 0){
          count++;
          end = time + 1;
          wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
          wt[smallest]=wait_time;
          turnaround_time = turnaround_time + end - arrival_time[smallest];
    }
}
	average_waiting_time = wait_time / limit; 
	average_turnaround_time = turnaround_time / limit;
	printf("\n\nAverage Waiting Time:  %lf\n", average_waiting_time);
	printf("Average Turnaround Time:   %lf\n", average_turnaround_time);
	for(y=0;y<limit;y++){
		printf("%d\n",wt[y]);
	}
	int x=0;
	c=1;
	t=0;
	for(k=1;k<j;k++){
		if(process[k]==process[k-1]){
			c++;
			waiting_time[x]=c;
		}
		else{
			x++;
			c++;
			waiting_time[x]=c;
			p[t]=process[k-1];
			t++;
		}
	}
	p[t]=process[k-1];
	arr[0]=waiting_time[0];
	for(i=0;i<=x;i++){
		arr[i+1]=waiting_time[i+1]-waiting_time[i];
	}
	printf("\n");	
    printf("\nGANTT CHART:\n"); 		
    chart(waiting_time,limit,x,t,pid,p,arr);       
  return 0;
}

//Gannt chart visualization
void chart(int waiting_time[],int limit,int x,int k,int pid[],int p[],int arr[]){
	int i,j;
	printf("\n");
	printf(" ");
    for(i=0; i<=x; i++) {
        for(j=0; j<arr[i]+1; j++) printf("--");
        printf(" ");
    }
     printf("\n|");
    for(i=0; i<=x; i++) {
        for(j=0; j<arr[i]; j++) printf(" ");
        printf("P%d",p[i]);
        for(j=0; j<arr[i]; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<=x; i++) {
        for(j=0; j<arr[i]+1; j++) printf("--");
        printf(" ");
    }
    printf("\n0");
    for(i=0; i<=x; i++) {
        for(j=0; j<arr[i]; j++) printf(" ");
        printf("  ");   
        for(j=0; j<arr[i]; j++) printf(" ");
        printf("%d",waiting_time[i]);
    }
    printf("\n");
    }
/*
OUTPUT:
PREEMPTIVE SJF SCHEDULING ALGORITHM:
Enter the Total Number of Processes:	5
Enter Details of 5 Processes
		PROCESS	|	    ARRIVAL-TIME  	|    BURST-TIME 
		----------------------------------------------------------
		  P1			0			10
		  P2			2			1
		  P3			3			2
		  P4			6			1	
		  P5			7			5

Average Waiting Time:  1.800000
Average Turnaround Time:   5.600000


GANTT CHART:
 ------ ---- ------ ---- ---- ------------ ---------------- 
|  P1  | P2 |  P3  | P1 | P4 |     P5     |       P1       |
 ------ ---- ------ ---- ---- ------------ ---------------- 
0      2    3      5    6    7            12               19
*/		

 

