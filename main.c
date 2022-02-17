#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "qtable.h"
#include "miscellaneous.h"
#include "simple_game.h"

typedef enum mode {
    train_from_start, train_from_existing, visualizeQtable, simulate
} mode;

int main() {
    srand(time(0));  // initialize random seed with current time

    genericGame game = {
            .generateInitialState = sg_generateInitialState,
            .destroyState         = sg_destroyState,
            .getValidActions      = sg_getValidActions,
            .transition           = sg_transition,
            .encodeGameState      = sg_encodeState,
            .isTerminal           = sg_isTerminal,
            .space_state_size     = sg_getStateSpaceSize(WIDTH, HEIGHT)
    };

    unsigned n_actions = sg_nActions;

    mode m = train_from_existing;
    unsigned n_simulations = 30;
    qtable q;
    const char* storagePath = "./storage.bin";

    switch (m) {
        case train_from_start:
            q = qtable_create(game.space_state_size, n_actions);
            qtable_train(
                    stdout,
                    storagePath,
                    game,
                    q,
                    30,
                    10000,
                    0.7,
                    0.8,
                    0.1,
                    linearDecay,
                    noDecay,
                    linearDecay
            );
            break;
        case train_from_existing:
            q = qtable_load(storagePath);
            qtable_train(
                    stdout,
                    storagePath,
                    game,
                    q,
                    3000,
                    10000,
                    0.2,
                    0.8,
                    0.2,
                    noDecay,
                    noDecay,
                    noDecay
            );
            break;
        case visualizeQtable:
            q = qtable_load(storagePath);
            qtable_print(q);
            break;
        case simulate:
            q = qtable_load(storagePath);
            for(unsigned i = 0; i < n_simulations; i++) {
                printf("Simulation %u:\n", i);
                sg_simulate(q);
                printf("\n\n");
            }
            break;
        default:
            return 0;
    }

    qtable_destroy(q);
    return 0;
}
