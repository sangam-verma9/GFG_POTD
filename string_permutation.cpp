#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Complete this function
    void solve(string S, int ind, vector<string> &ans)
    {
        if (ind >= S.length())
        {
            ans.push_back(S);
            return;
        }
        for (int i = ind; i < S.length(); i++)
        {
            swap(S[i], S[ind]);
            solve(S, ind + 1, ans);
            swap(S[i], S[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        // Your code here
        vector<string> ans;
        int ind = 0;
        solve(S, ind, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{

    return 0;
}