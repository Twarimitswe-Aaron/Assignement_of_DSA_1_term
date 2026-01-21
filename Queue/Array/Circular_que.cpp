//Twarimitswe Aaron
//Igihozo Belise
//Wihogora Florence

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:
    int size;
    int *arr;
    int front;
    int rear;
    int remaining;   // remaining empty slots

    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        remaining = size;
    }

    bool isEmpty() {
        return remaining == size;
    }

    bool isFull() {
        return remaining == 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = val;
        remaining--;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << arr[front] << " is removed" << endl;
        front = (front + 1) % size;
        remaining++;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        int count = size - remaining;
        int i = front;

        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    bool working = true;
    int operation, val, size;

    cout << "Enter the size of the queue you need: ";
    cin >> size;

    CircularQueue circular(size);

    while (working) {
        cout << "\nCIRCULAR QUEUE OPTIONS\n";
        cout << "=====================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Get Front\n";
        cout << "5. Exit\n";
        cout << "Select the option: ";
        cin >> operation;

        switch (operation) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                circular.enqueue(val);
                break;

            case 2:
                circular.dequeue();
                break;

            case 3:
                circular.display();
                break;

            case 4:
                circular.getFront();
                break;

            case 5:
                working = false;
                break;

            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;
}
