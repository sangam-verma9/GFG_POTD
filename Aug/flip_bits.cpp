#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ans = 0, zeroc = 0, onec = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zeroc++;
            }
            else
            {
                zeroc--;
                onec++;
            }
            ans = max(zeroc, ans);
            if (zeroc < 0)
                zeroc = 0;
        }
        return ans + onec;
    }
};
int main()
{

    return 0;
}
