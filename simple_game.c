//
// Created by giaco on 15/02/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "simple_game.h"

simple_game_state* sg_generateInitialState() {
    simple_game_state *init = malloc(sizeof(simple_game_state));
    if(!init) {
        fprintf(stderr, "Error: cannot create game state\n");
        return NULL;
    }
    init->width = WIDTH;
    init->height = HEIGHT;
    init->time_step = 0;

    init->player_pos.x = rand() % init->height;
    init->player_pos.y = rand() % init->width;

    unsigned testX = 0, testY = 0;
    do {
        testX = rand() % init->height;
        testY = rand() % init->width;
    } while(testX == init->player_pos.x && testY == init->player_pos.y);
    init->exit_pos.x = testX;
    init->exit_pos.y = testY;

    do {
        testX = rand() % init->height;
        testY = rand() % init->width;
    } while( (testX == init->player_pos.x && testY == init->player_pos.y) ||
             (testX == init->exit_pos.x && testY == init->pit_pos.y) );
    init->pit_pos.x = testX;
    init->pit_pos.y = testY;

    return init;
}

unsignedArray sg_getValidActions(simple_game_state* state) {
    unsignedArray result = unsignedArray_create(4);
    if(state->player_pos.x > 0) unsignedArray_push(&result, up);
    if(state->player_pos.x != state->height - 1) unsignedArray_push(&result, down);
    if(state->player_pos.y > 0) unsignedArray_push(&result, left);
    if(state->player_pos.y != state->width - 1) unsignedArray_push(&result, right);
    return result;
}

simple_game_state *sg_transition(simple_game_state* startingState, sg_action action, float* reward) {
    coord newPlayerPos = {
            .x = startingState->player_pos.x,
            .y = startingState->player_pos.y
    };
    switch (action) {
        case up:
            newPlayerPos.x--;
            break;
        case down:
            newPlayerPos.x++;
            break;
        case left:
            newPlayerPos.y--;
            break;
        case right:
            newPlayerPos.y++;
            break;
        default:
            fprintf(stderr, "Error: invalid action\n");
    }

    *reward = 0;

    if(newPlayerPos.x == startingState->pit_pos.x && newPlayerPos.y == startingState->pit_pos.y) *reward -= 1000;
    if(newPlayerPos.x == startingState->exit_pos.x && newPlayerPos.y == startingState->exit_pos.y) *reward += 1000;

    simple_game_state *newState = malloc(sizeof(simple_game_state));
    if(!newState) {
        fprintf(stderr, "Error: could not create new state\n");
        return NULL;
    }
    newState->width = startingState->width;
    newState->height = startingState->height;
    newState->player_pos = newPlayerPos;
    newState->exit_pos = startingState->exit_pos;
    newState->pit_pos = startingState->pit_pos;
    newState->time_step = startingState->time_step + 1;

    return newState;
}

uint64_t sg_encodeState(simple_game_state* state) {
    unsigned array_size = state->width * state->height;
    unsigned player_index = state->player_pos.x * state->width + state->player_pos.y;
    unsigned exit_index = state->exit_pos.x * state->width + state->exit_pos.y;
    unsigned pit_index = state->pit_pos.x * state->width + state->pit_pos.y;

    // Only non-terminal states are encoded, terminal states are encoded to a special code
    if(sg_isTerminal(state)) return sg_getStateSpaceSize(state->width, state->height) - 1;

    return
        player_index * (array_size - 1) * (array_size - 2) +
        exit_index   * (array_size - 2) +
        pit_index;
}

bool sg_isTerminal(simple_game_state* state) {
    return (
            (state->player_pos.x == state->exit_pos.x && state->player_pos.y == state->exit_pos.y) ||
            (state->player_pos.x == state->pit_pos.x && state->player_pos.y == state->pit_pos.y) ||
            (state->time_step >= (state->width * state->height) * 2)
    );
}

uint64_t sg_getStateSpaceSize(unsigned int width, unsigned int height) {
    unsigned array_size = width * height;
    return array_size * (array_size - 1) * (array_size - 2) + 1;
    // the +1 is for the encoding of every terminal state
}

void sg_printState(simple_game_state* state) {
    for(unsigned row = 0; row < state->height; row++) {
        for(unsigned col = 0; col < state->width; col++) {
            char curr = 0;
            if(state->player_pos.x == row && state->player_pos.y == col) curr = 'P';
            else if(state->exit_pos.x == row && state->exit_pos.y == col) curr = 'E';
            else if(state->pit_pos.x == row && state->pit_pos.y == col) curr = 'X';
            else curr = '_';
            printf("%c  ", curr);
        }
        printf("\n");
    }
    printf("\n");
}

void sg_simulate(qtable qtable) {
    simple_game_state* state = sg_generateInitialState();
    sg_printState(state);
    while(!sg_isTerminal(state)) {
        float t;
        unsignedArray validActions = sg_getValidActions(state);
        state = sg_transition(
                state,
                qtable_chooseBestAction(qtable, sg_encodeState(state), validActions),
                &t
        );
        unsignedArray_destroy(validActions);
        sg_printState(state);
    }
    sg_destroyState(state);
}

void sg_destroyState(simple_game_state *state) {
    free((simple_game_state*)state);
}


