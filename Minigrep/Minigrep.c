#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExpandableBitVec.h"
#include "Finder.h"

const size_t MAX_LINE_SIZE = 512;

int main (int argc, char** argv) {
    switch (argc) {
        case 1:
            fprintf(stderr, "You need to pass in a file as the first argument.\n");
            return -1;
        case 2:
            fprintf(stderr, "You need to pass in a pattern to look for as the second argument.\n");
            return -1;
    }


    FILE *fptr = fopen( argv[1], "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error reading file %s\n", argv[1]);
        return -1;
    }

    char* pattern = argv[2];
    ExpandableBitVec ebv = EBV(50);

    char* line = malloc(sizeof(char) * MAX_LINE_SIZE);
    ssize_t read;

    while ((read = getline(&line, &MAX_LINE_SIZE, fptr)) != -1) {
        Matches m = findMatches(line, pattern);


        MatchesToEBV(m, &ebv, read);

        for (ssize_t i = 0; i < read; i++) {
            if (Index(&ebv, i)) {
                printf("\x1B[32;1m%c\x1B[37m", line[i]);
            } else {
                printf("%c", line[i]);
            }
        }

        Clear(&ebv);
//        printf("\n");

        free(m.matches);
    }

    fclose(fptr);
    if (line)
        free(line);

    free(ebv.backing);

    return EXIT_SUCCESS;
}