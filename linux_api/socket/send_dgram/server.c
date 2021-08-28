#include "interface.h"

int
main(int argc, char **argv)
{
    struct sockaddr_in srvaddr, claddr;
    int sfd;
    socklen_t len;
    int remote_fd;
    int srvport = 7777;
    ssize_t numRead;
    char s_msg[BUF_SIZE] = "Hi, Im server\0"; 
    char buff[BUF_SIZE];

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(srvport);
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    } else {
        printf("[SERVER]: socket has created!\n");
    }
    
    remote_fd = bind(sfd, (const struct sockaddr *) &srvaddr,
                            sizeof(struct sockaddr_in));
    if(remote_fd == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    } 

  while(1) { 
    len = sizeof(struct sockaddr_in);
    numRead = recvfrom(sfd, buff, BUF_SIZE, 0, (struct sockaddr *) &claddr, &len); 
    if(numRead == -1) {
        printf("[SERVER]: fault recvfrom!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("[SERVER]: recived bytes %d\n", (int)numRead);
        printf("[SERVER_RECV_MESSAGE]: %s\n", buff);
    }

        numRead = sendto(sfd, s_msg, (BUF_SIZE + 1), 0, 
                    (struct sockaddr *) &claddr, 
                    sizeof(struct sockaddr_in));
        if(numRead == -1) {
            printf("[SERVER]: faulr sendto!\n");
            exit(EXIT_FAILURE);
        } else {
            printf("[SERVER]: sent bytes %d\n", (int)numRead);
            printf("[SERVER_SENT_MESSAGE]: %s\n", s_msg);
            break;
        }
  }
    exit(EXIT_SUCCESS);
}
