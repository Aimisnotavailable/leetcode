#include<vector>
#include<algorithm>
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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::vector<int> a;

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                a.push_back(temp->val);
                temp = temp->next;
            }
        }
        std::sort(a.begin(), a.end());
        lists.clear();
        ListNode* b = new ListNode();
        ListNode* c = b;
        for(int i = 0; i < a.size(); i++){
            c->next = new ListNode(a[i]);
            c = c->next;
        }
        return b->next;      
    }
};