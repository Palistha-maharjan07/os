#include<stdio.h>
#include<conio.h>
typedef struct
{
	int pid;
	int brust;
}process;
void calculateTime(process p[], int n, int waiting[],int turnaround[])
{
	int i;
	waiting[0] = 0;
	for(i = 1; i < n; i++)
		waiting[i]= waiting[i-1]+p[i-1].brust;
	for(i = 0; i < n; i++)
		turnaround[i]= waiting[i] + p[i].brust;
}
void calculateAverage(process p[], int n)
{
	int i, waiting[n], turnaround[n];
	int totalwaiting = 0, totalturnaround= 0;
	calculateTime(p, n, waiting, turnaround);
	printf("Process\t Brust Time\t Waiting Time\t Turnaround Time\n ");
	for(i= 0; i < n; i++)
	{
		totalwaiting+= waiting[i];
		totalturnaround+= turnaround[i];
		printf("%d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].brust, waiting[i], turnaround[i]);
	}
	double averagewaiting= (double)totalwaiting/n;
	double averageturnaround= (double)totalturnaround/n;
	printf("\nAverage waiting time: %f", averagewaiting);
	printf("\nAverage turnaround time: %f", averageturnaround);
}
void main()
{
	int i, n;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	process p[n];
	printf("Enter brust time:");
	for(i= 0; i < n; i++)
	{
		printf("Process %d:\n", i+1);
		p[i].pid= i + 1;
		printf("brust time:");
		scanf("%d", &p[i].brust);
	}
	calculateAverage(p, n);
	getch();
}

