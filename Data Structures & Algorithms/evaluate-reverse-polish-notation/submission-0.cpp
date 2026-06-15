class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*")
            {
                int num=stoi(tokens[i]);
                st.push(num);
            }
            else{
                if(tokens[i]=="/")
                {
                    int r=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                int div=l/r;
                st.push(div);
                }
                else if(tokens[i]=="*")
                {
                    int r=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                int mul=l*r;
                st.push(mul);
                }
                else if(tokens[i]=="+")
                {
                    int r=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                int sum=l+r;
                st.push(sum);
                }
                else if(tokens[i]=="-")
                {
                    int r=st.top();
                st.pop();
                int l=st.top();
                st.pop();
                int diff=l-r;
                st.push(diff);
                }
            }
        }
        return st.top();
        
    }
};
