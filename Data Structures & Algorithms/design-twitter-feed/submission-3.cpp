class Twitter {
public:
    int t;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    unordered_map<int,unordered_set<int>> followmap;
    Twitter() {
        t=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        followmap[userId].insert(userId);
        t++;
        tweetmap[userId].push_back({t,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>>pq;
        for(auto user : followmap[userId])
        {
            auto &tweets=tweetmap[user];
            if(tweets.size()==0)
            {
                continue;
            }
            else{
                int lti=tweets.size()-1;
                int time = tweets[lti].first;
                int tweetid = tweets[lti].second;
                pq.push({time,tweetid,user,lti});
            }
        }
        while(!pq.empty() && ans.size()<10)
        {
            auto curr = pq.top();
            pq.pop();

            int tme=curr[0];
            int tid=curr[1];
            int uid=curr[2];
            int idx=curr[3];
            ans.push_back(tid);
            if(idx>0)
            {
                auto &tweets1=tweetmap[uid];
                int time = tweets1[idx-1].first;
                int tweetid = tweets1[idx-1].second;
                pq.push({time,tweetid,uid,idx-1});

                 
            }
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followmap[followerId].erase(followeeId);
        
    }
};
