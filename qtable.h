//
// Created by giaco on 15/02/2022.
//

#ifndef QLEARNING_QTABLE_H
#define QLEARNING_QTABLE_H

#include <inttypes.h>

#include "miscellaneous.h"

typedef struct qtable {
    uint64_t    states;
    uint64_t    actions;
    float*      table;
} qtable;

qtable      qtable_create(uint64_t states, uint64_t actions);
qtable      qtable_errTable();
void        qtable_destroy(qtable qtable);
float       qtable_getQvalue(qtable qtable, uint64_t state, uint64_t action);
void        qtable_setQvalue(qtable qtable, uint64_t state, uint64_t action, float value);
uint64_t    qtable_chooseBestAction(qtable qtable, uint64_t state, unsignedArray validActions);
uint64_t    qtable_chooseRandomAction(qtable qtable, uint64_t state, unsignedArray validActions);
void        qtable_learn(
                qtable          qtable,
                uint64_t        srcState,
                uint64_t        actionTaken,
                uint64_t        dstState,
                unsignedArray   dstStateValidActions,
                float           reward,
                float           discountFactor,
                float           learningRate
            );
void        qtable_store(const char* filepath, qtable qtable);
qtable      qtable_load(const char* filepath);
void        qtable_train(
                FILE        *logStream,
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
            );
void        qtable_print(qtable qtable);

float linearDecay(float x);
float noDecay(float x);

#endif //QLEARNING_QTABLE_H
