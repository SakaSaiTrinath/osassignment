
#ifndef _pidmanager_h
#define _pidmanager_h

#include<stdio.h>
#include<unistd.h>
#define MIN_PID 100
#define MAX_PID 1000
#define ARR_SIZE MAX_PID-MIN_PID+1

int pid_status[ARR_SIZE];

int allocate_map()        //initializing pid statuses
{
  int i;
  for(i=0;i<ARR_SIZE;i++)
  {
    pid_status[i]=0;
  }
  return 0;               //return 0 indicating statuses have initialized.
}

int allocate_pid()
{
  int i;
  for(i=0;i<ARR_SIZE;i++)
  {
    if(pid_status[i]==0)   //checking if pid is free
    {
      pid_status[i]=1;     //changing status of pid
      return i+100;        //returning pid
    }
  }
  return 1;                //if pids are not free, 1 is returned indicating the same.
}

int release_pid(int p)
{
  int pid=p-100;            //taking pid from parameter.
  pid_status[pid]=0;        //changing pid status.
  
  if(pid_status[pid]==0)
    return 0;               //return status 0 to indicate pid is released successfully.
  else
    return 1;               //return 1 if unsuccessful.  
}

void display()
{
  int i;
  
  for(i=0;i<ARR_SIZE;i++)
  {
    printf("[%d] = %d\t",i+100,pid_status[i]);
  }
}

#endif
  
  
