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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        return {};

        vector<int>res;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int i = que.size();
            TreeNode * n = NULL;
            while(i--)
            {
                n=que.front();
                que.pop();
                if(n->left != NULL)
                que.push(n->left);
                if(n->right != NULL)
                que.push(n->right);
                
            }
            res.push_back(n->val);

        }
        return res;
    }
};