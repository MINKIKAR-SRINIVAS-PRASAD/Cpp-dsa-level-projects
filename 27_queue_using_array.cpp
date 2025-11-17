#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> arr;
    int front, rear, size;
    
public:
    Queue(int capacity) : size(0), front(0), rear(-1) {
        arr.resize(capacity);
    }
    
    void enqueue(int x) {
        if(size == arr.size()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % arr.size();
        arr[rear] = x;
        size++;
    }
    
    int dequeue() {
        if(isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % arr.size();
        size--;
        return val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    
    return 0;
}