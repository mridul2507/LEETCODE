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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        ListNode* res=new ListNode(-1);
        ListNode* dummy=res;

        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp){
                nums.push_back(temp->val);
                temp=temp->next;
            }
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            dummy->next=new ListNode(nums[i]);
            dummy=dummy->next;
        }

        return res->next;
    }
};