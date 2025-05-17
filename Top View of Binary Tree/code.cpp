class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<int, Node*>> que;
        map<int,int>mpp;
        
        que.push({0,root});
        
        while(!que.empty()){
            auto it = que.front();
            que.pop();
            
            Node* node = it.second;
            int line = it.first;
            if(mpp.find(line) == mpp.end()) mpp[line]=node->data;
            
            if(node->left) que.push({line-1,node->left});
            if(node->right) que.push({line+1,node->right});
            
        }
        
        for(auto p:mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
