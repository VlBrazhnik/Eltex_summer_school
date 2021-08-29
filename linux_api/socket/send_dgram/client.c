#include "interface.h"

int
main(int argc, char **argv)
{
    struct sockaddr_in claddr;
    int cfd;
    int serv_port = 7777;
    ssize_t numRead;
    char cl_msg[BUF_SIZE] = "Hi, Im client\0";
    char buff[BUF_SIZE];

    cfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(cfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    } else {
        printf("[CLIENT]: socket has created!\n");
    }
    memset(&claddr, 0, sizeof(struct sockaddr_in));
    claddr.sin_family = AF_INET;
    claddr.sin_port = htons(serv_port);
    claddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    numRead = sendto(cfd, cl_msg, (BUF_SIZE + 1), MSG_TRUNC, 
                    (struct sockaddr *) &claddr, sizeof(struct sockaddr_in));
        if(numRead == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        } else {
            printf("[CLIENT]: sent bytes %d\n", (int)numRead);
            printf("[CLIENT_MSG_SENT]: %s\n", cl_msg);
        }

        numRead = recvfrom(cfd, buff, (BUF_SIZE), 0, NULL, NULL);
        if(numRead == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        } else {
            printf("[CLIENT]: recive bytes %d\n", (int)numRead);
            printf("[CLIENT_MSG_RECV]: %s\n", buff);
        }
    exit(EXIT_SUCCESS);
}
