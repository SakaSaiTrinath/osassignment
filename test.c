/*
  This file test.c tests pidmanager which is defined in pidmanger.h. 
  
  On running this file, it asks for number of threads to create from user. 
  After getting input, 
  First allocate_map() called from pidmanager.h which initialises all the pid statuses.  
  Then threads and structure objects for every thread gets created.
  Then every thread ask pidmanager for pid on creation by calling allocate_map() function from pidmanager header file. 
  After getting pid, thread calls set_sleep_time() for getting random period of sleep time.
  Then, thread sleeps for allocated time.
  After sleep time completed, thread leaves the pid to pidmanger by calling release_pid() from pidmanager.h.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "pidmanager.h"

struct proc       //structure for thread which represents process's data
{
  int sno;        //serial number
  int pid;        //pid value
  int sl_time;    //sleep time
};

int pid_check(int pid)
{
  if(pid>=100)                        //checking whether pid is assigned or not.
  {
    printf("\nPid %d assigned successfully...\n",pid);
    return 0;                               //returning 0 to indicate pid is set.
  }
  else if(pid==1)                     //if returned is 1, pid is not set (indicating pids are not free).
  {
    printf("\npid allocation failed...\n"); 
    return 1;                         //returning 1 to say the same.
  }
  else                              //if something else happened.
  {
    printf("\nSomething went wrong... pid: %d is returned...",pid);
    return 1;
  }
}

int set_sleep_time()
{
  return rand()%10;                      //giving sleep time in range 0-10 secs.
}

void *thread_fun(void *pro)               //In each thread, this body of code executes.
{
  struct proc *p = (struct proc *) pro;
  printf("\n%d: Fetching pid...\n",p->sno);
  p->pid = alocate_pid();                 //fetching pid
  
  while(pid_check(p->pid)==1)             //until pid is assigned, this loop will run.
  {
    sleep(5);                             //sleeps for 5 secs as pid is not assigned.
    printf("\n%d: Fetching pid...\n",p->sno);   
    p->pid = allocate_pid();              //trying to fetch pid once more.
  }
  display();                              //display the pids statuses.
  
  p->sl_time = set_sleep_time();          //setting of sleep time for every process or thread.
  printf("\n%d: pid = %d,sl_time = %d\n",p->sno,p->pid,p->sl_time);
  printf("\n%d - %d: Entered Sleep time...\n",p->sno,p->pid);
  sleep(p->sl_time);                                                    //every thread sleep for its allocated time.
  printf("\n%d - %d: Exited Sleep time...\n",p->sno,p->pid);
  release_pid(p->pid);                                    //after sleep time completes, every thread releases its pid.
  display();
}

int main()
{
  int i, no_of_threads;
  printf("Enter no of threads: ");
  scanf("%d",&no_of_threads);               //getting no of threads from user input.
  printf("...program getting stared...\n");
  
  int x = allocate_map();                   //initializing pid statuses.
  if(x==0)                                  //checking whether they get initialized or not.
    printf("Map allocated...\n");
  else
    printf("Problem in initializing statuses...\n");
  
  struct proc pr[no_of_threads];               //creating structures for threads to store data of a thread of the number given by user.
  pthread_t pr_threads[no_of_threads];              //creating threads references of number given by user.
  
  for(i=0;i<no_of_threads;i++)
  {
    pr[i].sno = i;                                  //giving every structure its serial number, starting from 0.
    pthread_create(&pr_threads[i],NULL,thread_fun,&pr[i]);           //creating threads with function associated with every thread.
  }
  
  for(i=0;i<no_of_threads;i++)              
  {
    pthread_join(pr_threads[i],NULL);                     //waiting for every thread to get execute.
  }
  
  printf("\n...Program Successfully terminated...\n");
}
  
  
  
  
    
    
    
