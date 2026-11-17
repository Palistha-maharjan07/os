#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, head, i, j;
	int totalMovement= 0;
	printf("Enter number of requests: ");
	scanf("%d", &n);
	int request[n];
	int visited[n];
	printf("Enter the request queue:\n");
	for (i= 0; i < n; i++)
	{
		scanf("%d", &request[i]);
		visited[i]= 0;
	}
	printf("Enter initial head position:");
	scanf("%d", &head);
	printf("\nSSTF service sequence:\n");
	printf("%d", head);
	for(i= 0; i < n; i++)
	{
		int minDistance= 9999;
		int index= -1;
		for(j= 0; j < n; j++)
		{
			if(visited[j]==0)
			{
				int distance= abs(head - request[j]);
				if(distance < minDistance)
				{
					minDistance= distance;
					index= j;
				}
			}
		}
		visited[index]= 1;
		totalMovement+= abs(head - request[index]);
		head= request[index];
		printf("->%d", head);
	}
	printf("\n\nTotal Head Movement= %d cylinders\n", totalMovement);
	printf("Average Head Movement= %.2f cylinders\n",(float) totalMovement);
	return 0;
}
