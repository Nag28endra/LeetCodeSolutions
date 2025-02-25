//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(int node, vector<int> &color, vector<pair<int,int>>& edges, int m, int N, int col){
        for(const auto& edge : edges) {
            // collect adjancet nodes.
            int u = edge.first;
            int v = edge.second;

            // If node is connected to u or v, check their color
            if ((u == node && color[v] == col) || (v == node && color[u] == col)) {
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int>& color,vector<pair<int,int>> &edges, int m, int N){
        // check if the nodes are equal to the given vertices.
        if(node == N) return true;
        // traverse each color
        for(int i=1;i<=m;i++){
            // check for adjacent color
            if (isSafe(node,color,edges,m,N,i)) {
                // if safe insert
                color[node] = i;
                // check for other color.
                if (solve(node+1,color,edges,m,N)) return true;
                // causing ambiguity remove the color for recently inserted node. (backtracking.)
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    // create a  vector for colors.
       vector<int> color(v, 0);
       // make a function call
       if (solve(0,color,edges,m,v)) return true;
       return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends
