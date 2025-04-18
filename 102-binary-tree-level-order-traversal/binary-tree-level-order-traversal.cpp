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
        // define our data structure for returning answer
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        // define a queue to store visited nodes.
        queue<TreeNode*> q;
        // add the root node to the queue.
        q.push(root);

        // traverse based on the queue data structure
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i = 0; i<size; i++){
                // take the very first node of the queue
                TreeNode* node = q.front();
                // delete that from the queue
                q.pop();
                // check if the left sub tree is null or not
                if (node->left != NULL) q.push(node->left);
                // check if the right sub treee is null or  not
                if (node->right != NULL)q.push(node->right);
                // add the popped node value from queue to the level data structure.
                level.push_back(node->val);
            }
            // add the level data structure to our answer.
            ans.push_back(level);
        }
        return ans;
    }
};