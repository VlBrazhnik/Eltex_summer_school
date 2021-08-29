#include <stdio.h>

int main(int argc, char *argv[]) {
    
    FILE *fp;
    void fcopy(FILE *, FILE *);

    if (argc == 1) // no arguments
        fcopy(stdin, stdout);
    else
        while(--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("[ERR] cat: cannot open file %s\n", *argv);
                return 1;
            } else {
                fcopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

void fcopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
