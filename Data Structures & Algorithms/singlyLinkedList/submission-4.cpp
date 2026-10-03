class Node{
public:
    Node *next;
    int data;
    Node(int val): data(val), next(NULL){}
    Node(int val, Node *next): data(val), next(next){}
};
class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node *it = head;
        while(index-- && it){
            it = it->next;
        }
        return it ? it->data : -1;
    }

    void insertHead(int val) {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
    }
    
    void insertTail(int val) {
        Node *newTail = new Node(val);
        if(!head){
            head = newTail;
            return;
        }
        Node *it = head;
        while(it->next){
            it = it->next;
        }
        it->next = newTail;
    }

    bool remove(int index) {
        Node *prev = NULL;
        Node *curr = head;
        while(index-- && curr){
            prev = curr;
            curr = curr->next;
        }
        if(curr){
            if(!prev){
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values;
        for(Node *it = head; it != NULL; it = it->next){
            values.push_back(it->data);
        }
        return values;
    }
};