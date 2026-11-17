#include<stdio.h>
#include<conio.h>
#include<pthread.h>
void *printNumbers(void *arg)
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("Thread 1:%d\n", i);
		sleep(1);
	}
	pthread_exit(NULL);
}
void *printLetters(void *arg)
{
	int i;
	char letters[]={'A', 'B', 'C', 'D', 'F'};
	for(i = 0; i < 5; i++)
	{
		printf("Thread 2: %c\n", letters[i]);
		sleep(1);
	}
	pthread_exit(NULL);
}
void main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, printNumbers, NULL);
	pthread_create(&thread2, NULL, printLetters, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	getch();
}
