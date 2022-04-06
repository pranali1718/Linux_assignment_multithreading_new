#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t threadid;

	struct sched_param ssp;

	int scheduled_policy;

	pthread_getschedparam(pthread_self(), &scheduled_policy, &ssp);
	printf("Default: \t Policy: %d \t Priority: %d\n",scheduled_policy, ssp.sched_priority);

	scheduled_policy = SCHED_FIFO;
	ssp.sched_priority = 4;

	pthread_setschedparam(pthread_self(), scheduled_policy, &ssp);

	pthread_getschedparam(pthread_self(), &scheduled_policy, &ssp);
	printf("After Setting: \t Policy: %d \t Priority: %d\n",scheduled_policy, ssp.sched_priority);

	return 0;
}