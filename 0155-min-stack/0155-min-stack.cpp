class MinStack {
public:
    vector<pair<int,int>> arr;
    MinStack() {
        
    }
    
    void push(int val) {
        if(arr.size()==0)
        {
            arr.push_back(make_pair(val,val));
        }
        else
        {
            arr.push_back(make_pair(val, min(arr.back().second, val)));
        }
    }
    
    void pop() {      
        arr.erase(arr.begin()+arr.size()-1);
    }
    
    int top() {
        if(arr.size()>0)
        {
            return arr[arr.size()-1].first;
        }
        return -1;
    }
    
    int getMin() {
        return arr[arr.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */