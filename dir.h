#pragma once

#include <string>
#include <vector>
#include <filesystem>

struct Node {
    std::string name;
    bool isDirectory;
    std::vector<Node> children;

    Node(const std::string& n, bool isDir)
        : name(n), isDirectory(isDir) {}

    // TODO: get processed pseudo-name for levenshtein distance comparison
    std: string processedName;
};

class Tree {
public:
    Tree(const std::string& rootPath);

    // TODO: remove when finished
    void printTree(Node& node, int depth = 0) const;
    void print() const;
private:
    Node root;
    void buildTree(Node& node, const std::filesystem::path& path);
    void printTree(const Node& node, int depth=0) const;
    void iterTree(const Node& node, int depth=2) const;
};
