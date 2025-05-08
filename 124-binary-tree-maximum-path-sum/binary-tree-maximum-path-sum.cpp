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
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        findPathSum(root,pathSum);
        return pathSum;
    }
private:
    int findPathSum(TreeNode* node, int &pathSum){
        if(node == NULL) return 0;
        int leftSum = max(0,findPathSum(node->left,pathSum));
        int rightSum = max(0,findPathSum(node->right,pathSum));

        pathSum = max(pathSum, leftSum+rightSum+node->val);
        return max(leftSum,rightSum)+node->val;
    }
};