class MyQueue {
private:
    stack<int> a, b;

    void t() {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if (b.empty()) {
            t();
        }
        int front = b.top();
        b.pop();
        return front;
    }
    
    int peek() {
        if (b.empty()) {
            t();
        }
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};