class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.count(key))
        {
            mp[key].push_back({timestamp,value});
        }
        else{
            mp[key]={{timestamp,value}};
        }
        
    }
    
    string get(string key, int timestamp) {
        int idx=-1;
        string s="";
        if(!mp.count(key))
        {
            return "";
        }
        else{
            vector<pair<int,string>> arr = mp[key];
            int l=0;
            int r=arr.size()-1;
            
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(arr[mid].first<=timestamp)
                {
                    idx=arr[mid].first;
                    s=arr[mid].second;
                    l=mid+1;
                }
                else if(arr[mid].first>timestamp)
                {
                    r=mid-1;
                }
            }
        }
        if(idx==-1)
        {
            return "";
        }
        else{
            return s;
        }
        
    }
};
