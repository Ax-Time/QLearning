//
// Created by giaco on 15/02/2022.
//

#ifndef QLEARNING_SIMPLE_GAME_H
#define QLEARNING_SIMPLE_GAME_H

#include "miscellaneous.h"
#include "qtable.h"

/**
 * This game is played on a WIDTH x HEIGHT board where there is a player, an exit and a pit, the goal is that
 * the player finds the exit before the time expires and without falling into the pit.
 * The actions are: UP(0), DOWN(1), LEFT(2), RIGHT(3)
 */

#define WIDTH 3
#define HEIGHT 3

typedef enum sg_action {
    up = 0, down = 1, left = 2, right = 3, sg_nActions
} sg_action;

typedef struct coord {
    unsigned x;
    unsigned y;
} coord;

typedef struct simple_game_state {
    unsigned    width;
    unsigned    height;
    coord       player_pos;
    coord       exit_pos;
    coord       pit_pos;
    unsigned    time_step;
} simple_game_state;

simple_game_state*  sg_generateInitialState();
void                sg_destroyState(simple_game_state* state);
unsignedArray       sg_getValidActions(simple_game_state* state);
simple_game_state*  sg_transition(simple_game_state* startingState, sg_action action, float* reward);
uint64_t            sg_encodeState(simple_game_state* state);
bool                sg_isTerminal(simple_game_state* state);
uint64_t            sg_getStateSpaceSize(unsigned width, unsigned height);
void                sg_printState(simple_game_state* state);
void                sg_simulate(qtable qtable);

#endif //QLEARNING_SIMPLE_GAME_H
