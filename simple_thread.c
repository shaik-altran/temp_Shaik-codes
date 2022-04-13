#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *thread_function()
{
	printf("In thread_function\n");
	printf("Process_id : %d\n",getpid());
}

int main(int argc,char **argv)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	printf("In main thread\n");

	pthread_create(&thread1, NULL, thread_function, NULL);
	pthread_create(&thread2, NULL, thread_function, NULL);
	pthread_create(&thread3, NULL, thread_function, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

}

	
