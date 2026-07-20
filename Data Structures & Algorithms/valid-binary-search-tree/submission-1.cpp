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
    bool isValidBST(TreeNode* root) {
        return validate(root, -1001, 1001);
    }

private:
    bool validate(TreeNode* root, int min_val, int max_val){
        if (root==nullptr) return true;
        if(root->val >= max_val || root->val <= min_val) return false;
        int left=validate(root->left, min_val, root->val);
        int right=validate(root->right, root->val, max_val);
        return left && right ;
    }
};
