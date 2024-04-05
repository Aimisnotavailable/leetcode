
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* m = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = m;

        while(curr){
            ListNode* tmp= curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
       
        curr = head;

        while(prev){
            ListNode* t = curr->next;
            ListNode* t1 = prev->next;
            curr->next = prev;
            prev->next = t;
            prev = t1;
            curr = curr->next->next;
        }
    }
};