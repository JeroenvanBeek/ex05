#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *ThreadFunction(void *arg);

int main(void) 
{
  pthread_t ThreadID_A;
  pthread_t ThreadID_B;

  const char ThreadArgA[] = "I am thread A.";
  const char ThreadArgB[] = "I am thread B.";

  // Thread will be *created* here, but not necessarily started yet.  
  //   The *scheduler* determines when the thread will start.
  // In the call, ThreadArgA is cast to void*

  if(pthread_create(&ThreadID_A, NULL, ThreadFunction, (void*) ThreadArgA)) 
  {
    fprintf(stderr, "No thread A\n");
    exit(EXIT_FAILURE);
  }
  
  if(pthread_create(&ThreadID_B, NULL, ThreadFunction, (void*) ThreadArgB)) 
  {
    fprintf(stderr, "No thread B\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Thread A has ID %lu\n", ThreadID_A);
  printf("Thread B has ID %lu\n", ThreadID_B);
  
  pthread_join(ThreadID_A, NULL);
  pthread_join(ThreadID_B, NULL);
  
  return 0;
}

// Thread function:
void *ThreadFunction(void *arg) {
  printf("%s\n", (char *) arg);  // Cast arg (back) to char*
  pthread_exit(NULL);            // End of thread function
}
