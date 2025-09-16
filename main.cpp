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
    std::string path = ".";
    Tree tree(path);
    tree.print();

    return 0;
}
