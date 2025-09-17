#include "compare.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

namespace fs = std;

// levenshtein distance
int lsDistance(const std::string& s1, const std::string& s2) {
    // TODO: decide whether to check if strings are not equal in or outside this function
    int size1 = s1.size();
    int size2 = s2.size();
    if (s1==s2) {
    return 0;
    }

    // From https://de.wikipedia.org/wiki/Levenshtein-Distanz
    // replace, insert, deletion = 1
    // init levenshtein distance matrix
    std::vector<std::vector<int>> ldm(size1+1, std::vector<int>(size2+1));
    for (int i = 0; i <= size1; i++) ldm[i][0] = i;
    for (int j = 0; j <= size2; j++) ldm[0][j] = j;

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
          if (s1[i-1] == s2[j-1]) {
            ldm[i][j] = ldm[i-1][j-1]; // do nothing
        } else {
                // minimize cost out of del, insert and substitution
                ldm[i][j] = std::min({ldm[i-1][j], ldm[i][j-1], ldm[i-1][j-1]}) + 1;
            }
        }
    }
    return ldm[size1][size2];
}
