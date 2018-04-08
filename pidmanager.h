/*
  This file is a header file which defines the pidmanager.
  
  allocate_map() function initializes the pid statuses.
  allocate_pid() function returns a free pid from the data structure and changes the status of that pid to 1 on calling from a thread, 
    otherwise i.e., if no pid is free, it returns 1.
  release_pid() function takes back the pid on calling from the thread. i.e., it changes the pid status of that pid back to 0.
  display() function shows all the pids which are in use when it is called.
*/

#ifndef _pidmanager_h
#define _pidmanager_h

#include<stdio.h>
#include<unistd.h>
#define MIN_PID 100
#define MAX_PID 1000
#define ARR_SIZE MAX_PID-MIN_PID+1

int pid_status[ARR_SIZE];       //data structure to store or maintain the pid statuses.

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
  return 1;                //if pids are not free, 1 is returned.
}

void release_pid(int p)
{
  int pid=p-100;            //taking pid from parameter.
  pid_status[pid]=0;        //changing pid status.
}

void display()
{
  int i,c=0;
  printf("\n----------------------------------------");
  for(i=0;i<ARR_SIZE;i++)
  {
    if(pid_status[i]==1)              //checking for pids which are in use.
    {
      printf("\n[%d] = %d\t",i+100,pid_status[i]);
      c++;
    }
  }
  printf("\nPids in Use: %d",c);
  printf("\n----------------------------------------\n\n");
}

#endif
  
  
