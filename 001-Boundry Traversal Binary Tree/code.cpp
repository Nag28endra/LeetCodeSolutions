class Solution {
    void addLeftBoundry(Node* root, vector<int> &result){
        Node* currentNode = root->left;
        while(currentNode){
            if(!isLeaf(currentNode)) result.push_back(currentNode->data);
            if(currentNode->left) currentNode = currentNode->left;
            else currentNode = currentNode->right;
        }
    }
    void addLeaves(Node* root, vector<int> &result){
        if(isLeaf(root)){
            result.push_back(root->data);
            return;
        } 
        
        if(root->left) addLeaves(root->left,result);
        if(root->right) addLeaves(root->right,result);
    }
    void addRightBoundry(Node* root, vector<int>& result){
        Node* currentNode = root->right;
        vector<int> temp;
        while(currentNode){
            if(!isLeaf(currentNode)) temp.push_back(currentNode->data);
            if(currentNode->right) currentNode = currentNode->right;
            else currentNode = currentNode->left;
        }
        for(int i = temp.size()-1; i>=0; i--) result.push_back(temp[i]);
    }
    bool isLeaf(Node* root){
        return (!root->left && !root->right);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        if(root == NULL) return result;
        if(!isLeaf(root)) result.push_back(root->data);
        addLeftBoundry(root,result);
        addLeaves(root,result);
        addRightBoundry(root,result);
        return result;
    }
};

