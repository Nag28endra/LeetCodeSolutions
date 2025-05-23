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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> que;

        que.push({root,{0,0}});

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            nodes[vertical][level].insert(node->val);
            if(node->left) que.push({node->left, {vertical-1,level+1}});
            if(node->right) que.push({node->right, {vertical+1,level+1}});
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};