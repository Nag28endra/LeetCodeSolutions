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
    // USING RECURSION
    // void preOrder(vector<int>& res, TreeNode* root){
    //     if (root == NULL) return;
    //     res.push_back(root->val);
    //     preOrder(res,root->left);
    //     preOrder(res,root->right);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        // to trace the nodes of the tree
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            // take out of the top node of the stack
            TreeNode* node = st.top();
            st.pop();
            // check whether right and left nodes are present or not.
            if (node->right !=NULL) st.push(node->right);
            if (node->left != NULL) st.push(node->left);
            // add the top of the stack node value to the result which was just popped.
            res.push_back(node->val);
        }
        return res;
    }
};