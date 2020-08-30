#define _POSIX_C_SOURCE 199309L  // sigaction(), struct sigaction, sigemptyset()
#define  _XOPEN_SOURCE 500  // For S_IFIFO in C99+
#include <stdio.h>   // printf, getchar
#include <string.h>  // memset
#include <signal.h>  // sigaction, sigemptyset, struct sigaction, SIGINT
#include <unistd.h>
#include <sys/stat.h>       // mkfifo()
#include <fcntl.h>          // open(), O_* constants

volatile sig_atomic_t i = 0;
void newHandler();//(int sig);

int main(void) {
  struct sigaction act, oldact;
  
  // Define SHR:
  memset(&act, '\0', sizeof(act));  // Fill act with NULLs by default
  act.sa_handler = newHandler;      // Set the custom SHR
  act.sa_flags = 0;                 // No flags, used with act.sa_handler
  sigemptyset(&act.sa_mask);        // No signal masking during SHR execution 
  
  // Install SHR:
  sigaction(SIGINT, &act, &oldact);  // This cannot be SIGKILL or SIGSTOP
  
  // Count Ctrl-Cs pressed; continue upon Enter:
  printf("press ctrl-C for start counting message(1)\n");
  

  while(i<25) {
    ;
  }
  printf("\ncounted 1, %d times.  Press Ctrl-C again to exit.\n", i);
  
  // Restore original SHR:
  sigaction(SIGINT, &oldact, NULL);
  
  // Wait for Ctrl-C to exit:
  while(1);
  
  return 0;
}

// SHR using sa_handler:
void newHandler()
{
  printf("\n");
  char message[3] = "1\n";
  for(i = 1; i < 25; ++i)
  { 
  write(O_WRONLY, &message, sizeof(message));  // Write message to FIFO
  sleep(1);
  }
}
