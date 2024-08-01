class MyLinkedList {
private:
    struct Node {
        int a;       
        Node* b;    
        Node(int x) : a(x), b(nullptr) {}
    };
    
    Node* c; 
    int d;    

public:
    MyLinkedList() : c(nullptr), d(0) {
    }
    
    int get(int e) {
        if (e < 0 || e >= d) {
            return -1;
        }
        Node* f = c;
        for (int i = 0; i < e; ++i) {
            f = f->b;
        }
        return f->a;
    }
    
    void addAtHead(int g) {
        Node* h = new Node(g);
        h->b = c;
        c = h;
        ++d;
    }
    
    void addAtTail(int i) {
        Node* j = new Node(i);
        if (!c) {
            c = j;
        } else {
            Node* k = c;
            while (k->b) {
                k = k->b;
            }
            k->b = j;
        }
        ++d;
    }
    
    void addAtIndex(int l, int m) {
        if (l > d || l < 0) {
            return;
        }
        if (l == 0) {
            addAtHead(m);
            return;
        }
        Node* n = new Node(m);
        Node* o = c;
        for (int i = 0; i < l - 1; ++i) {
            o = o->b;
        }
        n->b = o->b;
        o->b = n;
        ++d;
    }
    
    void deleteAtIndex(int p) {
        if (p < 0 || p >= d) {
            return;
        }
        if (p == 0) {
            Node* q = c;
            c = c->b;
            delete q;
        } else {
            Node* r = c;
            for (int i = 0; i < p - 1; ++i) {
                r = r->b;
            }
            Node* q = r->b;
            r->b = q->b;
            delete q;
        }
        --d;
    }
};