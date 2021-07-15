#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    fp = fopen(argv[1], "r+");

    if(fp == NULL) {
        printf("File cannot open!\n");
        return 1;
    } else {
        putc(100, fp);
        fclose(fp);
        printf("Check this file to writted\n");
    }
   return 0;
}
