class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int count=0;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        count++;
    }
    
    int pop() {
        int i, ans;
        for(i=0 ; i<count-1 ; i++)
        {
            ans = q1.front();
            q1.pop();
            q2.push(ans);
        }
        ans = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        count--;
        return ans;
    }
    
    int top() {
        int i, ans;
        for(i=0 ; i<count ; i++)
        {
            ans = q1.front();
            q1.pop();
            q2.push(ans);
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */