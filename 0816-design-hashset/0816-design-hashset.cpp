class MyHashSet {
private:
    set<int>HashSet;
public:
    MyHashSet() {
        HashSet.clear();
    }
    
    void add(int key) {
        HashSet.insert(key);
    }
    
    void remove(int key) {
        for(auto i = HashSet.begin();i!=HashSet.end();i++){
            if(*i==key){
                HashSet.erase(i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        for(int numbers: HashSet){
            if(numbers == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */