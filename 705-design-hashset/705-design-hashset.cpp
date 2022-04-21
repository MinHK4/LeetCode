/*
class MyHashSet {
private:
    set<int> s;
    
public:
    MyHashSet() { 
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(s.find(key));
    }
    
    bool contains(int key) {
        if(s.find(key) == s.end())
            return false;
        return true;
    }
};
*/

class MyHashSet {
private:
    vector<bool> hash;
    
public:
    MyHashSet() {
        hash.resize(1e6+1, false);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */