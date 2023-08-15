#include <bits/stdc++.h>
using namespace std;
//********* brute force (recursive) approach
class Solution
{
public:
    // Function to find the nth catalan number.
    int M = 1e9 + 7;
    int findCatalan(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (findCatalan(i) * findCatalan(n - i - 1)) % M;
        }
        return ans;
    }
};
//******** dp solution
class Solution
{
public:
    // Function to find the nth catalan number.
    int findCatalan(int n)
    {
        long long int cat[n + 1];
        cat[0] = cat[1] = 1;
        int M = 1e9 + 7;
        for (int i = 2; i <= n; i++)
        {
            cat[i] = 0;
            for (int j = 0; j < i; j++)
            {
                cat[i] = (cat[i] + (cat[j] * cat[i - j - 1]) % M) % M;
            }
        }
        return cat[n];
    }
};
int main()
{

    return 0;
}