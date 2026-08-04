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

    ListNode* rev(ListNode* t){
        ListNode* prev=NULL;
        ListNode* curr=t;

        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }

        temp=head;
        ListNode* result=new ListNode(0);
        ListNode* res=result;

        while(k<=len){
            ListNode* dummy = new ListNode(0);
            ListNode* dummy2=dummy;
            int count=k;

            while(count){
                dummy2->next=temp;
                dummy2=dummy2->next;
                temp=temp->next;
                count--;
            }

            dummy2->next=NULL;
            
            res->next = rev(dummy->next);
            while(res->next) res=res->next;
            len=len-k;
            delete dummy;
        }

        if(temp) res->next=temp;

        return result->next;
    }
};