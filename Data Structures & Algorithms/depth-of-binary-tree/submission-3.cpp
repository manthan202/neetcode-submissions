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
    int maxDepth(TreeNode* root) {
        return max_depth(root, 1);
    }

private:
    int max_depth(TreeNode* root, int depth){
        if(root==nullptr) return depth-1;
        int left=max_depth(root->left, depth+1);
        int right=max_depth(root->right, depth+1);
        return max(left, right);
    }
};
