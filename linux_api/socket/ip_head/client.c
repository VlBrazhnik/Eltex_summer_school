#include "interface.h"

void fill_udphdr(struct llevel_udp *);
void fill_iphdr(struct llevel_ip *);

int
main(int argc, char const *argv[]) {
	struct sockaddr_in claddr;
    struct llevel_udp uHead;
    struct llevel_ip ipHead;
	int cfd;
    int flopt = 1;
	socklen_t len;
	ssize_t numRead;
    
	cfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if(cfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
    } else {
        printf("[CLIENT]: socket has created!\n");
    }
    
    memset(&claddr, 0, sizeof(struct sockaddr_in));
    claddr.sin_family = AF_INET;
    claddr.sin_port = htons(SRV_PORT);
    claddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    /* set sockopt for recive packet */
    if(setsockopt(cfd, IPPROTO_IP, IP_HDRINCL, 
                &flopt, sizeof(flopt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    } else {
        printf("[SOCK_OPT]: can recive packets from serv!\n");
    }

    fill_udphdr(&uHead);
    fill_iphdr(&ipHead);
    printf("[CLIENT_MSG]: \n");
    char *msg = calloc(PACKAGE_SIZE - sizeof(uHead), sizeof(char));
    fgets(msg, PACKAGE_SIZE - sizeof(uHead), stdin);

    char *packet = calloc(PACKAGE_SIZE + sizeof(ipHead), sizeof(char));
    memmove(packet, &ipHead, sizeof(ipHead));
    memmove(packet + sizeof(ipHead), &uHead, sizeof(uHead));
    memmove(packet + 8 + sizeof(ipHead), msg, strlen(msg));

    /* send message to server */
    for(;;) {  
        len = sizeof(struct sockaddr_in);
        numRead = sendto(cfd, packet, PACKAGE_SIZE + sizeof(ipHead), 0, 
                        (struct sockaddr *) &claddr, 
                        len);
        if (numRead == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        } else {
            printf("[CLIENT_SENT_BYTES]: %lu\n", numRead);
            printf("[CLIENT_SENT_MESSAGE]: %s\n", msg);
        }

        numRead = recvfrom(cfd, packet, PACKAGE_SIZE + sizeof(ipHead), 0,
                            (struct sockaddr *) &claddr, &len);
        if(numRead == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        } else {
            printf("[CLIENT_RECV_BYTES]: %lu\n", numRead);
            printf("[CLIENT_RECV_MSG]: %s\n", packet);
            break;
        }
    }
    free(msg);
    free(packet);
	exit(EXIT_SUCCESS);
}

void fill_udphdr(struct llevel_udp *head) {
    head->src_port = htons(SRV_PORT);
    head->dest_port = htons(SRV_PORT);
    head->total_lenght = htons(PACKAGE_SIZE);
    head->checksum = 0;
}

void fill_iphdr(struct llevel_ip *head) {
    head->ver = 0x45;
    head->ds = 0;
    head->total_lenght = htons(PACKAGE_SIZE + sizeof(struct llevel_ip));
    head->ident = htons(576);
    head->flags = 0;
    head->ttl = 255;
    head->trans_proto = IPPROTO_UDP;
    head->checksum = 0;
    head->src_ipaddr = inet_addr("127.0.0.1"); 
    head->dest_ipaddr = inet_addr("127.0.0.2");
}
