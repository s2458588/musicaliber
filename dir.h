#pragma once

#include <string>

class Tree {
public:
    // explicit is preventing the compiler from implicitly converting the function parameter via the constructor
    explicit Tree(const std::string& path);

    // TODO: remove when finished
    void printTree() const;

private:
    void buildTree(const std::string& path, int depth);

    void indent(int depth) const;
    std::string rootDir;
};
