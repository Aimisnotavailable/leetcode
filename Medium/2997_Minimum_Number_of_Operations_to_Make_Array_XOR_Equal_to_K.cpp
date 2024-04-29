#include <vector>

class Solution {

public:
    int minOperations(std::vector<int>& nums, int k) {
        int final_xor = 0;

        for(auto n : nums){
            final_xor = final_xor ^ n;
        }

        int count = 0;

        while(k || final_xor){
            if((k % 2) != (final_xor % 2))
                count++;
            k /= 2;
            final_xor /=2;
        }
        return count;
    }
};