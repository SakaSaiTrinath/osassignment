#include<stdio.h>
#include<pthread.h>
int main()
{
  pthread_t p[100];
  for(int i=0;i<100;i++) 
  {
    pthread_create(&p[i],NULL,fun,NULL);
  }
}
