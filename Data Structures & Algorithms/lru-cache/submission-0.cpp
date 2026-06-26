class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int size;
    int k=0;
    Node *head = NULL;
    Node *tail = NULL;
    void insertFront(Node *node)
    {
    node->prev = NULL;
    node->next = head;

    if(head)
        head->prev = node;

    head = node;

    if(tail == NULL)
        tail = node;
    }

    void remove(Node *node)
    {
        if(node->prev!=NULL)
        {
            node->prev->next=node->next;
        }
        else{
            head=node->next;
        }

        if(node->next!=NULL)
        {
            node->next->prev=node->prev;
        }
        else{
            tail=node->prev;
        }
    }
    LRUCache(int capacity) {
        size=capacity;
        
    }
    
    int get(int key) {
        if(mp.count(key)==0)
            return -1;

        Node *node = mp[key];

        remove(node);
        insertFront(node);

        return node->val;
    }
    
    void put(int key, int value) {
        
        
        if(mp.count(key))
        {
            Node *node=mp[key];
            node->val = value;
            remove(node);
            insertFront(node);


        }
        else{
            if(k>=size)
            {
                mp.erase(tail->key);

                Node *temp = tail;
                remove(temp);
                delete temp;
                k--;
            }
            k++;
            Node *node = new Node(key,value);
            insertFront(node);
            mp[key]=node;

        }
        
    }
};
