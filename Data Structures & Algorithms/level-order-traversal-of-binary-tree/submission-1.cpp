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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {} ;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        vector<int> ele_result;

        while(!q.empty()){
            ele_result.clear();
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr=q.front();
                q.pop();
                ele_result.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back(ele_result);
        }
        return result;
    }
};
