class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        if(pq.size()==1)
        {
            return pq.top();
        }
        if(pq.size()==0)
        {
            return 0;
        }
        
        // Loop while there are at least two stones to smash
        while (pq.size() > 1) {
            int x = pq.top(); // Heaviest stone
            pq.pop();
            int y = pq.top(); // Second heaviest stone
            pq.pop();
            
            // If they aren't equal, push the remaining weight back
            if (x != y) {
                pq.push(x - y);
            }
        }
        return pq.size()==1?pq.top():0;
        
    }
};
