#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, capacity, count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == capacity)
            return;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (count == 0)
            return;
        front = (front + 1) % capacity;
        count--;
    }

    int peek() {
        if (count == 0)
            return -1;
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    int size() {
        return count;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout << q.size() << endl;
    cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl;
    cout << (q.isFull() ? "Full" : "Not Full") << endl;
    return 0;
}
