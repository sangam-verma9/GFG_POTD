#include <bits/stdc++.h>
using namespace std;
// my solution
class Solution
{
public:
    void solve(stack<int> &St, stack<int> &sn)
    {
        if (St.empty())
            return;
        int topele = St.top();
        St.pop();
        sn.push(topele);
        if (!St.empty())
        {
            solve(St, sn);
        }
    }
    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;
        stack<int> sn;
        solve(St, sn);
        St = sn;
    }
};
//****** gfg copy from comments
class Solution
{
public:
    queue<int> ans;
    void Reverse(stack<int> &St)
    {

        if (!St.empty())
        {
            ans.push(St.top());
            St.pop();
        }
        else
        {
            return;
        }

        Reverse(St);

        while (!ans.empty())
        {
            St.push(ans.front());
            ans.pop();
        }
    }
};
int main()
{

    return 0;
}