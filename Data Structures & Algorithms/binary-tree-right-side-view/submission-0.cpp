/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            int sz=st.size();
            vector<int> ans;
            for(int i=0;i<sz;i++)
            {
                TreeNode *node=st.front();
                st.pop();
                ans.push_back(node->val);
                if(node->left!=NULL)
                    st.push(node->left);
                if(node->right!=NULL)
                    st.push(node->right);
            }
            res.push_back(ans);
        }
        return res;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res=levelOrder(root);
        vector<int> ans;
        for(int i=0;i<res.size();i++)
        {
            int n=res[i].size();
            vector<int> temp=res[i];
            ans.push_back(temp[n-1]);

        }
        return ans;

        
    }
};
