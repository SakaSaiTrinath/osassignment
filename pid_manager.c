#include<stdio.h>
#include<unistd.h>
#define MIN PID 100
#define MAX PID 1000
#define ARR_SIZE MAX_PID-MIN_PID+1

int pid_status[ARR_SIZE];

int allocate_map()  //creates and initializes a data structure for representing pids
{
	int i;
	for(i=0;i<ARR_SIZE;i++)
	{
		pid_status[i]=0;	//initializing pid statuses;
	}
}

int allocate_pid()  //allocates and returns a pid;
{
	int i;
	for(i=0;i<ARR_SIZE;i++)
	{
		if(pid_statuses[i]==0)		//checking for free pid.
		{
			pid_status[i]=1;	//changing status of pid.
			return i+100;		//returning pid.
		}
	}
}

void release_pid(int pid)  //releases a pid
{
	int pid=p-100;		//taking pid from passed parameter.
	pid_status[pid]=0;	//changing pid status.
	return 0;		//return status 0 to representing success.
}

void display()
{
	printf("\n[0] = %d\n",pid_status[0]);
}

int main()
{	
	allocate_map();
	printf("\nAfter allocate_map()");
	display();
	int pid1 = allocate_pid();
	printf("Allocated pid: %d\n",pid1);
	printf("After allocate_pid()\n");
	display();
	release_pid(pid1);
	printf("After release_pid()\n");
	display();
	printf("Program run successfully...\n");
	return 0;
}

