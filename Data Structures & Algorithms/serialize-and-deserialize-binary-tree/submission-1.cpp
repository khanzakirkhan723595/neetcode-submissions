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

class Codec {
public:

    // Encodes a tree to a single string.
        void helper(TreeNode *root,string &res)
    {
        if(root==NULL)
        {
            res+="N,";
            return;
        }

        res+=to_string(root->val)+",";

        helper(root->left,res);
        helper(root->right,res);
    }

    string serialize(TreeNode *root)
    {
        string res;
        helper(root,res);
        return res;
    }

    TreeNode* build(vector<string> &nodes,int &idx)
    {
        if(nodes[idx]=="N")
        {
            idx++;
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(nodes[idx]));
        idx++;
        root->left=build(nodes,idx);
        root->right=build(nodes,idx);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                nodes.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(data[i]);
            }
        }
        int idx=0;
        return build(nodes,idx);
        
    }
};
