#include "interface.h"

int
main(int argc, char **argv)
{
    struct sockaddr_in srvaddr, claddr;
    struct llevel_udp uHead;
    int sfd;
    socklen_t len;
    int remote_fd;
    ssize_t numRead;
    char *clmsg = calloc(PACKAGE_SIZE - sizeof(uHead), sizeof(char));
    
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    } else {
        printf("[SERVER]: socket has created!\n");
    }
    
    memset(&srvaddr, 0, sizeof(struct sockaddr_in));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(SRV_PORT);
    srvaddr.sin_addr.s_addr = INADDR_ANY;
    
    remote_fd = bind(sfd, (const struct sockaddr *) &srvaddr, 
                    sizeof(struct sockaddr_in));
    if(remote_fd == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    while(1) { 
        len = sizeof(struct sockaddr_in);
        numRead = recvfrom(sfd, clmsg, PACKAGE_SIZE - sizeof(uHead), 
                            0, (struct sockaddr *) &claddr, &len); 
        if(numRead == -1) {
            printf("[SERVER]: fault recvfrom!\n");
            exit(EXIT_FAILURE);
        } else {
            printf("[SERVER_RECV_BYTES]: %d\n", (int)numRead);
            printf("[SERVER_RECV_MESSAGE]: %s\n", clmsg);
            break;
        }
    }
    free(clmsg);
    exit(EXIT_SUCCESS);
}
