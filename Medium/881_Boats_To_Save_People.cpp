#include<vector>
#include<algorith>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int boat_count = 0;
        while(l <= r){
            if(people[l] + people[r] <= limit)
                l++;
            r--;
            boat_count++;
        }
        return boat_count;
    }
};
