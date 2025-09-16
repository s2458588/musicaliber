#include "dir.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// Tree implementation
Tree::Tree(const std::string& rootPath)
    : root(rootPath, true)
{
    buildTree(root, fs::path(rootPath));
}

void Tree::buildTree(Node& node, const fs::path& path) {
    if (!fs::is_directory(path)) return;

    for (const auto& entry : fs::directory_iterator(path)) {
        bool isDir = fs::is_directory(entry.path());
        Node child(entry.path().filename().string(), isDir);
        node.children.push_back(child); //std::move(child)?

        if (isDir) {
            buildTree(node.children.back(), entry.path());
        }
    }
}

// TODO: provide this as functionality for preview mode
void Tree::printTree(const Node& node, int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent
              << (node.isDirectory ? "[D] " : "[F] ")
              << node.name << "\n";
    for (const auto& child : node.children) {
        printTree(child, depth + 1);
    }
}

void Tree::print() const {
    printTree(root);
}
