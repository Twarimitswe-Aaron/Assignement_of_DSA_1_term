//Twarimitswe Aaron
//Kamana Clare
//Igihozo Belise

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;   // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;   // maintain circle
        }

        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }

        if (front == rear) {
            cout << "Dequeued: " << front->data << endl;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Dequeued: " << temp->data << endl;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int option, val;
    bool running = true;

    while (running) {
        cout << "\nCIRCULAR QUEUE OPERATIONS\n";
        cout << "========================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                queue.enqueue(val);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                running = false;
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
