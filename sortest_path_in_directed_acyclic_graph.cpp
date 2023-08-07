#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void topologicalsort(int node, stack<int> &s, unordered_map<int, bool> &visited, unordered_map<int, list<pair<int, int>>> &adj)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                topologicalsort(i.first, s, visited, adj);
            }
        }
        s.push(node);
    }
    void getsortedpath(int src, vector<int> &sortdis, stack<int> &s, unordered_map<int, list<pair<int, int>>> &adj)
    {
        sortdis[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (sortdis[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if ((sortdis[top] + i.second) < sortdis[i.first])
                    {
                        sortdis[i.first] = sortdis[top] + i.second;
                    }
                }
            }
        }
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            pair<int, int> p = make_pair(v, w);
            adj[u].push_back(p);
        }
        // code here
        unordered_map<int, bool> visited;
        stack<int> s;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                topologicalsort(i, s, visited, adj);
            }
        }
        int src = 0;
        vector<int> sortdis(N, INT_MAX);

        getsortedpath(src, sortdis, s, adj);
        for (int i = 0; i < sortdis.size(); i++)
        {
            if (sortdis[i] == INT_MAX)
            {
                sortdis[i] = -1;
            }
        }
        return sortdis;
    }
};

int main()
{

    return 0;
}