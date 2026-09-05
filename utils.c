//
// Created by edy on 9/5/26.
//
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void read(struct gameState *output) {
    FILE *f = fopen("input.txt", "r");
    if (!f) {
        puts("error: cannot open input.txt (check working directory)");
        exit(1);
    }
    for (int i = 0; i < 6; i++)
        fscanf(f, "%s", output->column[i]);
    fclose(f);
}
// order T K D V 10 9 8 7 6
// 10 will be noted as A
// so "tkdva9876" would be a solved column

void print_current_state(struct gameState input) {
    int bitmask = 0;
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 6; j++) {
            if (input.column[j][i] == 0 && !(bitmask & (1 << j))) {
                bitmask |= 1 << j;
                continue;
            }
            if (bitmask & (1 << j))
                continue;
            printf("%c ", input.column[j][i]);
        }
        if (bitmask == 0x3F)
            break;
        printf("\n");
    }
}
int is_ordered(char prev, char next) {
    switch (prev) {
        case 'T':
            return next == 'K';
        case 'K':
            return next == 'D';
        case 'D':
            return next == 'V';
        case 'V':
            return next == 'A';
        case 'A':
            return next == '9';
        case '9':
            return next == '8';
        case '8':
            return next == '7';
        case '7':
            return next == '6';
        case '6':
            return 0;
        default:
            return 0;
    }
}
int isSolved(struct gameState input) {
    // Triggers if a cell is marked as BOTH filled and empty
    if (input.isEmpty & input.isFilledIn) {
        system("vlc bugs/bitmap_overlap.mp3 &");

        fprintf(stderr,
            "Bug, bug, bug, bug, bug, bug, bug, bug, bug, sahur!\n\n"
            "A terrifying anomaly that haunts developers at 3 AM. "
            "Legend says if a bit is simultaneously 1 in 'isEmpty' and 1 in 'isFilledIn', "
            "a memory-corrupting creature spawns directly inside your call stack.\n\n"
            "Hiii, how scary! Schrödinger's cell has manifested in your code—it is "
            "both completely full and totally empty at the same time. "
            "This Bug Bug creature marches through your terminal beating its drum: "
            "'bug, bug, bug, bug, bug, bug, bug'. "
            "Send this to a dev who forgot to isolate their bitwise flags before prod drops!\n"
        );
        return 0;
    }

    return ((input.isFilledIn | input.isEmpty) & 0x3F) == 0x3F;
}