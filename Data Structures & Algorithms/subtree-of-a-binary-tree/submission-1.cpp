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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr) return true;
        if(subRoot==nullptr && root==nullptr) return true;
        if(root==nullptr) return false;
        if(root->val==subRoot->val) {
            if(isSame(root->right, subRoot->right) && isSame(root->left, subRoot->left)) return true;
        } 
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) ;
    }

    bool isSame(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        if(root1->val != root2->val) return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right) ;
    }
};
