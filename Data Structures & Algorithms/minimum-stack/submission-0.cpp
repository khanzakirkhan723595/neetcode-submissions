class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
    }
    
    void pop() {
        if(st.empty())
        {
            return;
        }
        st.pop();
        
    }
    
    int top() {
        if(st.empty())
        {
            return 0;
        }
        return st.top();
        
    }
    
    int getMin() {
        stack<int> q;
        int mini=INT_MAX;
        while(!st.empty())
        {
            if(st.top()<mini)
            {
                mini=st.top();
            }
            q.push(st.top());
            st.pop();

        }
        while(!q.empty())
        {
            st.push(q.top());
            q.pop();
        }
        return mini;
        
    }
};
