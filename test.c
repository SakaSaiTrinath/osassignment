#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include "pidmanager.h"

struct proc
{
  int sno;
  int pid;
  int sl_time;
};

int pid_check(int pid)
{
  if(pid>=100)
  {
    printf("\nPid %d assigned successfully...\n",pid);
    return 1;
    //printf("\nPid is: %d",pid);
  }
  else if(pid==1)
  {
    printf("\npid allocation failed...\n");
    return 0;
  }
  else
  {
    printf("\nSomething went wrong... pid: %d is returned...",pid);
    return 0;
  }
}

int set_sleep_time()
{
  //srand(2);
  return rand()%10;
}

void *thread_fun(void *pro)
{
  struct proc *p = (struct proc *) pro;
  printf("\n%d: Fetching pid...\n",p->sno);
  p->pid = alocate_pid();
  
  while(pid_check(p->pid)==0)
  {
    sleep(5);
    printf("\n%d: Fetching pid...\n",p->sno);
    p->pid = allocate_pid();
  }
  display();
  
  p->sl_time = set_sleep_time();
  printf("\n%d: pid = %d,sl_time = %d\n",p->sno,p->pid,p->sl_time);
  printf("\n%d - %d: Entered Sleep time...\n",p->sno,p->pid);
  sleep(p->sl_time);
  printf("\n%d - %d: Exited Sleep time...\n",p->sno,p->pid);
  int pos = release_pid(p->pid);
  display();
  
  if(pos==0)
  {
    printf("\n%d - %d: pid released...\n",p->sno,p->pid);
  }
  else
  {
    printf("\n%d - %d: problem in releasing pid...\n",p->sno,p->pid);
  }
}

int main()
{
  int i, no_of_threads;
  printf("Enter no of threads: ");
  scanf("%d",&no_of_threads);
  printf("...program getting stared...\n");
  
  allocate_map();
  printf("Map allocated...\n");
  
  struct proc pr[no_of_threads];
  pthread_t pr_threads[no_of_threads];
  
  for(i=0;i<no_of_threads;i++)
  {
    pr[i].sno = i;
    pthread_create(&pr_threads[i],NULL,thread_fun,&pr[i]);
  }
  
  for(i=0;i<no_of_threads;i++)
  {
    pthread_join(pr_threads[i],NULL);
  }
  
  printf("\n...Program Successfully terminated...\n");
}
  
  
  
  
    
    
    
