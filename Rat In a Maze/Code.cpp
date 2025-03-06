//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(int i,int j, vector<vector<int>> &mat, int n,vector<string>&ans, string move, vector<vector<int>>&vis,int di[],int dj[]){
        if (i == n-1 && j==n-1){
            // add the path means the string to the answer.
            ans.push_back(move);
            return;
        }
        
        string dir ="DLRU";
        for (int idx=0; idx<4; idx++){
            // direction steps
            int nexti = i + di[idx];
            int nextj = j + dj[idx];
            
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && mat[nexti][nextj] == 1){
                // mark visited
                vis[i][j] = 1;
                solve(nexti,nextj,mat,n,ans,move+dir[idx],vis,di,dj);
                // mark un visited for backtracking
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // defining 2 arrays for directions in lexilogical order.   
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        vector<string> ans;
        // find the number of rows
        int n = mat[0].size();
        // creat a visited matrix
        vector<vector<int>> visited(n,vector<int>(n,0));
        if (mat[0][0] == 1) solve(0,0,mat,n,ans,"",visited,di,dj);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
