class RandomizedCollection {
private:
    map<int, vector<int>> a; 
    vector<pair<int, int>> b;        
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool notPresent = a.find(val) == a.end();
        a[val].push_back(b.size());
        b.push_back({val, a[val].size() - 1});
        return notPresent;
    }
    
    bool remove(int val) {
        if (a.find(val) == a.end()) {
            return false;
        }
        auto last = b.back();
        int idx = a[val].back();
        b[idx] = last;
        a[last.first][last.second] = idx;
        a[val].pop_back();
        if (a[val].empty()) {
            a.erase(val);
        }
        b.pop_back();
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % b.size();
        return b[randomIndex].first;
    }
};