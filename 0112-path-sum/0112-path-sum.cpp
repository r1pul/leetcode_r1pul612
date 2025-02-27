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
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int sum=0;
        return fill(root,temp,sum,targetSum);
    }
    bool fill(TreeNode* root , vector<int>temp , int sum , int ts)
    {
        if(!root)
        return false;

        sum+=root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==ts)
            return true;

            
        }
        bool l = fill(root->left,temp,sum,ts);
        bool r =fill(root->right,temp,sum,ts);
        return l || r;
    }
};