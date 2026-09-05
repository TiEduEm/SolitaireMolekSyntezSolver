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