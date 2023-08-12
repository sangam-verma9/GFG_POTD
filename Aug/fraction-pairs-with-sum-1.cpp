#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int cnt = 0;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            int gcd = __gcd(numerator[i], denominator[i]);
            int numr = numerator[i] / gcd;
            int denr = denominator[i] / gcd;
            int co_numr = denr - numr;
            cnt += mp[{co_numr, denr}];
            mp[{numr, denr}]++;
        }
        return cnt;
    }
};
int main()
{

    return 0;
}