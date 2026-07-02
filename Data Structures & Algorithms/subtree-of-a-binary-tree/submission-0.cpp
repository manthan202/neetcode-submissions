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
        stack<TreeNode*> st;
        st.push(root);
        vector<TreeNode*> vec;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->val==subRoot->val) vec.push_back(node);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            
        }
        for (int i=0; i<vec.size(); i++) {
            if(isSame(vec[i],subRoot)) return true;
        }
        return false;
    }

    bool isSame(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        if(root1->val != root2->val) return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right) ;
    }
};
