/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int findLength(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            head = head -> next;
            cnt++;
        }
        return cnt;
    }

    ListNode* intersection(ListNode* smaller, ListNode* longer, int diff)
    {
        //traverse the longest list to make them on same level
        for(int i=0; i<diff; i++)
        {
            longer = longer -> next;
        }

        while(longer && smaller)
        {
            if(longer == smaller)
            {
                return longer;
            }
            longer = longer -> next;
            smaller = smaller -> next;
        }

        return NULL;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            /*  first approach */

        // int l1 = findLength(headA);
        // int l2 = findLength(headB);

        // if(l1 > l2) //pass smaller list, bigger list and diff of size
        // {
        //     return intersection(headB, headA, l1 - l2);
        // }
        // else{
        //     return intersection(headA, headB, l2 - l1);
        // }

        /* second approach */

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 && temp2)
        {
            if (temp1 == temp2) {
                return temp1;
            }

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == NULL && temp2 == NULL)
                return NULL;

            if (temp1 == NULL){
                temp1 = headB;
            }
            if(temp2 == NULL){
                temp2 = headA;
            }
        }

        return NULL;

    }
};
