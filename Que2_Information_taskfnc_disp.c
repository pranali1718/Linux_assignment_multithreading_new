#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct information
{
	int Roll;
	int Marks;
	char Name[20];
	
};

void *fnc_task(void *arguments)
{
	printf("Here Is The Function Task\n");

	struct information *i = (struct information *)arguments;

	printf(" Roll No: %d \n Name: %s \n Marks: %d \t",i->Roll, i->Name, i->Marks);

	return NULL;
}

int main()
{
	struct information student;
    pthread_t threadid;

	student.Roll = 20;
	strcpy(student.Name, "Lavkesh K. T.");
	student.Marks = 69;

	pthread_create(&threadid, NULL, fnc_task, &student);
	pthread_join(threadid, NULL);

	pthread_exit(NULL);

	return 0;
}