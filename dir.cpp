#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;


// Representing the file structure as an n-ary tree
class Node {
public:
    std::string fileOrfolder;
    std::vector<Node*> children; // children contained by this node
    bool isDir; // should be true if the node is a directory

    // Constructor
    Node(std::string filename, bool isDirectory):
    node(std::move(filename), checkIfDirectory(isDirectory) {}

    // Add a child if the passed node is a directory
    void addChild(Node* childNode) {
        if isDirectory {
        children.push_back(childNode);
        }
    }

    // Destructor (denoted by tilde ~)
    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};
