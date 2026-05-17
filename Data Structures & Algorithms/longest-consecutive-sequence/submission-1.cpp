class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
        {
            return n;
        }
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        int cnt=1;
        int maxicnt=cnt;
        int q=pq.top();
        pq.pop();
        int curr=q;
        while(!pq.empty())
        {
            int r=pq.top();
            pq.pop();
            if(r==curr)
            {
                continue;
            }
            if(r==curr-1)
            {
                cnt++;
                maxicnt=max(cnt,maxicnt);
                curr=r;
                
            }
            else{
                curr=r;
                cnt=1;
            }
   
        }
        return maxicnt;
        
    }
};
