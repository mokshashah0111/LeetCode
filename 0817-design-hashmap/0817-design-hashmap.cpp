class MyHashMap {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key,int val) : key(key),val(val), next(nullptr), prev(nullptr){}
        Node(int key, int val, Node* next) : key(key),val(val), next(next), prev(nullptr){}
    };
    Node* head;
    Node* tail;
    MyHashMap() {
        head = tail = nullptr;
    }
    
    void put(int key, int value) {
        if(!head){
            head = tail = new Node(key,value);
        }
        else{
            auto dummy = head;
            while(dummy){
                if(dummy->key == key){
                    dummy->val= value;
                    break;
                }
                dummy = dummy->next;
            }
            if(dummy == nullptr){
                auto node = new Node(key,value);
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
    }
    
    int get(int key) {
        if(!head) return -1;
        auto dummy = head;
        while(dummy){
            if(dummy->key == key)return dummy->val;
            dummy = dummy->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head == nullptr)return;
        if(head == tail && head->key == key){
            head = tail = nullptr;
        }
        else if(head->key == key){
            head = head->next;
            head->prev = nullptr;
        }
        else if(tail->key == key){
            tail = tail->prev;
            tail->next = nullptr;
        }
        else{
            auto dummy = head;
            while(dummy){
                if(dummy->key == key){
                    auto prev = dummy->prev;
                    auto next = dummy->next;
                    prev->next = next;
                    next->prev = prev;
                    delete dummy;
                    break;
                }
                dummy = dummy->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */