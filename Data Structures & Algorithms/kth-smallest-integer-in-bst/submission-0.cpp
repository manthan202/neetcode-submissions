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
    int result;
    int kthSmallest(TreeNode* root, int k){
        kthSmallest2(root, k);
        return result;
    }

private:
    void kthSmallest2(TreeNode* root, int& k) {
        if(root==nullptr) return;
        kthSmallest2(root->left, k);
        k--;
        if(k==0) {
            result=root->val;
            return;
        }
        kthSmallest2(root->right, k);
    }
};
