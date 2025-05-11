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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> qu;
        qu.push(root);
        bool leftToRight = true;

        // while queue is not empty
        while(!qu.empty()){
            // find the size of the queue
            int size = qu.size();
            vector<int> ds(size);
            for(int i = 0; i<size; i++){
                // take out the front node from the queue.
                TreeNode* node = qu.front();
                // and delete it.
                qu.pop();
                // find the index to insert the node value.
                int idx = leftToRight ? i : (size-1-i);

                ds[idx] = node->val;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);

            }
            leftToRight = !leftToRight;
            result.push_back(ds);
        }
        return result;
    }
};