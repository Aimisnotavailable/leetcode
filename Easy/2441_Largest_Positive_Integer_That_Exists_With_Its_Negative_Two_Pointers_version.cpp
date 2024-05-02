class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int max_num = -1;
        std::sort(nums.begin(), nums.end());

        if(nums[left] > 0)
            return -1;
            
        while(left <  right){

            if(std::abs(nums[left]) == nums[right]){
                max_num = std::max(max_num, nums[right]);
                right--;
                left++;
            }
            else if(std::abs(nums[left]) < nums[right]){
                right--;
            }else {
                left++;
            }

        }

        return max_num;
    }
};
