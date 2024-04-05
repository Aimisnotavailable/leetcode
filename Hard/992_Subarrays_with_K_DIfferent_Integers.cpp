#include<vector>
#include<unordered_map>
class Solution {
public:
    int sub_arr_with_k_distinct(std::vector<int>& nums, int k){
        std::unordered_map<int, int> a;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;

        while(r < n){
            a[nums[r]]++;
            while(l <= r && a.size() > k){
                a[nums[l]]--;
                if(a[nums[l]] == 0)
                    a.erase(nums[l]);
                l++;
            }
            ans+= (r - l + 1);
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return sub_arr_with_k_distinct(nums, k) - sub_arr_with_k_distinct(nums, k - 1);
    }
};