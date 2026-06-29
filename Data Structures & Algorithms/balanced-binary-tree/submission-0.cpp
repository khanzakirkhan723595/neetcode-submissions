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
    int maxDepth(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp=st.top();
            st.pop();
            if(temp->left!=NULL)
                st.push(temp->left);
            if(temp->right!=NULL)
                st.push(temp->right);
            int l=maxDepth(temp->left);
            int r=maxDepth(temp->right);
            if(abs(r-l)>1)
            {
                return false;
            }
        }
        return true;
        
    }
};
