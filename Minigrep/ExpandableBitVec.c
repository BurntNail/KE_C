#include <stdlib.h>
#include <limits.h>
#include "ExpandableBitVec.h"

const int NO_BITS = sizeof(int) * 8;

ExpandableBitVec EBV (int size) {
    ExpandableBitVec ebv;
    ebv.currentSize = size;
    ebv.backing = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        ebv.backing[i] = 0;
    }
    return ebv;
}

void ExtendToSize (ExpandableBitVec* self, int size) {
    if (size > self->currentSize) {
        int* newPtr = malloc(sizeof(int) * size);

        for (int i = 0; i < self->currentSize; i++) {
            newPtr[i] = self->backing[i];
        }
        for (int i = self->currentSize - 1; i < size; i++) {
            newPtr[i] = 0;
        }

        free(self->backing);
        self->backing = newPtr;
    }
}

bool Index (ExpandableBitVec* self, int index) {
    ExtendToSize(self, index + 1);

    int backing_ind = index / NO_BITS;
    int internal_ind = index % NO_BITS;

    return (self->backing[backing_ind] & (1 << internal_ind)) > 0;
}

void Set (ExpandableBitVec* self, int index) {
    ExtendToSize(self, index + 1);

    int backing_ind = index / NO_BITS;
    int internal_ind = index % NO_BITS;

    self->backing[backing_ind] |= 1 << internal_ind;
}

void Unset (ExpandableBitVec* self, int index) {
    ExtendToSize(self, index + 1);

    int backing_ind = index / NO_BITS;
    int internal_ind = index % NO_BITS;

    self->backing[backing_ind] &= INT_MAX - (1 << internal_ind);
}

void Clear (ExpandableBitVec* self) {
    for (int i = 0; i < self->currentSize; i++) {
        self->backing[i] = 0;
    }
}