#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
private:
    int size;
    int front;
    int rear;
    int count;
    int* arr;

public:
    // Constructor
    ArrayQueue(int size) {
        this->size = size;
        front = 0;
        rear = -1;
        count = 0;
        arr = new int[size];
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == size;
    }

    // Enqueue operation
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        arr[++rear] = val;
        count++;
        cout << "Element enqueued\n";
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int removed = arr[0];

        // Shift elements to the left
        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }

        rear--;
        count--;
        return removed;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, option, val;

    cout << "Enter the size of the queue: ";
    cin >> size;

    ArrayQueue q(size);

    while (true) {
        cout << "\nQUEUE OPERATIONS\n";
        cout << "================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Get Front\n";
        cout << "5. Exit\n";
        cout << "Option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;

        case 2:
            cout << "Removed: " << q.dequeue() << endl;
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Front element: " << q.getFront() << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid option\n";
        }
    }
}
