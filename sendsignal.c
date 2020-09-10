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

void print_message(char message[100]);


int main(int argc, char *argv[])
{
  //char message[100];
  unsigned long int message;
  message = strtoul(argv[1], NULL, 10);
//int sleepTime = *(int*) arg;
//unsigned int sleepTimeC=10;
  //String message(argv[1]);
  printf("PID num = %li time to kill the progress\n",message);
  kill(message, 25);
  //scanf("%99s",message);
  //print_message(message);
}
// Print a message to screen, character by character:
/*void print_message(unsigned long int message) {

printf("%ld\n",message);
system("killall -25 getsignal");
  
  //for(unsigned int i=0; i<strlen(message); i++) {
    //write(1, &message[i], 1);
    //usleep(sleepTime * 1000);  // Sleep for sleepTime ms
  //}
}*/


