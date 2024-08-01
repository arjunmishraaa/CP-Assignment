class CustomStack {
private:
    int mxSize;
    vector<int> stk;
    vector<int> inc;
public:
    CustomStack(int maxSize) : mxSize(maxSize) {
        stk.reserve(maxSize);
        inc.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (stk.size() < mxSize) {
            stk.push_back(x);
        }
    }
    
    int pop() {
        if (stk.empty()) return -1;
        int idx = stk.size() - 1;
        int icr = inc[idx];
        if (idx > 0) {
            inc[idx - 1] += inc[idx];
        }
        inc.pop_back();
        int res = stk.back() + icr;
        stk.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int idx = min(k, static_cast<int>(stk.size())) - 1;
        if (idx >= 0) {
            inc[idx] += val;
        }
    }
};