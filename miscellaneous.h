//
// Created by giaco on 15/02/2022.
//

#ifndef QLEARNING_MISCELLANEOUS_H
#define QLEARNING_MISCELLANEOUS_H

#include <inttypes.h>
#include <stdbool.h>

typedef struct unsignedArray {
    uint64_t*   arr;
    uint64_t    max_size;
    uint64_t    size;
} unsignedArray;

unsignedArray unsignedArray_create(uint64_t max_size);
unsignedArray unsignedArray_err();
void          unsignedArray_destroy(unsignedArray ua);
void          unsignedArray_push(unsignedArray* ua, uint64_t element);

typedef struct genericGame {
    /**
     * pointer to a function that returns an initial state
     */
    void*           (*generateInitialState)();

    /**
     * pointer to a function that destroys a state
     */
    void            (*destroyState)(void*);

    /**
     * pointer to a function that takes a state as a parameter and returns an unsignedArray containing all
     * the valid actions that can be performed in that state
     */
    unsignedArray   (*getValidActions)(void*);

    /**
     * pointer to a function that takes a state, an action and a pointer to a float as parameters and returns
     * the state obtained by performing that action on that state, moreover it modifies the float parameter
     * into the reward of the transition
     */
    void*           (*transition)(void*, uint64_t, float*);

    /**
     * pointer to a function that takes a game state as a parameter and returns its encoding (the hashing function
     * must be perfect)
     */
     uint64_t       (*encodeGameState)(void*);

     /**
      * pointer to a function that takes a game state as a parameter and returns true if the state is terminal,
      * false otherwise
      */
      bool          (*isTerminal)(void*);

      /**
       * total state space size
       */
       uint64_t space_state_size;
} genericGame;


#endif //QLEARNING_MISCELLANEOUS_H
