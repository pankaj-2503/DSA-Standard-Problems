class MinStack {
    // TC : O(1) , SC:O(2N)
    stack<pair<int,int>>s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int mn;
        if(s.empty()) mn=val;
        if(!s.empty()) mn=min(s.top().second,val);
        s.push({val,mn});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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