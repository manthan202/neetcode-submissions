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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1, mp);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inLeft, int inRight, unordered_map<int, int>& mp){
        if(inRight<inLeft) return nullptr;
        
        TreeNode* root=new TreeNode(preorder[preIdx]) ;
        int inIdx=mp[preorder[preIdx]];
        preIdx++;
        
        root->left=helper(preorder, inorder, preIdx, inLeft, inIdx-1, mp);
        root->right=helper(preorder, inorder, preIdx, inIdx+1, inRight, mp);
        
        return root;
    }
    
};
