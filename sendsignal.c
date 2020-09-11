#define  _GNU_SOURCE  // Needed by usleep() in gcc

#include <pthread.h>  // threading, mutexes, CVs
#include <stdio.h>    // sprintf()
#include <unistd.h>   // write(), usleep()
#include <stdbool.h>  // true, false
#include <string.h>   // stren()
#include <sys/stat.h>       // mkfifo()
#include <fcntl.h>  
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>


int main(int argc, char *argv[])
{
  unsigned long int PID;
  PID = strtoul(argv[1], NULL, 10);


  while(1) 
  {
    printf("Proces with PID num =%li will be killed in three seconds\n",PID);
    sleep(3);
    kill(PID, 25);
  }

}



