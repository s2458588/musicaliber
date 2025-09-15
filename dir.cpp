#include "dir.h"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

// Node representing files and dir
struct Node {
    std::string name;
    bool isDirectory;
    std::vector<Node> children;

    Node(const std::string& n, bool isDir)
        : name(n), isDirectory(isDir) {}
};

// Class to build a file tree
class Tree {
private:
    Node root;

    void buildTree(Node& node, const fs::path& path) {
        if (!fs::is_directory(path)) return;

        for (const auto& entry : fs::directory_iterator(path)) {
            bool isDir = fs::is_directory(entry.path());
            Node child(entry.path().filename().string(), isDir);
            node.children.push_back(child);

            if (isDir) {
                buildTree(node.children.back(), entry.path());
            }
        }
    }

public:
    Tree(const std::string& rootPath)
        : root(rootPath, true) {
        buildTree(root, fs::path(rootPath));
    }

    // TODO: provide this as functionality for preview mode
    void printTree(const Node& node, int depth = 0) const {
        std::string indent(depth * 2, ' ');
        std::cout << indent
                  << (node.isDirectory ? "[D] " : "[F] ")
                  << node.name << "\n";
        for (const auto& child : node.children) {
            printTree(child, depth + 1);
        }
    }

    void print() const {
        printTree(root);
    }

    // TODO: deconstructor needed
};

// Print tree test
int main() {
    std::string path = "..";
    Tree tree(path);

    //tree.print();
    return 0;
}
