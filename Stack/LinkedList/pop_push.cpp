#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;      // maximum size
    int count;     // current size

public:
    Stack(int size) {
        this->size = size;
        top = nullptr;
        count = 0;
    }

    void push(int num) {
        if (count < size) {
            Node* newNode = new Node(num);
            newNode->next = top;
            top = newNode;
            count++;
        }
    }

    int pop() {
        if (top == nullptr) {
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return value;
    }

    int getSize() {
        return count;
    }

    bool empty() {
        return top == nullptr;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int size, operation;
    bool running = true;

    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    while (running) {
        cout << "\nChoose 1 option" << endl;
        cout << "===============" << endl;
        cout << "1.push" << endl;
        cout << "2.pop" << endl;
        cout << "3.size" << endl;
        cout << "4.display" << endl;
        cout << "5.end" << endl;

        cin >> operation;

        switch (operation) {
            case 1: {
                int noElm, elm;
                cout << "Enter number of elements you want to add: ";
                cin >> noElm;

                int remaining = size - stack.getSize();
                if (noElm > remaining) {
                    cout << "Elements are exceeding the size" << endl;
                    cout << "Currently you have " << stack.getSize()
                         << " elements and the maximum is " << size << endl;
                    cout << "Remaining slots: " << remaining << endl;
                } else {
                    for (int i = 0; i < noElm; i++) {
                        cout << "Enter element to push: ";
                        cin >> elm;
                        stack.push(elm);
                    }
                }
                break;
            }
            case 2:
                stack.pop();
                break;

            case 3:
                cout << stack.getSize() << endl;
                break;

            case 4:
                stack.display();
                break;

            case 5:
                running = false;
                break;

            default:
                cout << "Enter a valid option" << endl;
        }
    }

    return 0;
}
