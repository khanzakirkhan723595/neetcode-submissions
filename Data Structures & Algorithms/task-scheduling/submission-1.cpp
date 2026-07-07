class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int> pq;
        unordered_map<char, int> mp;

        // Count frequencies
        for(char ch : tasks)
            mp[ch]++;

        // Push frequencies into max heap
        for(auto &p : mp)
            pq.push(p.second);

        int time = 0;

        while(!pq.empty())
        {
            vector<int> temp;
            int cnt = 0;   // Number of tasks executed in this cycle

            // Execute at most n+1 tasks
            for(int i = 0; i <= n; i++)
            {
                if(pq.empty())
                    break;

                int freq = pq.top();
                pq.pop();

                freq--;
                cnt++;
                time++;

                if(freq > 0)
                    temp.push_back(freq);
            }

            
            for(int x : temp)
                pq.push(x);

            
            if(!pq.empty())
            {
                time += (n + 1 - cnt);
            }
        }

        return time;
    }
};