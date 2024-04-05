#include <vector>
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* t = head;
        std::vector<int> a;

        while(t){
            a.push_back(t->val);
            t = t->next;
        }
        
        while(left < right){
            int temp = a[left - 1];
            a[left - 1] = a[right - 1];
            a[right - 1] = temp;
            left++;
            right--;
        }

        t = head;
        
        for(int i = 0; i < a.size(); i++){
            t->val = a[i];
            t = t->next;
        }

        return head;
    }
};