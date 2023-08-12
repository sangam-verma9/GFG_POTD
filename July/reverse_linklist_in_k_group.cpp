#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct node *linkreverse(struct node *head, int k)
    {
        node *prev = NULL;
        node *curr = head;
        node *fow = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            fow = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *temp = linkreverse(head, k);
        node *curr = head;
        int cnt = 1;
        while (curr != NULL)
        {
            curr = curr->next;
            if (curr != NULL)
            {
                head->next
            }
        }
    }
};
int main()
{

    return 0;
}