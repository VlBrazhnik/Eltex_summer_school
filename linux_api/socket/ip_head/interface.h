#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*for memcpy, memset etc */
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <linux/if_packet.h> /* for struct sockaddr_ll */
#include <net/ethernet.h> /* the L2 protocols */


#define BUF_SIZE        20
#define PACKAGE_SIZE    20 
#define SRV_PORT        7777

struct llevel_udp {
    unsigned short src_port;
    unsigned short dest_port;
    unsigned short total_lenght;
    unsigned short checksum;
};

struct llevel_ip {
    unsigned char ver;
    unsigned char ds;
    unsigned short total_lenght;
    unsigned short ident;
    unsigned short flags;
    unsigned char ttl;
    unsigned char trans_proto;
    unsigned short checksum;
    unsigned int src_ipaddr;
    unsigned int dest_ipaddr;   
};
