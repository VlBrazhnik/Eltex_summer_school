#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int
main(int argc, char **argv)
{
    /* create pipe, create child proccess,
     * print child pid proccess 
     * */
    switch(fork()) {

        case -1: perror("fork");
                 exit(EXIT_FAILURE);

        case 0: /* child proccess */
                 printf("--CHILD--\n");
                 printf("--CHILD-- pid: %d\n", getpid());
                 printf("--CHILD-- parents pid: %d\n", getppid());
                 printf("--CHILD-- close\n");
                 
        default: /* parents proccess */
                 printf("--PARENT--\n");
                 printf("--PARENT-- pid: %d\n", getpid());
                 _exit(EXIT_SUCCESS);
                 break;
    }
    exit(EXIT_SUCCESS);
}
