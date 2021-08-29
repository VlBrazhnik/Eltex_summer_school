#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

#define BUF_SIZE        20
#define PACKAGE_SIZE    20 
#define SRV_PORT        7777

struct llevel_udp {
    unsigned short src_port;
    unsigned short dest_port;
    unsigned short total_lenght;
    unsigned short checksum;
};
