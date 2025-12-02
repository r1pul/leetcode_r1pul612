/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int idx  = 0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        
        return solve(preorder,inorder,0,n-1);
    }
    public TreeNode solve(int[] preorder, int[] inorder,int s , int e){
        if(s > e)
            return null;

        int rootval = preorder[idx];
        int i = s;
        for( ; i  <= e ; i++){
            if(inorder[i]==rootval)
                break;
            
        }
        idx++;
        TreeNode root = new TreeNode(rootval);
        root.left = solve(preorder,inorder,s,i-1);
        root.right = solve(preorder,inorder,i+1,e);
        return root; 
    }
}