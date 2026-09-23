class MyHashMap {
public:
    vector<pair<int,int>> hash;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0;i<hash.size();i++)
        {
            int k=hash[i].first;
            if(key==k)
            {
                hash[i].second=value;
                return;
            }
        }
        hash.push_back({key,value});
        
    }
    
    int get(int key) {
        for(int i=0;i<hash.size();i++)
        {
            int k=hash[i].first;
            if(key==k)
            {
                
                return hash[i].second;
            }
        }
        return -1;

        
    }
    
    void remove(int key) {
        for(int i=0;i<hash.size();i++)
        {
            int k=hash[i].first;
            if(key==k)
            {
                swap(hash[i],hash[hash.size()-1]);
                hash.pop_back();
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */