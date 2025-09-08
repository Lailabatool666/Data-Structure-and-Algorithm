#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1)
            return;
        arr[++top] = x;
    }

    void pop() {
        if (top == -1)
            return;
        top--;
    }

    int peek() {
        if (top == -1)
            return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.size() << endl;
    cout << (st.isEmpty() ? "Empty" : "Not Empty") << endl;
    cout << (st.isFull() ? "Full" : "Not Full") << endl;
    return 0;
}
