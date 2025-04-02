class MyCircularDeque {
    private:
    struct ListNode{
        int val;
        ListNode* next;

        ListNode(int c) : val(c) , next(nullptr){}
        ListNode(int c, ListNode* next) : val(c) , next(next){}
    };
    
    ListNode* front;
    ListNode* rear;
    int capacity;
    int currentsize;
public:
    MyCircularDeque(int k) {
        front = nullptr;
        rear = nullptr;
        currentsize= 0;
        capacity =k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front = rear = new ListNode(value);
        }
        else{
            ListNode* newNode= new ListNode(value);
            newNode->next = front;
            front = newNode;
        }
        currentsize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front = rear = new ListNode(value);
        }
        else{
            rear->next = new ListNode(value);
            rear = rear->next;
        }
        currentsize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(front == rear){
            front = rear = nullptr;
            currentsize=0;
        }
        else{
            front = front->next;
            currentsize--;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(front == rear){
            front = rear = nullptr;
            currentsize=0;
        }
        else{
            ListNode* current = front;
            while(current->next->next){
                current = current->next;
            }
            rear = current;
            rear->next = nullptr;
            currentsize--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return front->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return currentsize == 0;
    }
    
    bool isFull() {
        return currentsize== capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */