#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int ind, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {
        visited[ind] = true;
        ans.push_back(ind);
        for (auto i : adj[ind])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        dfs(0, adj, visited, ans);
        return ans;
    }
};
int main()
{

    return 0;
}