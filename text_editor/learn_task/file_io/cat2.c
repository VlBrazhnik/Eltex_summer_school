#include <stdio.h>

int main(int argc, char *argv[]) {
    
    FILE *ifp;
    FILE *ofp;

    void fcopy(FILE *, FILE *);

    if (argc == 1) // no arguments
        fcopy(stdin, stdout);
    else {
          
            if ((ifp = fopen(argv[1], "r")) == NULL) {
                printf("[ERR] cat: cannot open input file %s\n", argv[1]);
                return 1;
            } else if ((ofp = fopen(argv[2], "w")) == NULL) {
                printf("[ERR] cat: cannot open output file %s\n", argv[2]);
                return 1;
              } else {
                 fcopy(ifp, ofp);
                 fclose(ifp);
                 fclose(ofp);
                 printf("cat: copy has successufl!\n");
                }
    }
    return 0;
}

void fcopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
