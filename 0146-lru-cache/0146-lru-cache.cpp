class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(), l, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(), l, mp[key]);
            mp[key]->second = value;
            return;
        }
        if(l.size()==size)
        {
            int dkey = l.back().first;
            l.pop_back();
            mp.erase(dkey);
        }
        l.push_front(make_pair(key, value));
        mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */