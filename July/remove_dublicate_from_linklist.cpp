#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        unordered_map<int, int> mp;
        Node *temp = head;
        mp[temp->data]++;
        Node *curr = head->next;
        while (curr != NULL)
        {
            mp[curr->data]++;
            if (mp[curr->data] <= 1)
            {
                temp = temp->next;
                curr = curr->next;
            }
            else
            {
                temp->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
int main()
{

    return 0;
}