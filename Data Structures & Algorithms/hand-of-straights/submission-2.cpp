class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        unordered_map<int,int> mp;

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++)
        {
            mp[hand[i]]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(mp[hand[i]] > 0)
            {
                int start = hand[i];

                for(int j = 0; j < groupSize; j++)
                {
                    int x = start + j;

                    if(mp[x] <= 0)
                        return false;

                    mp[x]--;
                }
            }
        }

        return true;
    }
};