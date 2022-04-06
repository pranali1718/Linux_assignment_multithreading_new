#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_once_t once_program = PTHREAD_ONCE_INIT;
void my_once()
{
	printf(" Here Is The Initialization of The code\n ");
}

void *thread_task(void *arg)
{
	printf(" In The Thread %d\n ",(int *)arg);
	pthread_once(&once_program , (void *)my_once);

	printf(" Exiting The thread %d\n ", (int *)arg);

	return NULL;
}

int main()
{
	pthread_t threadid1, threadid2, threadid3;
	pthread_create(&threadid1, NULL, thread_task, (void *)1);
	pthread_create(&threadid2, NULL, thread_task, (void *)2);
	pthread_create(&threadid3, NULL, thread_task, (void *)3);

	pthread_join(threadid1, NULL);
	pthread_join(threadid2, NULL);
	pthread_join(threadid3, NULL);

	return 0;
}