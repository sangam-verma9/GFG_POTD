#include <bits/stdc++.h>
using namespace std;
// brute force approach (TLE)
class Solution
{
public:
    int solve(int n, int a[], int prev, int curr)
    {
        if (curr == n)
        {
            return 0;
        }
        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
        {
            include = 1 + solve(n, a, curr, curr + 1);
        }

        int exclude = 0 + solve(n, a, prev, curr + 1);

        return max(include, exclude);
    }
    int longestSubsequence(int n, int a[])
    {
        int ans = solve(n, a, -1, 0);
    }
};
//******* memoziaton approach *******

class Solution
{
public:
    int solve(int n, int a[], int prev, int curr, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }
        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
        {
            include = 1 + solve(n, a, curr, curr + 1, dp);
        }

        int exclude = 0 + solve(n, a, prev, curr + 1, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }
    int longestSubsequence(int n, int a[])

    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, a, -1, 0, dp);
    }
};
//******** tabulation *** ***
class Solution
{
public:
    int longestSubsequence(int n, int a[])

    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + dp[curr + 1][curr + 1]; // [curr][prev+1+1]
                }
                int exclude = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
};
//********** space optimization ********
class Solution
{
public:
    int longestSubsequence(int n, int a[])

    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + nextRow[curr + 1]; // [curr][prev+1+1]
                }
                int exclude = nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};
//**********  optimized approach *********
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        if (n == 0)
            return 0;
        // your code here
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                // find index which is just greater and replace
                int ind = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[ind] = a[i];
            }
        }
        return ans.size();
    }
};
//**********

int main()
{

    return 0;
}