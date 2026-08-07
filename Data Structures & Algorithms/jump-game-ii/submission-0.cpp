class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            // How far can I reach from i?
            
            // Update farthest
            farthest=max(farthest,i+nums[i]);
            
            // If I have reached currentEnd,
            if(i==currentEnd)
            {
                currentEnd=farthest;
                jumps++;
            }   
            // I need to take another jump.
        }

        return jumps;
        
    }
};
