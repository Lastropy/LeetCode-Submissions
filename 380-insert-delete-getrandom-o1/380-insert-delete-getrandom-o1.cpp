class RandomizedSet {
private:
    unordered_set<int> s;
    int size;
    
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end())
            return false;
        s.insert(val);
        size++;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())
            return false;
        s.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        // srand(time(0));
        
        int pos = (rand()) % size;
        auto it = s.begin();
        advance(it, pos);
        return (*it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */