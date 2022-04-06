#include<stdio.h>
#include<pthread.h>

static pthread_spinlock_t spin_lock;

void *thread1_func(void *arg)
{
	int x;
	printf("In The Thread1 Function\n");

	printf("Entering to The thread1 Spin Lock\n");
	pthread_spin_lock(&spin_lock);

	for(x=0; x<1000; x++)
		printf("Thread1 : %d\n",x*2);

	pthread_spin_unlock(&spin_lock);
	printf("Exiting From Thread1 Spinlock\n");

	printf("Exiting The Thread1\n");

	return NULL;
}

void *thread2_func(void *args)
{
	int x;
	printf("In thread2 function\n");

	printf("Entering thread2 spin lock\n");
	pthread_spin_lock(&spin_lock);

	for(x=0; x<1000; x++)
		printf("thread2: %d\n",x*5);

	pthread_spin_unlock(&spin_lock);
	printf("Exiting thread2 spinlock\n");

	printf("Exiting thread2\n");

	return NULL;
}

int main()
{
	pthread_t threadid1, threadid2;

	printf("In Main Thread: %ld\n",pthread_self());
	if(pthread_spin_init(&spin_lock, PTHREAD_PROCESS_PRIVATE) != 0)
		perror("Spin Init");

	pthread_create(&threadid1, NULL, thread1_func, NULL);
	pthread_create(&threadid2, NULL, thread2_func, NULL);

	pthread_join(threadid1, NULL);
	pthread_join(threadid2, NULL);

	printf("Exiting Main thread\n");

	return 0;
}