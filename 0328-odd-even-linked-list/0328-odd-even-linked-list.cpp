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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        ListNode* oddHead=odd;
        head=head->next->next;

        int cnt=3;
        while(head){
            if(cnt%2==0){
                even->next=head;
                even=even->next;
            }
            else{
                odd->next=head;
                odd=odd->next;
            }

            head=head->next;
            cnt++;
        }

        odd->next=evenHead;
        even->next=NULL;

        return oddHead;
    }
};