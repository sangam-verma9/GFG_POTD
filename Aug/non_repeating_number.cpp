#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp ^= nums[i];
        }
        int lsb_one = temp & (~(temp - 1));
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lsb_one & nums[i])
            {
                a ^= nums[i];
            }
            else
            {
                b ^= nums[i];
            }
        }
        if (a > b)
            return {b, a};
        return {a, b};
    }
};
int main()
{

    return 0;
}