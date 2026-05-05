#include <iostream>  
#include <string>    
#include "StoreTree.hpp" 


const std::string DATA_FILE = "store_db.txt";

void displayMenu() {
    std::cout << "\n----------------------------" << std::endl;
    std::cout << "   STORE MANAGEMENT SYSTEM   " << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "1. Add Node (Create)" << std::endl;
    std::cout << "2. Update Node Name (Update)" << std::endl;
    std::cout << "3. Delete Node (Delete)" << std::endl;
    std::cout << "4. Show Tree (Read All)" << std::endl;
    std::cout << "5. Search Node (Read)" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    std::string storeName = "MyStore";
 
    StoreSystem::Tree myStore(storeName);

    myStore.load(DATA_FILE);

    int choice;
    std::string name, parent, type, newName;

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            continue;
        }
        std::cin.ignore(); 

        if (choice == 6) break;

        switch (choice) {
            case 1:
                std::cout << "Parent Name: "; std::getline(std::cin, parent);
                std::cout << "Child Name: "; std::getline(std::cin, name);
                std::cout << "Category/Type: "; std::getline(std::cin, type);
                if (myStore.add(parent, name, type)) {
                    std::cout << BLUE << ">> Successfully added!" << RESET << std::endl;
                    myStore.save(DATA_FILE); 
                } else {
                    std::cout << ">> Error: Parent not found." << std::endl;
                }
                break;

            case 2:
                std::cout << "Current Node Name: "; std::getline(std::cin, name);
                std::cout << "New Node Name: "; std::getline(std::cin, newName);
                if (myStore.update(name, newName)) {
                    std::cout << BLUE << ">> Successfully updated!" << RESET << std::endl;
                    myStore.save(DATA_FILE); 
                } else {
                    std::cout << ">> Error: Node not found." << std::endl;
                }
                break;

            case 3:
                std::cout << "Node Name to Delete: "; std::getline(std::cin, name);
                if (myStore.remove(name)) {
                    std::cout << BLUE << ">> Successfully deleted!" << RESET << std::endl;
                    myStore.save(DATA_FILE); 
                } else {
                    std::cout << ">> Error: Node not found or cannot delete root." << std::endl;
                }
                break;

            case 4:
                std::cout << "\n--- Current Store Structure ---" << std::endl;
                myStore.show();
                break;

            case 5:
                std::cout << "Node Name to Find: "; std::getline(std::cin, name);

                if (StoreSystem::Node* found = myStore.find(name)) {
                    std::cout << BLUE << ">> Found: " << found->name << " [" << found->type << "]" << RESET << std::endl;
                    std::cout << BLUE << ">> It has " << found->children.size() << " children." << RESET << std::endl;
                } else {
                    std::cout << ">> Node not found." << std::endl;
                }
                break;

            default:
                std::cout << ">> Invalid choice, try again." << std::endl;
        }
    }

    return 0;
}
