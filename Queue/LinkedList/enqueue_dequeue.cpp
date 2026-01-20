#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear  = nullptr;

bool isEmpty();

void enqueue(int val){
    Node* t = new Node;
    t->data = val;
    t->next = nullptr;

    if(isEmpty()){
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    if(isEmpty()){
        cout << "Queue is empty ";
        return -1;
    }

    Node* p = front;
    int value = p->data;
    front = front->next;

    if(front == nullptr){
        rear = nullptr;
    }

    delete p;
    return value;
}

void display(){
    if(isEmpty()){
        cout << "Queue is empty";
        return;
    }

    Node* p = front;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

bool isEmpty(){
    return front == nullptr;
}

int main(){
    int option, val;

    while(true){
        cout << "\nQUEUE OPERATIONS\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Option: ";
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                cout << dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option";
        }
    }
}
