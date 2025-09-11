#include <vector>
#include <string>

namespace fs = std;

// test struct
struct TestNode {
    std::string name;
    bool isDirectory;
    std::vector<Node> children;

    Node(const std:string& n, bool isDir)
         : name(n), isDirectory(isDir) {}
};

// levenshtein distance
int lsDistance(string s1, string s2) {
    int size1 = s1.size();
    int size2 = s2.size();

    // TODO: Tabelle aus Beispiel https://de.wikipedia.org/wiki/Levenshtein-Distanz implementieren
}
