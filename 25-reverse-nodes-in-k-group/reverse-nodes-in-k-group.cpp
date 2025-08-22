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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* current = head;
        while(current)
        {
            count++;
            current = current->next;
        }
        
        ListNode* first = new ListNode(0);
        first->next = head;
        head= first;
        ListNode* second,*curr,*prev=NULL,*front=NULL;
        
        while(count >= k)
        {
            second = first->next;
            // prev=first;
            curr=first->next;
            int x = k;
            while(x && curr)
            {
                front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                x--;

            }
            first->next=prev;
            second->next=curr;
            first=second;
            count -= k;

        }
        first=head;
        head = head->next;
        delete first;
        return head;


    }
};