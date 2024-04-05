#include <vector>
class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        long long int ans = 0;
        int n = nums.size();
        int minK_i = -1;
        int maxK_i = -1;
        int bad_i = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK) bad_i = i;
            if(nums[i] == maxK) maxK_i = i;
            if(nums[i] == minK) minK_i = i;
            ans += std::max(0,std::min(minK_i, maxK_i) - bad_i);
        }
        return ans;
    }
};