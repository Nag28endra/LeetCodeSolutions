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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode* root){
        if (root == NULL) return 0;

        // find the left and right height of the tree
        int leftHeight = dfsHeight(root->left);
        int rightHeight = dfsHeight(root->right);

        // check if they are returning -1 or not.
        if (leftHeight == -1 || rightHeight == -1) return -1;
        // find whether they are balanced or no t.
        if (abs(leftHeight - rightHeight)>1) return -1;
        // return the height of the tree.
        return max(leftHeight,rightHeight) + 1;
    }
};