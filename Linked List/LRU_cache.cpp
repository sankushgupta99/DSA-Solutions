#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:

public:
    // constructor for cache
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int x, int y){
            key = x;
            value = y;
            next = NULL;
            prev = NULL;
        }
    };
    class Doubly_LL{
        public:
        Node* front;
        Node* back;
        Doubly_LL(){
            front = new Node(-1,-1);
            back = new Node(-1,-1);
            front->next = back;
            back->prev = front;
        }
    };
    int capacity;
    int size = 0;
    Doubly_LL* ll = new Doubly_LL();
    map<int,Node*> m1;
    LRUCache(int cap)
    {
        this->capacity = cap;
    }
    void insert_in_queue(Node* node){
        Node* prev_node;
        prev_node = ll->back->prev;
        node->prev = prev_node;
        node->next = ll->back;
        prev_node->next = node;
        ll->back->prev = node;
    }
    void delete_from_queue(Node* node){
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        if(prev_node!=NULL)
        prev_node->next = next_node;
        if(next_node!=NULL)
        next_node->prev = prev_node;
        node->next = NULL;
        node->prev = NULL;
    }
    // this function should return value corresponding to key
    int get(int key)
    {
        int val = -1;
        if(m1[key])
        {
            val = m1[key]->value;
            delete_from_queue(m1[key]);
            insert_in_queue(m1[key]);
        }
        return val;
    }
    
    // storing key, value pair
    void set(int key, int value)
    {
        if(!m1[key]){
            Node* temp = new Node(key,value);
            if(size < capacity){
                insert_in_queue(temp);
                m1[key] = temp;
                size++;
            }
            else{
                m1[ll->front->next->key] = NULL;
                delete_from_queue(ll->front->next);
                insert_in_queue(temp);
                m1[key] = temp;
            }
        }
        else{
            m1[key]->value = value;
            delete_from_queue(m1[key]);
            insert_in_queue(m1[key]);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}