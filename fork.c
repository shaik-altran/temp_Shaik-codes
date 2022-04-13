#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

void fork_function()
{
	fork();
	fork();
	printf("Welcome to fork function.It's pid is : %d\n",getpid());
	return NULL;
}


int main()
{
	printf("HI welcome to main function\n");
	fork_function();
}
