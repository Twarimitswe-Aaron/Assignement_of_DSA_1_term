#include<bits/stdc++.h>

using namespace std;

int queue_arr[100], n=100, front=-1; // Renamed 'queue' to 'queue_arr' to avoid conflict with std::queue
int rear=-1;

void enqueue(int val){
    if(rear == n-1){
        cout << "Queue Overflow/Full" << endl;
    } else {
        if(front == -1) front = 0;
        rear++;
        queue_arr[rear] = val;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "Queue Underflow/Empty" << endl;
        return;
    }
    
    cout << "Element deleted: " << queue_arr[front] << endl;

    // Shifting elements to the left
    for(int i = 0; i < rear; i++){
        queue_arr[i] = queue_arr[i+1];
    }
    
    rear--; // Decrement rear after shifting
    
    // Reset pointers if queue becomes empty
    if (rear == -1) front = -1; 
}

void display(){
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    for(int i = 0; i <= rear; i++){
        cout << queue_arr[i] << " "; // Print the VALUE, not the index
    }
    cout << endl;
}

int main(){
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    
    cout << "Initial Queue: ";
    display();
    
    dequeue();
    
    cout << "Queue after dequeue: ";
    display();
    
    return 0;
}