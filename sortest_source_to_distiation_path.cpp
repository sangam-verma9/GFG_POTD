#include <bits/stdc++.h>
using namespace std;
// striver sloution
class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        if (X == 0 && Y == 0)
            return 0;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newc >= 0 && newc < M && newr < N && A[newr][newc] == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;
                    if (newr == X && newc == Y)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};
int main()
{

    return 0;
}