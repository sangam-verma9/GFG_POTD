#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long int largestPrimeFactor(int n)
    {
        // code here
        long long int ans = 1;
        while (n % 2 == 0)
        {
            ans = 2;
            n = n / 2;
        }
        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                ans = i;
                n = n / i;
            }
        }
        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2)
            ans = n;

        return ans;
    }
};
int main()
{

    return 0;
}