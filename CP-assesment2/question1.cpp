class MyStack {
private:
queue<int> a, b;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        b.push(x);
        while (!a.empty()) {
            b.push(a.front());
            a.pop();
        }
        swap(a, b);
    }
    
    int pop() {
        int top = a.front();
        a.pop();
        return top;
    }
    
    int top() {
         return a.front();
    }
    
    bool empty() {
         return a.empty();
    }
};