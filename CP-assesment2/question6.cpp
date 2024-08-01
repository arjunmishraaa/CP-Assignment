class StockSpanner {
private:
    stack<pair<int, int>> a; 
    
public:
    StockSpanner() {
    }
    
    int next(int b) {
        int c = 1; 
        while (!a.empty() && a.top().first <= b) {
            c += a.top().second;
            a.pop(); 
        }
        a.push({b, c}); 
        return c;
    }
};