#include "interface.h"

int
main (int argc, char *argv[])
{
    struct sockaddr_un addr;
    int i;
    int ret;
    int data_socket;
    char buffer[BUFFER_SIZE];

    /* create local socket */

    data_socket = socket(AF_LOCAL, SOCK_SEQPACKET, 0);
    if (data_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* clean up structure */

    memset(&addr, 0, sizeof(struct sockaddr_un));

    /* connect socket to socket address */

    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);
    
    ret = connect(data_socket, (const struct sockaddr *) &addr, 
                    sizeof(struct sockaddr_un));
    if (ret == -1) {
        fprintf(stderr, "The server is down.\n");
        exit(EXIT_FAILURE);
    }

    /* send argument */

    for (i = 1; i < argc; ++i) {
        ret = write(data_socket, argv[i], strlen(argv[i]) + 1);
        if (ret == -1) {
            perror("write");
            break;
        }
    }

    /* request result */

    strcpy (buffer, "END");
    ret = write(data_socket, buffer, strlen(buffer) + 1);
    if (ret == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    /* recive result */

    ret = read(data_socket, buffer, BUFFER_SIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    /* ensure buffer is 0-terminated. */

    buffer[BUFFER_SIZE - 1] = 0;

    printf("Result = %s\n", buffer);

    /* close socket */

    close(data_socket);

    exit(EXIT_SUCCESS);
}

