 #include <vector>
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
    bool isPalindrome(ListNode* head) {
        ListNode* t = head;
        std::vector<int> a;

        while(t){
            a.push_back(t->val);
            t = t->next;
        }
        if(a.size() == 1)
            return true;

        int left = 0;
        int right = a.size()-1;

        while(left < right){
            if(a[left] != a[right]){
                a.clear();
                return false;
            }
            left++;
            right--;
        }
        a.clear();
        return true;
    }
};