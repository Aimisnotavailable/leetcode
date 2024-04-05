#include<vector>
#include<algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(),nums.end()),count = 0;
        long long int left = 0,right = 0,ans = 0;

        while(right < nums.size() || left > right){
            if(nums[right] == max_num)
                count++;
            while(count >= k){
                if(nums[left] == max_num)
                    count--;
                ans += nums.size() - right;
                left++;
            }
            right++;
        }
        return ans;
    }
};