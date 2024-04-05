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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;
        ListNode* start;
        ListNode* end;
        ListNode* temp = list2;
        int count = 0;

        while(true){
            if(count == a - 1){
                start = current;
            }
            if(count == b){
                end = current->next;
                break;
            }
            current = current->next;
            count++;
        }

        while(temp->next != nullptr){
            temp = temp->next;
        }
        start->next = list2;
        temp->next = end;

        return list1;
    }
};