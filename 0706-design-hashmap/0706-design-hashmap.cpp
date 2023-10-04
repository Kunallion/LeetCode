class MyHashMap {
public:
    vector<pair<int, int>> arr;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int i;
        for(i=0 ; i<arr.size() ; i++)
        {
            if(arr[i].first==key)
            {
                arr[i].second = value;
                break;
            }
        }
        if(i==arr.size())
        {
            arr.push_back(make_pair(key, value));
        }
    }
    
    int get(int key) {
        int i;
        for(i=0 ; i<arr.size() ; i++)
        {
            if(arr[i].first==key)
            {
                return arr[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i;
        for(i=0 ; i<arr.size() ; i++)
        {
            if(arr[i].first==key)
            {
                arr.erase(arr.begin()+i);
                break;
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