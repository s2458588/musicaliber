#include "compare.h"
#include "dir.h"
#include <iostream>
#include <string>

int main (void){
    // test lsd
    std::string s1 = "Soos";
    std::string s2 = "Sees";
    int lsdist = lsDistance(s1, s2);
    std::cout << "Soos -> Sees: " << lsdist <<"\n";
    return 0;

    // test tree builder
    Tree tree(".");
    tree.printTree();

    return 0;
}

// TODO: fix the double class definition in dir.h/cpp
