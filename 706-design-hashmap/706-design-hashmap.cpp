class MyHashMap {
private: 
    vector<int> hashval;
    
public:
    MyHashMap() {
        hashval.resize(1e6+1, -1);
    }
    
    void put(int key, int value) {
        hashval[key] = value;
    }
    
    int get(int key) {
        return hashval[key];
    }
    
    void remove(int key) {
        hashval[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */