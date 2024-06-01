
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
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* temp = reverse(head);
        ListNode* prev = nullptr;
        ListNode* ans = temp;
        int carry = 0;
        
         while(temp){
            temp->val = temp->val * 2 + carry;
            if(temp->val / 10 > 0){
                carry = 1;
                temp->val %= 10;
                                 }
             else{
                carry = 0;
                };
            prev = temp;
            temp = temp->next;
        }
        if(carry > 0){
            prev->next = new ListNode(carry);
        }
       
        return reverse(ans);
       }
    ListNode* reverse(ListNode* head){
        ListNode* t = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = t;
            t = head;
            head = temp;
        }
            
        return t;
    }
};
