class MaxStack {
    struct Node{
        int val;
        Node* next;
        Node* prev;

        Node(int val): val(val), next(nullptr),prev(nullptr){}
        // Node(int val, int max): val(val), max(max),next(nullptr), prev(nullptr){}
        Node(int val,Node* next): val(val), next(next), prev(nullptr){}
        Node(int val, Node* next, Node* prev): val(val), next(next), prev(prev){}
    };
public:
    Node* head;
    Node* tail;
    map<int,vector<Node*>>values;
    // int maxi;
    MaxStack() {
        head = tail = nullptr;
        // maxi = INT_MIN;
        values = {};
    }
    
    void push(int x) {
        if(!head){
            head = tail = new Node(x);
            // maxi =x;
            values[x].emplace_back(head);
        }
        else{
            auto newNode =new Node(x);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            values[x].emplace_back(newNode);
        }
    }
    
    int pop() {
        if(head == tail){
            int val = head->val;
            head = tail =nullptr;
            values[val].pop_back();
            if(values[val].empty()) values.erase(val);
            return val;
        }
        else{
            int result = tail->val;
            tail = tail->prev;
            tail->next = nullptr;
            values[result].pop_back();
            if(values[result].empty()) values.erase(result);
            return result;
        }
    }
    
    int top() {
        return tail->val;
    }
    
    int peekMax() {
        return std::prev(values.end())->first;
    }
    
    int popMax() {
        int currMax = std::prev(values.end())->first;
        auto iter = values[currMax].back();
        values[currMax].pop_back();
        if(values[currMax].empty())values.erase(currMax);
        if(iter==head && iter == tail){
            head = tail = nullptr;
            // return currMax;
        }
        else if(iter == head){
            head = head->next;
            head->prev = nullptr;
            // return currMax;
        }
        else if(iter == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }
        else{
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            // return currMax;
        }
        return currMax;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */