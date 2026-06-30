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
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *node=st.top();
            st.pop();
            
            if(p->val < node->val && q->val < node->val)
            {
                if(node->left!=NULL)
                    st.push(node->left);
            }
            else if(p->val > node->val && q->val > node->val)
            {
                if(node->right!=NULL)
                {
                    st.push(node->right);
                }

            }
            else{
                return node;
            }
        }
        return NULL;
        
    }
};
