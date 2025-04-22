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
    // USING RECURSSION
    // void inOrder(TreeNode* root,vector<int> &res){
    //     if (root == NULL)return;
    //     // traverse to left
    //     inOrder(root->left,res);
    //     // print the value
    //     res.push_back(root->val);
    //     // traverse right
    //     inOrder(root->right,res);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        // take the root node
        TreeNode* node = root;

        while(true){
            // move to left if the node is not null
            if (node != NULL){
                st.push(node);
                // move to the left
                node = node->left;
            }
            // move to right if the current node is null - backtracking.
            else{
                if (st.empty()) break;
                // take the top of the node.
                node = st.top();
                st.pop();
                // add the value to our result.
                res.push_back(node->val);
                // go to the right of the current node.
                node = node->right;
            }
        }
        return res;
    }
};