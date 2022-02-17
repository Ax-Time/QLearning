//
// Created by giaco on 15/02/2022.
//

#include <malloc.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include "qtable.h"

qtable qtable_create(uint64_t states, uint64_t actions) {
    float* table = malloc(sizeof(float) * states * actions);
    if(!table) {
        fprintf(stderr, "Error: couldn't create qtable\n");
        return qtable_errTable();
    }
    for(uint64_t state = 0; state < states; state++) {
        for(uint64_t action = 0; action < actions; action++) {
            table[state * actions + action] = 2.0 * ( (float) rand() / (float) RAND_MAX ) - 1.0;
        }
    }
    qtable qtable = {
            .states = states,
            .actions = actions,
            .table = table
    };
    return qtable;
}

qtable qtable_errTable() {
    qtable result = {
            .states = 0,
            .actions = 0,
            .table = NULL
    };
    return result;
}

float qtable_getQvalue(qtable qtable, uint64_t state, uint64_t action) {
    if(state >= qtable.states || action >= qtable.actions) {
        fprintf(stderr, "Error: the requested qvalue is out of boundaries\n");
        return 0;
    }
    float qvalue = qtable.table[state * qtable.actions + action];
    return qvalue;
}

void qtable_setQvalue(qtable qtable, uint64_t state, uint64_t action, float value) {
    if(state >= qtable.states || action >= qtable.actions) {
        fprintf(stderr, "Error: the requested qvalue is out of boundaries\n");
        return;
    }
    qtable.table[state * qtable.actions + action] = value;
}

uint64_t qtable_chooseBestAction(qtable qtable, uint64_t state, unsignedArray validActions) {
    if(state >= qtable.states) {
        fprintf(stderr, "Error: the state provided is out of boundaries\n");
        return 0;
    }
    // Check if actions are in boundaries
    for(uint64_t index = 0; index < validActions.size; index++) {
        if(validActions.arr[index] >= qtable.actions) {
            fprintf(stderr, "Error: at least one of the actions provided is out of boundaries\n");
            return 0;
        }
    }

    // Return best Qvalue
    float bestQvalue = -FLT_MAX;
    uint64_t bestAction = 0;
    for(uint64_t index = 0; index < validActions.size; index++) {
        uint64_t action = validActions.arr[index];
        float qvalue = qtable_getQvalue(qtable, state, action);
        if(qvalue >= bestQvalue) {
            bestQvalue = qvalue;
            bestAction = action;
        }
    }

    return bestAction;
}

uint64_t qtable_chooseRandomAction(qtable qtable, uint64_t state, unsignedArray validActions) {
    if(state >= qtable.states) {
        fprintf(stderr, "Error: the state provided is out of boundaries\n");
        return 0;
    }
    // Check if actions are in boundaries
    for(uint64_t index = 0; index < validActions.size; index++) {
        if(validActions.arr[index] >= qtable.actions) {
            fprintf(stderr, "Error: at least one of the actions provided is out of boundaries\n");
            return 0;
        }
    }

    return validActions.arr[rand() % validActions.size];
}

void qtable_learn(
            qtable          qtable,
            uint64_t        srcState,
            uint64_t        actionTaken,
            uint64_t        dstState,
            unsignedArray   dstStateValidActions,
            float           reward,
            float           discountFactor,
            float           learningRate
        )
{
    float maxValueDstState = qtable_getQvalue(qtable,
                                              dstState,
                                              qtable_chooseBestAction(qtable, dstState, dstStateValidActions));
    qtable_setQvalue(
                qtable,
                srcState,
                actionTaken,
                (1 - learningRate) * qtable_getQvalue(qtable, srcState, actionTaken)
                + learningRate * (reward + discountFactor * maxValueDstState)
            );
}

