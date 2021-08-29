#include "interface.h"

void fill_header(struct llevel_udp *);

int
main(int argc, char const *argv[]) {
	struct sockaddr_in claddr;
    struct llevel_udp uHead;
	int cfd;
	socklen_t len;
	ssize_t numRead;
    
	cfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
	if(cfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
    } else {
        printf("[CLIENT]: socket has created!\n");
    }
    
    memset(&claddr, 0, sizeof(struct sockaddr_in));
    claddr.sin_family = AF_INET;
    claddr.sin_port = htons(SRV_PORT);
    claddr.sin_addr.s_addr = INADDR_ANY;

    fill_header(&uHead);
    printf("[CLIENT_MSG]: \n");

    char *msg = calloc(PACKAGE_SIZE - sizeof(uHead), sizeof(char));
    fgets(msg, PACKAGE_SIZE - sizeof(uHead), stdin);
    char *packet = calloc(PACKAGE_SIZE, sizeof(char));
    memmove(packet, &uHead, sizeof(uHead));
    memmove(packet + 8, msg, strlen(msg));
    
    /* send message to server */
    for(;;) {  
        len = sizeof(struct sockaddr_in);
        numRead = sendto(cfd, packet, PACKAGE_SIZE, 0, 
                        (struct sockaddr *) &claddr, 
                        len);
        if (numRead == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        } else {
            printf("[CLIENT_SENT_BYTES]: %lu\n", numRead);
            printf("[CLIENT_SENT_MESSAGE]: %s\n", msg);
            break;
        }
    }
    free(msg);
    free(packet);
	exit(EXIT_SUCCESS);
}

void fill_header(struct llevel_udp *head) {
    head->src_port = htons(SRV_PORT);
    head->dest_port = htons(SRV_PORT);
    head->total_lenght = htons(PACKAGE_SIZE);
    head->checksum = htons(0);
}
