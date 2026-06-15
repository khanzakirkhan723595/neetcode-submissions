class MinStack {
public:
    stack<int> st;
    stack<int> mst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mst.empty() || val<=mst.top())
        {
            mst.push(val);
        }
        
    }
    
    void pop() {
        if(st.top()==mst.top())
        {
            mst.pop();
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
        int mini=mst.top();
        return mini;
        
    }
};
