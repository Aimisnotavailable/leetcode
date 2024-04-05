#include <vector>
#include <map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::map<int, int> freq;
        int n = nums.size(), i = 0, j = 0, ans = 1;

        while(i < n && j < n){
            freq[nums[j]]++;
            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            ans = std::max(ans,j - i + 1);
            j++;
        }

        return ans;
    }
};