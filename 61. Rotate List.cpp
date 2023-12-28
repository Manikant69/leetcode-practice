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
private:
    ListNode* findNthNode(ListNode* temp, int k)
    {
        int cnt = 1;
        while(cnt < k)
        {
            temp = temp -> next;
            cnt++;
        }

        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
        {
            return head;
        }

        int len = 1;
        ListNode* tail = head;

        while(tail -> next){
            len++;
            tail = tail -> next;
        }
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
private:
    ListNode* findNthNode(ListNode* temp, int k)
    {
        int cnt = 1;
        while(cnt < k)
        {
            temp = temp -> next;
            cnt++;
        }

        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
        {
            return head;
        }

        int len = 1;
        ListNode* tail = head;

        while(tail -> next){
            len++;
            tail = tail -> next;
        }

        k = k % len;

        if(k == 0) return head;

        //make it circular
        tail -> next = head;

        ListNode* newLastNode = findNthNode(head, len - k);


        //updating the head last's next will become the head
        head = newLastNode -> next;

        //make the last node next to null
        newLastNode -> next = NULL;


        return head;

    }
};
        k = k % len;

        if(k == 0) return head;

        //make it circular
        tail -> next = head;

        ListNode* newLastNode = findNthNode(head, len - k);


        //updating the head last's next will become the head
        head = newLastNode -> next;

        //make the last node next to null
        newLastNode -> next = NULL;


        return head;

    }
};
