//preemptive priority
#include <stdio.h>
 struct proc{
	int pid;
	int arrival_time;
	int  burst_time;
	int priority;
};
typedef struct proc pr;
void bubbleSort(pr p[], int n);
void chart(int waiting_time[],int limit,int x,int k,int p[],int arr[]);
int main() {	
  pr p[20];
  int temp[10];
  int i,j=0,p1[20],t, smallest,process[200],count=0;
  int time, limit,waiting_time[20],arr[20],k,c;
  double wait_time = 0, turnaround_time = 0, end;
  float average_waiting_time, average_turnaround_time;
  printf("\n\tPREEMPTIVE PRIORITY SCHEDULING ALGORITHM:\n");
  printf("\nEnter the Total Number of Processes:\t");
  scanf("%d", &limit); 
  printf("\nEnter Details of %d Processes\n", limit);
  printf("\t\tPROCESS\t|\t    ARRIVAL-TIME  \t|    BURST-TIME  \t|    PRIORITY");
  printf("\n\t\t----------------------------------------------------------------------------\n");
	for(i = 0; i < limit; i++){
        printf("\t\t  P%d",i+1);
        scanf("%d%d%d", &p[i].arrival_time,&p[i].burst_time,&p[i].priority); 
        temp[i]=p[i].burst_time;
        p[i].pid = i+1;
  }
  bubbleSort(p,limit);
  p[9].priority = 9999;
  	for(time = 0; count != limit; time++){	
      smallest = 9;
      for(i = 0; i < limit; i++){
          if(p[i].arrival_time <= time && p[i].priority<p[smallest].priority && p[i].burst_time > 0){
            smallest = i;          
          }
      }
    	p[smallest].burst_time--;
    	process[j]=p[smallest].pid;
    	j++;
        if(p[smallest].burst_time == 0){
          count++;
          end = time + 1;
          wait_time = wait_time + end - p[smallest].arrival_time - temp[smallest];
          turnaround_time = turnaround_time + end - p[smallest].arrival_time;
        }
  } 
  average_waiting_time = wait_time / limit;
  average_turnaround_time = turnaround_time / limit;
  printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
  printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
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
			p1[t]=process[k-1];
			t++;
		}
	}
	p1[t]=process[k-1];
	arr[0]=waiting_time[0];
	for(i=0;i<=x;i++){
		arr[i+1]=waiting_time[i+1]-waiting_time[i];
	}
	printf("\n");	
 	printf("\nGANTT CHART:\n"); 		
	chart(waiting_time,limit,x,t,p1,arr);   
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
void chart(int waiting_time[],int limit,int x,int k,int p[],int arr[]){
int i,j,flag=0;
printf("\n");
printf(" ");
for(i=0; i<=x; i++){
	if(flag<1){
    	for(j=0; j<arr[i]+1; j++) printf("--");
    	printf(" ");
    	if(waiting_time[i]>=10){
    		flag++;
		}	
	}
	else{
			for(j=0; j<arr[i]+2; j++) printf("--");
    		printf(" ");
	}

}
 printf("\n|");
flag=0;
for(i=0; i<=x; i++) {
	if(flag<1){
    for(j=0; j<arr[i]; j++) printf(" ");
    printf("P%d",p[i]);
    for(j=0; j<arr[i]; j++) printf(" ");
    printf("|");
    if(waiting_time[i]>=10){
    	flag++;
    }
   }
   else{
		for(j=0; j<arr[i]+1; j++) printf(" ");
    printf("P%d",p[i]);
    for(j=0; j<arr[i]+1; j++) printf(" ");
    printf("|");
    
   }
    
}
printf("\n ");
flag=0;
for(i=0; i<=x; i++) {
	if(flag<1){
    for(j=0; j<arr[i]+1; j++) printf("--");
    printf(" ");
    if(waiting_time[i]>=10){
    	flag++;
    }
	}
	else{
		for(j=0; j<arr[i]+2; j++) printf("--");
		printf(" ");
	}
}
printf("\n0");
flag=0;
for(i=0; i<=x; i++) {
	if(flag<1){
    for(j=0; j<arr[i]; j++) printf(" ");
    printf("  ");   
    for(j=0; j<arr[i]; j++) printf(" ");
    printf("%d",waiting_time[i]);	
    	if(waiting_time[i]>=10)
    		flag++;
    }
    else{
		for(j=0; j<arr[i]+1; j++) printf(" ");
			printf(" ");   
    		for(j=0; j<arr[i]+1; j++) printf(" ");
    			printf("%d",waiting_time[i]);	    
    }
}        
printf("\n");
}		
/*
OUTPUT:
	PREEMPTIVE PRIORITY SCHEDULING ALGORITHM:

Enter the Total Number of Processes:	5

Enter Details of 5 Processes
		PROCESS	|	    ARRIVAL-TIME  	|    BURST-TIME  	|    PRIORITY
		----------------------------------------------------------------------------
		  P1			0			10      		3
		  P2			2			1			1
		  P3			3			2			3 
		  P4			6			1			4
		  P5			7			5			2


Average waiting time:	6.200000
Average Turnaround Time:	10.000000

GANTT CHART:
 ------ ---- ---------- ------------ ------------ -------- ------ 
|  P1  | P2 |    P1    |     P5     |     P1     |   P3   |  P4  |
 ------ ---- ---------- ------------ ------------ -------- ------ 
0      2    3          7            12           16       18     19
*/

 

