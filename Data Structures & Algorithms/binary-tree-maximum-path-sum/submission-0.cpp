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
    int maxisum=INT_MIN;
    int dfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lg=max(0,dfs(root->left));
        int rg=max(0,dfs(root->right));
        maxisum=max(maxisum,lg+root->val+rg);

        return root->val + max(lg,rg);

        
    }
    int maxPathSum(TreeNode* root) {
        stack<TreeNode *>st;
        
        st.push(root);
        while(!st.empty())
        {
            TreeNode *node=st.top();
            st.pop();
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);

            
            dfs(node);
        }
        return maxisum;

    }
};
