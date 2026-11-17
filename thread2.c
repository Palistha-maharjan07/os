#include<stdio.h>
#include<conio.h>
#include<pthread.h>
void *printMultiple(void *arg)
{
	int i, k;
	for(i= 1; i <= 50; i++)
	{
		k= i * 2;
		printf("Thread 1:%d\n", k);
		sleep(1);
	}
	pthread_exit(NULL);
}
void *printMultiples(void *arg)
{
	int i, k;
	char letters[]={'A', 'B', 'C', 'D', 'F'};
	for(i = 1; i <= 50; i++)
	{
		k= i * 3;
		printf("Thread 2: %d\n", k);
		sleep(1);
	}
	pthread_exit(NULL);
}
void *printOne(void *arg)
{
	int i, k;
	char letters[]={'A', 'B', 'C', 'D', 'F'};
	for(i = 1; i <= 50; i++)
	{
		k= i *1;
		printf("Thread 3: %d\n", k);
		sleep(1);
	}
	pthread_exit(NULL);
}
void main()
{
	pthread_t thread1, thread2, thread3;
	pthread_create(&thread1, NULL, printMultiple, NULL);
	pthread_create(&thread2, NULL, printMultiples, NULL);
	pthread_create(&thread3, NULL, printOne, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	getch();
}
