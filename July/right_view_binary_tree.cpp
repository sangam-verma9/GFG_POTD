#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        queue<Node *> q;
        int cnt = 0;
        q.push(root);
        q.push(NULL);
        ans.push_back(root->data);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
                cnt = -1;
                continue;
            }
            if (cnt == -1 && front != NULL)
            {
                ans.push_back(front->data);
                cnt = 0;
            }
            if (front->right)
            {
                q.push(front->right);
            }
            if (front->left)
            {
                q.push(front->left);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}