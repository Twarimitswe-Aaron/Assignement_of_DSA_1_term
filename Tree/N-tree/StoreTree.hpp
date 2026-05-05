#ifndef STORE_TREE_HPP
#define STORE_TREE_HPP

#include <iostream>  
#include <vector>    
#include <string>    


const std::string RESET = "\033[0m";  
const std::string BLUE = "\033[1;34m";   
const std::string GREEN = "\033[1;32m";  

namespace StoreSystem {

    struct Node {
        std::string name;            
        std::string type;            
        std::vector<Node*> children; 
        
        Node(std::string n, std::string t) : name(n), type(t) {}
        
        ~Node() {
            for (Node* child : children) {
                delete child; 
            }
        }
    };

    class Tree {
    private:
        Node* root; 

        Node* findRecursive(Node* current, const std::string& name);
        void printRecursive(Node* current, int depth);

    public:
        Tree(std::string storeName); 
        ~Tree();                

        bool add(std::string parentName, std::string name, std::string type); 
        Node* find(std::string name);                              
        bool update(std::string oldName, std::string newName);           
        bool remove(std::string name);                             
        
        void show(); 

        void save(std::string filename); 
        void load(std::string filename); 
    };

} 

#endif 
