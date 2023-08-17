#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool allnine(int num[], int n)
    {
        for (int i = 0; i < n; i++)
            if (num[i] != 9)
                return false;
        return true;
    }
    vector<int> generateNextPalindrome(int num[], int n)
    {
        if (allnine(num, n))
        {
            vector<int> ans;
            ans.push_back(1);
            for (int i = 0; i < n - 1; i++)
            {
                ans.push_back(0);
            }
            ans.push_back(1);
            return ans;
        }

        else if (n & 1)
        {
            bool flag = false;
            for (int i = 0; i < n / 2; i++)
            {
                if (num[i] > num[n - i - 1])
                {
                    flag = true;
                }
                else if ((num[i] == num[n - i - 1]))
                {
                    continue;
                }
                else
                {
                    flag = false;
                }
                num[n - i - 1] = num[i];
            }

            if (flag == false)
            {
                int j = 0;
                for (; j < n / 2 - 1; j++)
                {
                    if (num[n / 2 - j] == 9)
                    {
                        num[n / 2 - j] = 0;
                        num[n / 2 + j] = 0;
                    }
                    else
                        break;
                }
                if (j == 0)
                {
                    num[n / 2 - j]++;
                }
                else
                {
                    num[n / 2 - j]++;
                    num[n / 2 + j]++;
                }
            }
        }
        else
        {

            bool flag = false;
            for (int i = 0; i < n / 2; i++)
            {
                if (num[i] > num[n - i - 1])
                    flag = true;

                else if ((num[i] == num[n - i - 1]))
                    continue;

                else
                    flag = false;

                num[n - i - 1] = num[i];
            }
            if (flag == false)
            {
                int j = 0;
                for (; j < n / 2 - 1; j++)
                {
                    if (num[n / 2 - j - 1] == 9)
                    {
                        num[n / 2 - j - 1] = 0;
                        num[n / 2 + j] = 0;
                    }
                    else
                        break;
                }

                num[n / 2 - j - 1]++;
                num[n / 2 + j]++;
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = num[i];
        }
        return ans;
    }
};
int main()
{

    return 0;
}
