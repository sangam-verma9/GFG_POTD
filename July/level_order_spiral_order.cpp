#include <bits/stdc++.h>
using namespace std;
vector<int> findSpiral(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    ans.push_back(root->data);
    if (root->left)
        q.push(root->left);
    if (root->right)
        q.push(root->right);
    q.push(NULL);
    vector<int> temp;
    bool ltor = 1;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (!q.empty())
                q.push(NULL);
            if (ltor)
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    ans.push_back(temp[i]);
                }
            }
            else
            {
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    ans.push_back(temp[i]);
                }
            }
            temp.clear();
            ltor = !ltor;
            continue;
        }
        temp.push_back(front->data);
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
    return ans;
}
int main()
{

    return 0;
}