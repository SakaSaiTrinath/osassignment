#include<stdio.h>
#include "pidmanager.h"

struct proc
{
  int pid;
  int sleep_time;
};

void pid_check(int pid)
{
  if(pid>=100)
  {
    printf("\nPid assigned successfully...");
    printf("\nPid is: %d",pid);
  }
  else if(pid==0)
  {
    printf("\npid allocation failed...\n");
  }
  else
  {
    printf("\nSomething went wrong... pid: %d is returned...",pid);
  }
}

int main()
{
  struct proc p1,p2;
  allocate_map();
  printf("\nAfter allocate_map()\n");
  display();
  p1.pid = allocate_pid();
  pid_check(p1.pid);
  p2.pid = allocate_pid();
  pid_check(p2.pid);
  pid_check(p2.pid);
  printf("\nAfter allocate_pid()\n");
  display();
  release_pid(p1.pid);
  printf("\nAfter release_pid()\n");
  display();
  printf("\nProgram terminated successfully...\n");
}
  
  
  
  
    
    
    
