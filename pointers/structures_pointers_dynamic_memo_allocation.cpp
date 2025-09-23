#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string address;
    string phone_number;
};

Contact* createContact(int size) {
    return new Contact[size];
}

void addNewEntry(Contact* contact, string name, string address, string phone_number, int index) {
    contact[index].name = name;
    contact[index].address = address;
    contact[index].phone_number = phone_number;
}

void displayContacts(Contact* contact, int size, int count) {
    cout << "Contact List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name:" << contact[i].name 
             << ", Address:" << contact[i].address 
             << ", Phone Number:" << contact[i].phone_number << endl;
    }
}

bool searchByContact(Contact* contact, int size, string phone_number, int count) {
    for (int i = 0; i < count; i++) {
        if (contact[i].phone_number == phone_number) {
            cout << "Contact Found: Name:" << contact[i].name 
                 << ", Address:" << contact[i].address 
                 << ", Phone Number:" << contact[i].phone_number << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int size, choice;
    int currentIndex = 0; // tracks how many contacts are added
    Contact* contact = nullptr;

    cout << "Enter number of contacts: ";
    cin >> size;

    contact = createContact(size);

    bool running = true;
    while (running) {
        cout << "\nMenu:\n1. Add New Entry\n2. Display Contacts\n3. Search by Phone Number\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (currentIndex >= size) {
                cout << "Address book is full!\n";
                break;
            }

            string name, address, phone_number;
            cout << "\nEnter Name: ";
            cin >> name;
            cout << "Enter Address: ";
            cin >> address;  // replace with getline(cin, address) if you want spaces
            cout << "Enter Phone Number: ";
            cin >> phone_number;

            addNewEntry(contact, name, address, phone_number, currentIndex);
            currentIndex++;
            break;
        }

        case 2:
            displayContacts(contact, size, currentIndex);
            break;

        case 3: {
            string phone_number;
            cout << "\nEnter Phone Number to Search: ";
            cin >> phone_number;
            if (!searchByContact(contact, size, phone_number, currentIndex)) {
                cout << "Contact Not Found!" << endl;
            }
            break;
        }

        case 4:
            cout << "Exiting..." << endl;
            running = false;
            break;

        default:
            cout << "Invalid option!" << endl;
        }
    }

    if (contact != nullptr) {
        delete[] contact;
    }

    return 0;
}
