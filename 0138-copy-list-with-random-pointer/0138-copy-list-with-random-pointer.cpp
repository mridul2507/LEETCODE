/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

    // STEP 1: insert a copy of each node in between the original nodes
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }

    //  STEP 2:  connect random pointers of the copied nodes
        temp=head;
        while(temp){
            Node* copy=temp->next;
            if(temp->random) copy->random=temp->random->next;
            temp=temp->next->next;
        }

    // STEP 3:retrieve the deep copy of the linked list
        temp=head;
        Node* dummy=new Node(0);
        Node* res=dummy;
        while(temp){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
          
        return dummy->next;
    }
};