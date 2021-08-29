#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int
main (int argc, char *argv[])
{
    int filedes[2];
    pid_t cpid; 
    char buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);

    }
    if (pipe(filedes) == -1) { /* create the pipe */
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
       if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
       }
       if (cpid == 0) {
           close(filedes[1]);         
           while (read(filedes[0], &buf, 1) > 0) {
               write(STDOUT_FILENO, &buf, 1);
           }
           write(STDOUT_FILENO, "\n", 1);
           close(filedes[0]);
           _exit(EXIT_SUCCESS);
            
       }
       else { 
            close(filedes[0]);
            write(filedes[1], argv[1], strlen(argv[1]));
            close(filedes[1]);
            wait(NULL);
            exit(EXIT_SUCCESS);
       }
}
