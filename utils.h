//
// Created by edy on 9/5/26.
//

#ifndef SOLITAIRETIS100SOLVER_UTILS_H
#define SOLITAIRETIS100SOLVER_UTILS_H

struct gameState {
    char column[6][36];
    int isFilledIn; // is a bitmask
    int isEmpty;
};

void read(struct gameState *output);
void print_current_state(struct gameState input);
int is_ordered(char prev, char next);

#endif //SOLITAIRETIS100SOLVER_UTILS_H
