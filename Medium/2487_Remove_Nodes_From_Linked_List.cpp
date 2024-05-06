#include <stack>

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        std::stack<int> a;
        while(temp){
            int curr = temp->val;
            while(!a.empty() && a.top() < curr){
                a.pop();
            }
            a.push(curr);
            temp = temp->next;
        }
        temp = nullptr;
        while(!a.empty()){
            ListNode* h = new ListNode(a.top());
            h->next = temp;
            temp = h;
            a.pop();
        }

        return temp;
    }
};