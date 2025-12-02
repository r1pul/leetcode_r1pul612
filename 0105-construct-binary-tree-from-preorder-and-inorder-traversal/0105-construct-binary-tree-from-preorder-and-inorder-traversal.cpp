/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n - 1, idx);
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s, int e,
                    int& idx) {
        if (s > e)
            return NULL;
        int rootval = preorder[idx];
        int i = s;
        for (; i <= e; i++) {
            if (inorder[i] == rootval)
                break;
        }
        idx++;
        TreeNode* root = new TreeNode(rootval);
        root->left = solve(preorder, inorder, s, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, e, idx);

        return root;
    }
};