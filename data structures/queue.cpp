template<typename T>
struct Node {
    
    T val;
    Node *next;

    Node(T x) {
        val = x;
        next = NULL;
    }

};

template<typename T>
struct Queue {
    
private:

    int _size;
    Node<T> *head;
    Node<T> *tail;

public:

    Queue() {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    void push(T x) {
        Node<T> *node = new Node<T>(x);
        
        if (size() == 0) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        _size++;
    }

    T pop() {
        T res = front();

        Node<T> *next = head->next;
        free(head);
        head = next;
        
        _size--;

        return res;
    }

    T front() {
        if (size() == 0) {
            throw 1;
        }

        return head->val;
    }

    int size() {
        return _size;
    }

    void clear() {
        _size = 0;

        while (head) {
            Node<T> *next = head->next;
            free(head);
            head = next;
        }
    }

};
