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
     ListNode* reverse(ListNode* curr,ListNode* prev)
        {
            if(curr==NULL)
            {
                return prev;
            }
            ListNode* front=curr->next;
            curr->next=prev;
            return reverse(front,curr);
        }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       

        //l1=reverse(l1,NULL);
        //l2=reverse(l2,NULL);

        ListNode* curr1 = l1;
        ListNode* curr2=l2;
        int carry=0,sum;
        ListNode* head = new ListNode(0);
        ListNode* tail=head;

        while(curr1 && curr2)
        {
            sum = curr1->val + curr2->val + carry;
            tail->next = new ListNode(sum % 10);
            curr1 = curr1->next;
            curr2 = curr2->next;
            tail = tail->next;
            carry = sum/10;
        }

        //when curr1 is still left
        while(curr1)
        {
            sum = curr1->val+carry;
            tail->next = new ListNode(sum % 10);
            curr1=curr1->next;
            tail = tail->next;
            carry = sum/10;
        }

        // when curr2 is present
        while(curr2)
        {
            sum = curr2->val+carry;
            tail->next = new ListNode(sum % 10);
            curr2=curr2->next;
            tail = tail->next;
            carry = sum/10;
        }
        //carry left
        while(carry)
        {
            tail->next = new ListNode(carry % 10);
            carry /= 10;
        }


        tail=head;
        head=head->next;
        delete tail;
        return head;


    }
};