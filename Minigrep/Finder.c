#include <string.h>
#include <stdlib.h>
#include "Finder.h"

Matches findMatches (char* text, char* pattern) {
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    if (pattern_length == 0) {
        Matches m;
        m.count = 0;
        m.matches = malloc(0);
        return m;
    }

    Match* maxMatches = malloc(sizeof(Match) * ((text_length / pattern_length) + 1));
    int matchesFound = 0;

    for (int i = 0; i < text_length - pattern_length; i++) {
        char current = text[i];

        if (current == pattern[0]) {
            bool works = true;
            for (int offset = 1; offset < pattern_length; offset++) {
                if (text[i + offset] != pattern[offset]) {
                    works = false;
                    break;
                }
            }

            if (works) {
                Match m;
                m.start = i;
                m.end = i + pattern_length - 1;
                maxMatches[matchesFound] = m;
                matchesFound++;
            }
        }
    }

    Match* matches = malloc(sizeof(Match) * matchesFound);
    for (int i = 0; i < matchesFound; i++) {
        matches[i] = maxMatches[i];
    }
    free(maxMatches);



    Matches m;
    m.matches = matches;
    m.count = matchesFound;

    return m;
}

void MatchesToEBV (Matches matches, ExpandableBitVec* ebv, int total_size) {
    ExtendToSize(ebv,total_size);

    for (int i = 0; i < matches.count; i++) {
        Match m = matches.matches[i];

        for (int ebv_i = m.start; ebv_i <= m.end; ebv_i++) {
            Set(ebv, ebv_i);
        }
    }
}