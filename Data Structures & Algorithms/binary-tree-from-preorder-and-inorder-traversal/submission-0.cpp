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
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inLeft, int inRight){
        if(inRight<inLeft) return nullptr;
        
        TreeNode* root=new TreeNode(preorder[preIdx]) ;
        int inIdx=search(preorder[preIdx], inLeft, inRight, inorder);
        preIdx++;
        
        root->left=helper(preorder, inorder, preIdx, inLeft, inIdx-1);
        root->right=helper(preorder, inorder, preIdx, inIdx+1, inRight);
        
        return root;
    }

    int search(int target, int start, int end, vector<int> nums){
        for(int i=start; i<=end; i++) {
            if (nums[i]==target) return i;
        }
        return -1;
    }
    
};
