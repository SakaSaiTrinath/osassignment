#include<stdio.h>
#include<unistd.h>
#define MIN PID 100;
#define MAX PID 1000;
struct my_pid
{
	pid_t pidd;
	int status;
};

int allocate_map()  //creates and initializes a data structure for representing pids
{
}

int allocate_pid()  //allocates and returns a pid;
{
}

void release_pid(int pid)  //releases a pid
{
}

int main()
{	
	printf("Program run successfully...\n");
	return 0;
}