void qtable_store(const char *filepath, qtable qtable) {
    FILE* fp = NULL;
    fp = fopen(filepath, "wb");
    if(!fp) {
        fprintf(stderr, "FileError: cannot store qtable\n");
        return;
    }
    fwrite(&qtable.states, sizeof(uint64_t), 1, fp);
    fwrite(&qtable.actions, sizeof(uint64_t), 1, fp);
    fwrite(qtable.table, sizeof(float), qtable.states * qtable.actions, fp);
    fclose(fp);
}

qtable qtable_load(const char *filepath) {
    FILE* fp = NULL;
    fp = fopen(filepath, "rb");
    if(!fp) {
        fprintf(stderr, "FileError: cannot load qtable\n");
        return qtable_errTable();
    }
    qtable q;
    fread(&q.states, sizeof(uint64_t), 1, fp);
    fread(&q.actions, sizeof(uint64_t), 1, fp);
    float* table = malloc(sizeof(float) * q.states * q.actions);
    fread(table, sizeof(float), q.states * q.actions, fp);
    fclose(fp);
    q.table = table;
    return q;
}

void qtable_train(
            FILE*       logStream,
            const char* storagePath,
            genericGame game,
            qtable      qtable,
            unsigned    epochs,
            unsigned    generations,
            float       startingLearningRate,
            float       startingDiscountFactor,
            float       startingExplorationProbability,
            float       (*learningRateDecayFun)(float),
            float       (*discountFactorDecayFun)(float),
            float       (*explorationProbabilityDecayFun)(float)
        )
{
    for(unsigned epoch = 0; epoch < epochs; epoch++) {
        fprintf(logStream, "Epoch %u:\n", epoch);
        fprintf(logStream, "\tLearning Rate: %.2f\n", startingLearningRate);
        fprintf(logStream, "\tDiscount Factor: %.2f\n", startingDiscountFactor);
        fprintf(logStream, "\tExploration Probability: %.2f\n", startingExplorationProbability);

        for(unsigned generation = 0; generation < generations; generation++) {
            void* state = (void*) game.generateInitialState();
            while(!game.isTerminal(state)) {
                uint64_t state_encoding = game.encodeGameState(state);
                unsignedArray validActions = game.getValidActions(state);
                float reward;
                uint64_t actionChosen = ((float)rand() / (float)RAND_MAX) < startingExplorationProbability ?
                                        qtable_chooseBestAction(qtable,
                                                                state_encoding,
                                                                validActions) :
                                        qtable_chooseRandomAction(qtable,
                                                                  state_encoding,
                                                                  validActions);

                void* newState = game.transition(state, actionChosen, &reward);

                unsigned newState_encoding = game.encodeGameState(newState);
                unsignedArray newStateValidActions = game.getValidActions(newState);
                qtable_learn(
                            qtable,
                            state_encoding,
                            actionChosen,
                            newState_encoding,
                            newStateValidActions,
                            reward,
                            startingDiscountFactor,
                            startingLearningRate
                        );

                game.destroyState(state);
                state = newState;
                unsignedArray_destroy(validActions);
                unsignedArray_destroy(newStateValidActions);
            }
            game.destroyState(state);
        }

        qtable_store(storagePath, qtable);
        startingLearningRate = learningRateDecayFun(startingLearningRate);
        startingDiscountFactor = discountFactorDecayFun(startingDiscountFactor);
        startingExplorationProbability = explorationProbabilityDecayFun(startingExplorationProbability);
    }
}

void qtable_print(qtable qtable) {
    for(uint64_t state = 0; state < qtable.states; state++) {
        for(uint64_t action = 0; action < qtable.actions; action++) {
            if(action == 0) printf("%llu:  ", state);
            printf("%+.2f  ", qtable_getQvalue(qtable, state, action));
        }
        printf("\n");
    }
    printf("\n");
}

float linearDecay(float x) {
    if(x <= 0) return 0;
    else return x - 0.001 < 0 ? 0 : x - 0.001;
}

float noDecay(float x) {
    return x;
}

void qtable_destroy(qtable qtable) {
    free(qtable.table);
}





