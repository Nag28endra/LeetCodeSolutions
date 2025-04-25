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
    // Using RECURSION
    // void postOrder(TreeNode* root, vector<int> &res){
    //     if (root == NULL)return;

    //     postOrder(root->left, res);
    //     postOrder(root->right,res);
    //     res.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        // traverse the first stack to keep track of nodes.
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root == NULL) return res;
            // check the left and right of the current node.
            if (root->left) st1.push(root->left);
            if (root->right) st1.push(root->right);

        }
        // at last pop the top values and store them in our result.
            while(!st2.empty()){
                res.push_back(st2.top()->val);
                st2.pop();
            }
        return res;
    }
};