class MyCircularQueue {
public:

    struct Node {
        int val;
        Node *next;

        Node(int val) {
            this->val = val;
            next = NULL;
        }
    };

    int size;
    int i = 0;

    Node *head = NULL;
    Node *tail = NULL;

    MyCircularQueue(int k) {
        size = k;
    }

    bool enQueue(int value) {

        if(i == size)
            return false;

        Node *nnode = new Node(value);

        if(i == 0)
        {
            head = nnode;
            tail = nnode;
            nnode->next = head;
        }
        else
        {
            nnode->next = head;
            tail->next = nnode;
            tail = nnode;
        }

        i++;

        return true;
    }

    bool deQueue() {

        if(i == 0)
            return false;

        if(i == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;

            head = head->next;
            tail->next = head;

            delete temp;
        }

        i--;

        return true;
    }

    int Front() {
        if(i == 0)
            return -1;

        return head->val;
    }

    int Rear() {
        if(i == 0)
            return -1;

        return tail->val;
    }

    bool isEmpty() {
        return i == 0;
    }

    bool isFull() {
        return i == size;
    }
};