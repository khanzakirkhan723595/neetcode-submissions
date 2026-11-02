class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1;i<rowIndex+1;i++)
        {
            vector<int> temp1=res[i-1];
            vector<int> temp2;
            temp2.push_back({temp1[0]});
            for(int i=1;i<temp1.size();i++)
            {
                temp2.push_back(temp1[i]+temp1[i-1]);
            }
            temp2.push_back(1);
            res.push_back(temp2);
            
        }
        return res[rowIndex];
        
    }
};


