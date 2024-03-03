/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head, *fast = head, *firstKth = head;

        for(int i=0; i<k-1; i++)
        {
            fast = fast -> next;
            firstKth = firstKth -> next;
        }

        while(fast -> next)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        int temp = firstKth -> val;
        firstKth -> val = slow -> val;
        slow -> val = temp;

        return head;
    }
};
