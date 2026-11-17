#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int n, head, i;
    int totalManagement= 0;
    printf("Enter number of requests:");
    scanf("%d", &n);
    int request[n];
    printf("Enter the request queue:\n");
    for(i=0; i<n; i++)
    {
    	scanf("%d", &request[i]);
	}
	printf("Enter initial head position:");
	scanf("%d", &head);
	printf("%d", head);
	for(i= 0; i<n; i++)
	{
		totalManagement+= abs(head - request[i]);
		head= request[i];
		printf("->%d", head);
	}
	printf("\n\n Total Head Management= %d cylinders\n", totalManagement);
	printf("Average Head Management= %2f cylinders\n", (float) totalManagement);
	return 0;
}

