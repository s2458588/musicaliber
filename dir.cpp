#include "dir.h"
#include <iostream>
#include <filesystem>
#include <regex>
#include <string>

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

// TODO: make tree class return a structure that contains only until depth 2 (root > artist > album > song.file)
void Tree::iterTree(const Node& node, int depth) const {
    std::regex yearPat("^\\(?\\d{4}\\)?");
    std::regex trimPat("^\\s+|\\s+$");

    for (const auto& child : node.children) {
        // Remove possible date prefix and trim white spaces for levenshtein distance comparison
        child.processedName = std::regex_replace(node.name, yearPat, "");
        if (child.isDirectory) {
            child.processedName = std::regex_replace(child.processedName, trimPat, "");
        }
        iterTree(const Node& node, depth);
    }
    // check RAM occupied by tree
    std::cout << sizeof(node) << "bytes";
}
