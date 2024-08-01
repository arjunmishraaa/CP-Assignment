#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;
class HashMap {
public:
    HashMap(int sz) : size(sz), table(sz, {-1, 0}), chain(sz) {}

    void insert(int k, int v) {
        int idx = hash(k);
        while (table[idx].first != -1 && table[idx].first != k) {
            idx = (idx + 1) % size;
        }
        table[idx] = {k, v};
    }

    bool find(int k) {
        int idx = hash(k);
        while (table[idx].first != -1) {
            if (table[idx].first == k) return true;
            idx = (idx + 1) % size;
        }
        return false;
    }

    void remove(int k) {
        int idx = hash(k);
        while (table[idx].first != -1) {
            if (table[idx].first == k) {
                table[idx] = {-1, 0};  // Mark as deleted
                rehash();
                return;
            }
            idx = (idx + 1) % size;
        }
    }

    void insertChain(int k, int v) {
        int idx = hash(k);
        for (auto &p : chain[idx]) {
            if (p.first == k) {
                p.second = v;
                return;
            }
        }
        chain[idx].emplace_back(k, v);
    }

    bool findChain(int k) {
        int idx = hash(k);
        for (auto &p : chain[idx]) {
            if (p.first == k) return true;
        }
        return false;
    }

    void removeChain(int k) {
        int idx = hash(k);
        auto &lst = chain[idx];
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            if (it->first == k) {
                lst.erase(it);
                return;
            }
        }
    }

private:
    int size;
    vector<pair<int, int>> table;
    vector<list<pair<int, int>>> chain;

    int hash(int k) {
        return k % size;
    }

    void rehash() {
        vector<pair<int, int>> oldTable = table;
        table = vector<pair<int, int>>(size, {-1, 0});
        for (auto &p : oldTable) {
            if (p.first != -1) {
                insert(p.first, p.second);
            }
        }
    }
};

int main() {
    HashMap hm(10);
    return 0;
}
