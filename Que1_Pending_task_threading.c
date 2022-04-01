#include<stdio.h>
#include<pthread.h>

void *t_fnc(void *arg)
{
	printf(" Into The Thread Function\n ");

	for(int i = 0 ; i < 100 ; i++)
		printf(" Here The Value Of i is: %d\n ", i );

	printf(" Now EXit From The Thread.\n ");
}

int main()
{
	pthread_t threadid;
	int set=0;

	pthread_create(&threadid, NULL, t_fnc, NULL);
	pthread_join(threadid, NULL);
	pthread_exit(NULL);
	printf(" Terminating the Main Thread\n ");

	return 0;
}