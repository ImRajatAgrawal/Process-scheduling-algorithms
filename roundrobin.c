//round robin
#include <stdio.h>
#include<stdlib.h>
 struct process{
	int pid;
	int arrival_time;
	int  burst_time;
	int completed;
	int temp;
	int waiting_time;
	int turnaround_time;
};
typedef struct process pr;
int isempty_q(int queue[],int front,int rear);;
void insert_q(int queue[],int *front,int *rear,int key);
int delete_q(int queue[],int *front,int *rear);
void initialize_q(int queue[],int *front,int *rear);
void chart(int [],int limit,int x,int p[],int tq);
void bubbleSort(pr p[], int n);
int isInQueue(int i,int q[],int front,int rear);
int main(){
   	  pr p[10];   
      int limit,i,j,tq,m,sumbt=0,k=0,c=0,wt[100];
      int time,q[200],front,rear,proc[100];
      float average_waiting_time=0, average_turnaround_time=0;
      printf("\n\tROUND ROBIN SCHEDULING ALGORITHM:\n");
      initialize_q(q,&front,&rear);
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processes\n", limit);
      printf("\nEnter time quantum:");
      scanf("%d",&tq);
      printf("\t\tPROCESS\t|\t    ARRIVAL-TIME  \t|    BURST-TIME ");
      printf("\n\t\t----------------------------------------------------------\n");
    	for(i = 0; i < limit; i++){
            printf("\t\t  P%d",i+1);
            scanf("%d%d", &p[i].arrival_time,&p[i].burst_time); 
            p[i].pid = i+1;
            p[i].temp=p[i].burst_time;
			 p[i].completed=0;
 			sumbt+=p[i].burst_time;
      	}	
      	bubbleSort(p,limit);
  	  	insert_q(q,&front,&rear,0);
      	for(time=p[0].arrival_time;time<sumbt;){ 	
      		m=delete_q(q,&front,&rear);
    		if(p[m].temp<=tq){ 
			  time+=p[m].temp; 
			  proc[k]=p[m].pid;
			  k++;
			  wt[c]=time;
			  c++;
			  p[m].temp=0; 
			  p[m].completed=1;
              p[m].waiting_time=time-p[m].arrival_time-p[m].burst_time;
              p[m].turnaround_time=time-p[m].arrival_time; 
			  for(j=0;j<limit;j++){
            	if(p[j].arrival_time<=time && p[j].completed!=1&& isInQueue(j,q,front,rear)!=1){
            		insert_q(q,&front,&rear,j);
           
            	}
           	 }
		   }  
		   else{ 
			  	p[m].temp-=tq; 
			  	time+=tq;
			  	proc[k]=p[m].pid;
			  	k++;
			  	wt[c]=time;
			  	c++;
			  	for(j=0;j<limit;j++){
           		 if(p[j].arrival_time<=time && p[j].completed!=1&&m!=j&& isInQueue(j,q,front,rear)!=1){
           				 insert_q(q,&front,&rear,j); 
            		}
           		}
           		insert_q(q,&front,&rear,m);		
			 }
	  }			  
	for(i=0;i<limit;i++){
		average_waiting_time+=p[i].waiting_time;
		average_turnaround_time+=p[i].turnaround_time;
	}
	printf("\nAverage waiting time:%f",average_waiting_time/limit);
    printf("\nAverage Turnaround Time:%f",average_turnaround_time/limit);
    printf("\n	GANNT CHART:\n");
 	chart(wt,limit,k-1,proc,tq);    
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
int isInQueue(int i,int q[],int front,int rear){
	int k;
	for(k=front;k<=rear;k++){
		if(q[k]==i)
			return 1;
	}
	return 0;
}
void insert_q(int queue[],int *front,int *rear,int key){
	*rear+=1;
	queue[*rear]=key;
	if(*front==-1)
		*front=0;
	return;
}
int delete_q(int queue[],int *front,int *rear){
	int key;
	key=queue[*front];
		if(*front==0 && *rear==0)
			*front=*rear=-1;
		else
			*front=(*front)+1;
	return key;
}
void initialize_q(int queue[],int *front,int *rear){
	*front=-1;
	*rear=-1;
}
int isempty_q(int queue[],int front,int rear){
	if(front==-1)
		return 1;
	return 0;
}
void chart(int waiting_time[],int limit,int x,int p[],int tq){
int i,j,flag=0;
printf("\n");
printf(" ");
for(i=0; i<=x; i++){
	if(flag<1){
    	for(j=0; j<tq+1; j++) printf("--");
    	printf(" ");
    	if(waiting_time[i]>=10){
    		flag++;
		}	
	}
	else{
			for(j=0; j<tq+2; j++) printf("--");
    		printf(" ");
	}

}
 printf("\n|");
flag=0;
for(i=0; i<=x; i++) {
	if(flag<1){
    for(j=0; j<tq; j++) printf(" ");
    printf("P%d",p[i]);
    for(j=0; j<tq; j++) printf(" ");
    printf("|");
    if(waiting_time[i]>=10){
    	flag++;
    }
   }
   else{
		for(j=0; j<tq+1; j++) printf(" ");
    printf("P%d",p[i]);
    for(j=0; j<tq+1; j++) printf(" ");
    printf("|");
    
   }
    
}
printf("\n ");
flag=0;
for(i=0; i<=x; i++) {
	if(flag<1){
    for(j=0; j<tq+1; j++) printf("--");
    printf(" ");
    if(waiting_time[i]>=10){
    	flag++;
    }
	}
	else{
		for(j=0; j<tq+2; j++) printf("--");
		printf(" ");
	}
}
printf("\n0");
flag=0;
for(i=0; i<=x; i++){
	if(flag<1){
    for(j=0; j<tq; j++) printf(" ");
    printf("  ");   
    for(j=0; j<tq; j++) printf(" ");
    printf("%d",waiting_time[i]);	
    	if(waiting_time[i]>=10)
    		flag++;
    }
    else{
		for(j=0; j<tq+1; j++) printf(" ");
			printf(" ");   
    		for(j=0; j<tq+1; j++) printf(" ");
    			printf("%d",waiting_time[i]);	    
    }
}        
printf("\n");
}		
/*
ROUND ROBIN SCHEDULING ALGORITHM:

Enter the Total Number of Processes:	6

Enter Details of 6 Processes

Enter time quantum:2
		PROCESS	|	    ARRIVAL-TIME  	|    BURST-TIME 
		----------------------------------------------------------
	      P1			    0					4
		  P2			    1					5
		  P3			    2					2
		  P4			    3					1
		  P5			    4					6
		  P6			    6					3

Average waiting time:7.333333
Average Turnaround Time:10.833333
	GANNT CHART:
 ------ ------ ------ ------ ------ ------ -------- -------- --------  
|  P1  |  P2  |  P3  |  P1  |  P4  |  P5  |   P2   |   P6   |   P5   | 
 ------ ------ ------ ------ ------ ------ -------- -------- --------  
0      2      4      6      8      9      11       13       15       17
 -------- -------- --------
|   P2   |   P6   |   P5   |
 -------- -------- -------- 
17       18       19       21
*/
 

