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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         queue<TreeNode*> qe;
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        qe.push(root);
        int l = 0;
        while (!qe.empty()) {
            vector<int> v;
            
            int n = qe.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = qe.front();
                qe.pop();
                if (temp->left != nullptr)
                    qe.push(temp->left);

                if (temp->right != nullptr)
                    qe.push(temp->right);

                v.push_back(temp->val);
            }
            
            if (l % 2 != 0) {
                reverse(v.begin(), v.end());

                ans.push_back(v);
            }
            else 
            ans.push_back(v);
            l++;
        }
        return ans;
    }
        
    
};