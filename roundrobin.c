#include<stdio.h>
#include<conio.h>
typedef struct
{
	int pid;
	int burst;
}process;
void turnaroundtime(process p[], int n, int waiting[], int turnaround[]){
	int i;
	for(i=0; i<n;i++)
		turnaround[i]=p[i].burst + waiting[i];
}
void waitingtime(process p[], int n, int waiting[], int quantum){
	int i, rem_bt[n];
	for(i=0; i<n;i++)
		rem_bt[i]=p[i].burst;
	int t=0;
	int flag;
	while(1){
		flag=1;
		for(i=0; i<n;i++){
			if(rem_bt[i]>0){
				flag=0;
				if(rem_bt[i]>quantum){
					t+=quantum;
					rem_bt[i]-=quantum;
				}
				else{
					t=t+rem_bt[i];
					waiting[i]=t-p[i].burst;
					rem_bt[i]=0;
				}
			}
		}
		if(flag==1)
			break;
	}
}
void calculateTime(process p[], int n, int quantum)
{
	int i, waiting[n], turnaround[n], totalwaiting=0, totalturnaround=0;
	waitingtime(p, n, waiting, quantum);
	turnaroundtime(p, n, waiting, turnaround);
	printf("Processs\tBurst time\twaiting time\tturnaround time\n");
	for(i=0; i<n; i++)
	{
		totalwaiting+= waiting[i];
		totalturnaround+=turnaround[i];
		printf("%d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].burst, waiting[i], turnaround[i] );
	}
	double averagewaiting=(double)totalwaiting/n;
	double averageturnaround=(double)totalturnaround/n;
	printf("\nAverage waiting time: %f", averagewaiting);
	printf("\nAverage turnaround time: %f", averageturnaround);
}
int main(){
	int i, n, quantum;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	process p[n];
	printf("Enter burst time:");
	for(i=0;i<n;i++){
		printf("process %d:\n", i+1);
		p[i].pid=i+1;
		printf("burst time: ");
		scanf("%d", &p[i].burst);
	}
	printf("Enter quantum size:");
	scanf("%d", &quantum);
	calculateTime(p,n, quantum);
	getch();
	return 0;
}


