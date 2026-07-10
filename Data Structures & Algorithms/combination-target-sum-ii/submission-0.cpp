class Solution {
public:
    vector<vector<int>> res;
    void f(int idx,vector<int> vec, int sum,int target,vector<int>& candidates)
    {
        if(sum == target)
        {
            res.push_back(vec);
            return;
        }

        if(sum > target)
            return;
    
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(sum + candidates[i] > target)
                break;          // because array is sorted

            
            vec.push_back(candidates[i]);
            f(i+1,vec,sum+candidates[i],target,candidates);
            vec.pop_back();
            
            
        }
        
        
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        f(0,vec,0,target,candidates);
        return res;
    }
};
