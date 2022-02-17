//
// Created by giaco on 15/02/2022.
//

#include <malloc.h>
#include <stdio.h>
#include "miscellaneous.h"

unsignedArray unsignedArray_create(uint64_t max_size) {
    uint64_t* arr = malloc(sizeof(uint64_t) * max_size);
    if(!arr) {
        fprintf(stderr, "Error: couldn't allocate memory for array\n");
        return unsignedArray_err();
    }
    unsignedArray result = {
            .arr = arr,
            .max_size = max_size,
            .size = 0
    };
    return result;
}

unsignedArray unsignedArray_err() {
    unsignedArray result = {
            .arr = NULL,
            .max_size = 0,
            .size = 0
    };
    return result;
}

void unsignedArray_destroy(unsignedArray ua) {
    free(ua.arr);
}

void unsignedArray_push(unsignedArray* ua, uint64_t element) {
    if(ua->size == ua->max_size) {
        fprintf(stderr, "Error: array is full: cannot add more moves\n");
    }
    ua->arr[ua->size] = element;
    ua->size++;
}

