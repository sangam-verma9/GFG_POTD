#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthFibonacci(int n)
    {
        // code here
        int num1 = 1;
        int num2 = 1;
        if (n == 1 || n == 2)
        {
            return 1;
        }
        int M = 1e9 + 7;
        for (int i = 3; i <= n; i++)
        {
            int num3 = (num1 + num2) % M;
            num1 = num2;
            num2 = num3;
        }
        return num2;
    }
};
int main()
{

    return 0;
}