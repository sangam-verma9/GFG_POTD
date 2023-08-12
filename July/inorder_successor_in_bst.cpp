#include <bits/stdc++.h>
using namespace std;
//********** first think TC:O(N) SC:O(N) ***********
class Solution
{
public:
    void solve(Node *root, Node *x, vector<Node *> &v)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, x, v);
        v.push_back(root);
        solve(root->right, x, v);
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        vector<Node *> v;
        solve(root, x, v);
        v.push_back(NULL);
        bool flag = 1;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i]->data == x->data)
            {
                flag = 0;
            }
            if (flag == 0)
            {
                return v[i + 1];
            }
        }
        return NULL;
    }
};
//********** copy from gfg TC:O(N) SC:O(1) ***********
Node *res = NULL;
void help(Node *root, Node *x)
{
    if (root == NULL)
        return;
    if (root->data <= x->data)
    {
        help(root->right, x);
    }
    else
    {
        res = root;
        help(root->left, x);
    }
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    help(root, x);
    return res;
}
//***********
int main()
{

    return 0;
}