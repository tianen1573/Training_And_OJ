struct Node
{
    Node * prev;
    Node * next;
    int key, val;

    Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr){};
    Node():key(0), val(0), prev(nullptr), next(nullptr) {};
};
class LRUCache {
public:
    LRUCache(int capacity) {

        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        capa = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(hash.count(key) == 0)
        {
            return -1;
        }

        Node *node = hash[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

        return  node->val;
    }
    
    void put(int key, int value) {

        //存在
        if(hash.count(key) != 0)
        {
            Node *node = hash[key];
            node->val = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            
            return ;
        }

        Node * node = new Node(key, value);
        if(size == capa)
        {
            Node * last = tail->prev;
            last->next->prev = last->prev;
            last->prev->next = last->next;
            hash.erase(last->key);
            delete last;
        }
        else
        {
            ++ size;
        }
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        hash[key] = node;
    }

private:

    void delNode(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }


    unordered_map<int, Node*> hash;
    Node * head;
    Node * tail;
    int size;
    int capa;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */