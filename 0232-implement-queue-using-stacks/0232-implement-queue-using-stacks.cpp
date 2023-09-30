class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int top=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        top++;
    }
    
    int pop() {
        int i=0, num;
        for(i=0 ; i<top-1 ; i++)
        {
            num = s1.top();
            s1.pop();
            s2.push(num);
        }
        num = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        top--;
        return num;
    }
    
    int peek() {
        int i=0, num;
        for(i=0 ; i<top-1 ; i++)
        {
            num = s1.top();
            s1.pop();
            s2.push(num);
        }
        num = s1.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return num;
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */