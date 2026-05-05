#include "StoreTree.hpp"  
#include <fstream>         
#include <sstream>         

// No 'using namespace' here!

StoreSystem::Tree::Tree(std::string storeName) {
    root = new Node(storeName, "Store"); 
}

StoreSystem::Tree::~Tree() {
    delete root; 
}

StoreSystem::Node* StoreSystem::Tree::findRecursive(Node* current, const std::string& name) {
    if (current->name == name) return current;

    for (Node* child : current->children) {
        Node* found = findRecursive(child, name);
        if (found) return found;
    }
    return nullptr;
}

StoreSystem::Node* StoreSystem::Tree::find(std::string name) {
    return findRecursive(root, name);
}

bool StoreSystem::Tree::add(std::string parentName, std::string name, std::string type) {
    Node* parent = find(parentName);
    if (!parent) return false;

    for (Node* child : parent->children) {
        if (child->name == name) {
            std::cout << ">> Error: '" << name << "' already exists." << std::endl;
            return false; 
        }
    }

    parent->children.push_back(new Node(name, type));
    return true;
}

bool StoreSystem::Tree::update(std::string oldName, std::string newName) {
    Node* node = find(oldName);
    if (node) {
        node->name = newName;
        return true;
    }
    return false;
}

bool StoreSystem::Tree::remove(std::string name) {
    if (root->name == name) return false;

    std::vector<Node*> stack = {root};
    while (!stack.empty()) {
        Node* current = stack.back();
        stack.pop_back();

        for (auto it = current->children.begin(); it != current->children.end(); ++it) {
            if ((*it)->name == name) {
                delete *it;            
                current->children.erase(it);
                return true;
            }
            stack.push_back(*it);
        }
    }
    return false;
}

void StoreSystem::Tree::printRecursive(Node* current, int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << (i == depth - 1 ? "|-- " : "    ");
    }
    std::cout << BLUE << current->name << " [" << current->type << "]" << RESET << std::endl;

    for (Node* child : current->children) {
        printRecursive(child, depth + 1);
    }
}

void StoreSystem::Tree::show() {
    printRecursive(root, 0);
}

void saveNodeRecursive(StoreSystem::Node* current, int depth, std::ofstream& file) {
    file << depth << "," << current->name << "," << current->type << std::endl;
    for (StoreSystem::Node* child : current->children) {
        saveNodeRecursive(child, depth + 1, file);
    }
}

void StoreSystem::Tree::save(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveNodeRecursive(root, 0, file);
        file.close();
    }
}

void StoreSystem::Tree::load(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    std::vector<StoreSystem::Node*> lastNodeAtDepth(100, nullptr);

    for (Node* child : root->children) delete child;
    root->children.clear();

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string sDepth, name, type;
        
        if (!std::getline(ss, sDepth, ',')) continue;
        if (!std::getline(ss, name, ',')) continue;
        if (!std::getline(ss, type, ',')) continue;

        int depth = std::stoi(sDepth);

        if (depth == 0) {
            root->name = name;
            root->type = type;
            lastNodeAtDepth[0] = root;
        } else {
            StoreSystem::Node* newNode = new StoreSystem::Node(name, type);
            StoreSystem::Node* parent = lastNodeAtDepth[depth - 1];
            if (parent) {
                parent->children.push_back(newNode);
                lastNodeAtDepth[depth] = newNode;
            }
        }
    }
    file.close();
}
