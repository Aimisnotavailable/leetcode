#include <vector>
class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int i = 0;
        int n = tickets.size();
        int t = 0;

        while(tickets[k] != 0){
            if(tickets[i] > 0)
                t++;
            tickets[i]--;
            i = (i + 1) % n;            
        }

        return t;
    }
};