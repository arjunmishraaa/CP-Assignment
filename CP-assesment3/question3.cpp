#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
private:
    int cap;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int cap) : cap(cap) {}

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        lst.splice(lst.begin(), lst, m[key]);
        return m[key]->second;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            lst.splice(lst.begin(), lst, m[key]);
            m[key]->second = value;
        } else {
            if (lst.size() == cap) {
                m.erase(lst.back().first);
                lst.pop_back();
            }
            lst.emplace_front(key, value);
            m[key] = lst.begin();
        }
    }
};
int main() {
    LRUCache cache(2);
    

}