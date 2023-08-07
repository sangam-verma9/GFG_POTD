#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());
        long long diff = INT_MAX;
        long long i = 0, j = m - 1;
        while (j < n)
        {
            long long d = a[j] - a[i];
            if (d < diff)
                diff = d;
            i++;
            j++;
        }
        return diff;
    }
};
int main()
{

    return 0;
}