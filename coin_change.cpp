#include <bits/stdc++.h>
using namespace std;
//***** brute force approach
class
{
public:
    long long int count(int coins[], int N, int sum)
    {
        if (sum < 0)
        {
            return 0;
        }
        if (sum == 0)
        {
            return 1;
        }
        if (N <= 0)
        {
            return 0;
        }
        return count(coins, N, sum - coins[N - 1]) + count(coins, N - 1, sum);
    }
};
// ***** optimized approcah
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        // code here.
        vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, -1));
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    }
};
int main()
{

    return 0;
}