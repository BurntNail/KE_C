#pragma once

#include <stdbool.h>

typedef struct ExpandableBitVec {
    int currentSize;
    int* backing;
} ExpandableBitVec;

ExpandableBitVec EBV (int size);
void ExtendToSize (ExpandableBitVec* self, int size);
bool Index (ExpandableBitVec* self, int index);
void Set (ExpandableBitVec* self, int index);
void Unset (ExpandableBitVec* self, int index);
void Clear (ExpandableBitVec* self);