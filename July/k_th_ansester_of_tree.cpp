#include <bits/stdc++.h>
using namespace std;
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == node)
    {
        return root;
    }
    Node *leftans = solve(root->left, k, node);
    Node *rightans = solve(root->right, k, node);
    if (leftans != NULL && rightans == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    else if (rightans != NULL && leftans == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}
int main()
{

    return 0;
}