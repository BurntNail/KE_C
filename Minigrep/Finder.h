#pragma once

#include "ExpandableBitVec.h"

typedef struct Match {
    int start;
    int end;
} Match;

typedef struct Matches {
    Match* matches;
    int count;
} Matches;

Matches findMatches (char* text, char* pattern);
void MatchesToEBV (Matches matches, ExpandableBitVec* ebv, int total_size);